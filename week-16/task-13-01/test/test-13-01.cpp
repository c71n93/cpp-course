#include <cstdint>
#include <vector>

#include "bytes-to-hex.hpp"
#include "gtest/gtest.h"

TEST(BytesToHexTest, EmptyVector) {
    const std::vector<uint8_t> input;
    EXPECT_EQ(bytes_to_hex_string(input), "");
}

TEST(BytesToHexTest, SingleByte) {
    EXPECT_EQ(bytes_to_hex_string({0x00}), "00");
    EXPECT_EQ(bytes_to_hex_string({0xFF}), "FF");
    EXPECT_EQ(bytes_to_hex_string({0x0A}), "0A");
    EXPECT_EQ(bytes_to_hex_string({0xA0}), "A0");
}

TEST(BytesToHexTest, CommonCases) {
    EXPECT_EQ(bytes_to_hex_string({0xBA, 0xAD}), "BAAD");
    EXPECT_EQ(bytes_to_hex_string({0xDE, 0xAD, 0xBE, 0xEF}), "DEADBEEF");
    EXPECT_EQ(bytes_to_hex_string({0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF}),
              "0123456789ABCDEF");
}

TEST(BytesToHexTest, AllPossibleBytes) {
    std::vector<uint8_t> all_bytes(256);
    for (int i = 0; i < 256; ++i) {
        all_bytes[i] = static_cast<uint8_t>(i);
    }
    const std::string result = bytes_to_hex_string(all_bytes);
    ASSERT_EQ(result.size(), 512);  // 256 bytes * 2 chars
    for (int i = 0; i < 256; ++i) {
        const std::string byte_str = result.substr(i * 2, 2);
        const std::string expected = std::string(1, "0123456789ABCDEF"[i >> 4]) +
                                     std::string(1, "0123456789ABCDEF"[i & 0x0F]);
        EXPECT_EQ(byte_str, expected);
    }
}

TEST(BytesToHexTest, CorrectFormatting) {
    const std::vector<uint8_t> input = {0x1, 0x2, 0x03, 0x10, 0xFF};
    const std::string result = bytes_to_hex_string(input);
    EXPECT_EQ(result, "01020310FF");
    EXPECT_TRUE(result.find("01") != std::string::npos);
    EXPECT_TRUE(result.find("02") != std::string::npos);
}

TEST(BytesToHexTest, LargeInput) {
    const std::vector<uint8_t> large_input(10000, 0xAB);
    const std::string result = bytes_to_hex_string(large_input);
    EXPECT_EQ(result.size(), 20000);
    for (size_t i = 0; i < result.size(); i += 2) {
        EXPECT_EQ(result.substr(i, 2), "AB");
    }
}
