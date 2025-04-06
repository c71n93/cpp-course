#pragma once

#include <algorithm>
#include <ranges>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> emails(const std::string& str) {
    const std::regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{1,}\b)");
    std::vector<std::string> emails;
    std::ranges::for_each(std::sregex_iterator(std::cbegin(str), std::cend(str), pattern),
                          std::sregex_iterator(),
                          [&emails](const auto& matches) { emails.push_back(matches[0]); });
    return emails;
}
