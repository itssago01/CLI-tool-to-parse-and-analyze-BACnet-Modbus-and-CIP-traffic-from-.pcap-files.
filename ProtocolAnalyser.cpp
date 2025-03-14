#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using json = nlohmann::json;

class ProtocolAnalyzer {
public:
    ProtocolAnalyzer(const std::string& filePath) : pcapFile(filePath) {}

    void analyze() {
        if (!fs::exists(pcapFile)) {
            std::cerr << "Error: File does not exist.\n";
            return;
        }

        std::string tsharkCmd = "tshark -r " + pcapFile +
            " -T json -Y \"bacnet || modbus || cip\" > output.json";
        
        int result = std::system(tsharkCmd.c_str());
        if (result != 0) {
            std::cerr << "Error running Tshark.\n";
            return;
        }

        parseOutput();
    }

private:
    std::string pcapFile;

    void parseOutput() {
        std::ifstream file("output.json");
        if (!file) {
            std::cerr << "Error reading Tshark output.\n";
            return;
        }

        json packetData;
        file >> packetData;

        for (const auto& packet : packetData) {
            if (packet.contains("_source")) {
                json source = packet["_source"];
                if (source.contains("layers")) {
                    json layers = source["layers"];
                    std::cout << "Decoded Message:\n";
                    if (layers.contains("bacnet")) {
                        std::cout << "BACnet: " << layers["bacnet"] << "\n";
                    }
                    if (layers.contains("modbus")) {
                        std::cout << "Modbus: " << layers["modbus"] << "\n";
                    }
                    if (layers.contains("cip")) {
                        std::cout << "CIP: " << layers["cip"] << "\n";
                    }
                    std::cout << "---------------------\n";
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <pcap_file>\n";
        return 1;
    }

    ProtocolAnalyzer analyzer(argv[1]);
    analyzer.analyze();
    return 0;
}
