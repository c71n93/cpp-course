#include <sstream>

#include "gtest/gtest.h"
#include "ipv4.hpp"

using ipv4::IPv4;

TEST(IPv4Test, OutputStream) {
    const IPv4 ip(192, 168, 0, 1);
    std::stringstream ss;
    ss << ip;
    EXPECT_EQ(ss.str(), "192.168.0.1");
}

TEST(IPv4Test, InputStreamValidInput) {
    IPv4 ip;
    std::stringstream ss("192.168.0.1");
    ss >> ip;

    std::stringstream output;
    output << ip;

    EXPECT_EQ(output.str(), "192.168.0.1");
    EXPECT_FALSE(ss.fail());
}

TEST(IPv4Test, InputStreamInvalidFormat) {
    IPv4 ip;
    std::stringstream ss("192.168.0");
    ss >> ip;

    EXPECT_TRUE(ss.fail());
}

TEST(IPv4Test, InputStreamInvalidValuesBig) {
    IPv4 ip;
    std::stringstream ss("300.168.0.1");
    ss >> ip;

    EXPECT_TRUE(ss.fail());
}

TEST(IPv4Test, InputStreamInvalidValuesNegative) {
    IPv4 ip;
    std::stringstream ss("192.168.0.-1");
    ss >> ip;

    EXPECT_TRUE(ss.fail());
}

TEST(IPv4Test, InputStreamBorderValues) {
    IPv4 ip;
    std::stringstream ss("0.0.0.0");
    ss >> ip;

    std::stringstream output;
    output << ip;

    EXPECT_EQ(output.str(), "0.0.0.0");
    EXPECT_FALSE(ss.fail());

    ss.clear();
    ss.str("255.255.255.255");
    ss >> ip;

    output.str("");
    output << ip;

    EXPECT_EQ(output.str(), "255.255.255.255");
    EXPECT_FALSE(ss.fail());
}
