# C++ Industrial Protocol Analyzer

A CLI tool for parsing and analyzing industrial protocol traffic (BACnet, Modbus, and CIP) from `.pcap` files. This tool leverages Wireshark’s `tshark` to dissect network packets and outputs decoded messages in a structured format.

## Features

- **Reads Packet Captures:** Processes `.pcap` files.
- **Protocol Dissection:** Extracts and decodes BACnet, Modbus, and CIP messages using `tshark`.
- **Structured Output:** Displays decoded messages in a clear, structured format.
- **Cross-Platform:** Utilizes C++17 features such as `std::filesystem` for modern file handling.

## Tech Stack

- **Language:** C++ (requires C++17 or higher)
- **Dissector:** [Wireshark’s tshark](https://www.wireshark.org/)
- **JSON Parsing:** [nlohmann/json](https://github.com/nlohmann/json) (header-only library)
- **Optional:** Protocol Buffers (for future extensions)

## Prerequisites

- **Wireshark / tshark:**
  - **Linux:** `sudo apt install tshark`
  - **macOS:** `brew install wireshark`
  - **Windows:** Download from [Wireshark’s website](https://www.wireshark.org/download.html)
- **C++ Compiler:** Ensure you have a compiler that supports C++17 (e.g., g++, clang++).
- **nlohmann/json:** 
  - Install via a package manager or add the header directly from the [GitHub repository](https://github.com/nlohmann/json).

## Installation

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/yourusername/cpp-industrial-protocol-analyzer.git
   cd cpp-industrial-protocol-analyzer
