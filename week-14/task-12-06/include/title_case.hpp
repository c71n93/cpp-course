#pragma once

#include <algorithm>
#include <iterator>
#include <ranges>
#include <string>

namespace my_algorithms {

void title_case(std::string& str) {
    std::ranges::transform(
        std::views::zip(str, std::views::iota(0)), str.begin(), [&](auto&& pair) {
            auto [c, idx] = pair;
            return (idx == 0 || std::isspace(str[idx - 1])) ? std::toupper(c) : std::tolower(c);
        });
}

}  // namespace my_algorithms
