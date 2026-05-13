#pragma once

#include <unordered_set>

namespace my_algorithm {

std::vector<std::string> tokenize(const std::string& str,
                                  const std::unordered_set<char>& delimiters) {
    std::vector<std::string> tokens;
    auto start = str.begin();
    auto end = str.end();
    while (start != end) {
        while (start != end && delimiters.contains(*start)) {
            ++start;
        }
        auto token_end = start;
        while (token_end != end && !delimiters.contains(*token_end)) {
            ++token_end;
        }
        if (start != token_end) {
            tokens.emplace_back(start, token_end);
        }
        start = token_end;
    }
    return tokens;
}

}  // namespace my_algorithm
