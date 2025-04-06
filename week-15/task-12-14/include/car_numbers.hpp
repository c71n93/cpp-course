#pragma once

#include <algorithm>
#include <ranges>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> rus_car_numbers(const std::string& str) {
    const std::regex pattern(R"(\b[ABEKMHOPCTYX]\d{3}[ABEKMHOPCTYX]{2}\b)");
    std::vector<std::string> numbers;
    std::ranges::for_each(std::sregex_iterator(std::cbegin(str), std::cend(str), pattern),
                          std::sregex_iterator(),
                          [&numbers](const auto& matches) { numbers.push_back(matches[0]); });
    return numbers;
}
