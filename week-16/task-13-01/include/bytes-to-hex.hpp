#pragma once

#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

std::string bytes_to_hex_string(const std::vector<uint8_t>& bytes) {
    std::ostringstream oss;
    oss << std::hex << std::uppercase << std::setfill('0');
    for (uint8_t const byte : bytes) {
        oss << std::setw(2) << static_cast<int>(byte);
    }
    return oss.str();
}
