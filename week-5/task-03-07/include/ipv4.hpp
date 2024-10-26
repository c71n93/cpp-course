#pragma once

#include <array>
#include <iostream>
#include <ranges>

namespace ipv4 {

class IPv4 {
public:
    IPv4() : address_{0, 0, 0, 0} {}

    IPv4(uint8_t a, uint8_t b, uint8_t c, uint8_t d) : address_{a, b, c, d} {}

    friend std::istream& operator>>(std::istream& is, IPv4& ip) {
        char dot;
        std::array<int, 4> raw;
        constexpr int max = std::numeric_limits<uint8_t>::max();
        for (size_t i = 0; i < raw.size(); ++i) {
            if (i == raw.size() - 1) {
                if (is >> raw[i] && is_between_included(raw[i], 0, max)) {
                    ip.address_[i] = static_cast<uint8_t>(raw[i]);
                } else {
                    is.setstate(std::ios::failbit);
                }
            } else {
                if (is >> raw[i] >> dot && dot == '.' && is_between_included(raw[i], 0, max)) {
                    ip.address_[i] = static_cast<uint8_t>(raw[i]);
                } else {
                    is.setstate(std::ios::failbit);
                }
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const IPv4& ip) {
        os << static_cast<int>(ip.address_[0]) << '.' << static_cast<int>(ip.address_[1]) << '.'
           << static_cast<int>(ip.address_[2]) << '.' << static_cast<int>(ip.address_[3]);
        return os;
    }

private:
    template <std::integral Int>
    static bool is_between_included(Int value, Int a, Int b) {
        return value >= a && value <= b;
    }

    std::array<uint8_t, 4> address_;
};

}  // namespace ipv4
