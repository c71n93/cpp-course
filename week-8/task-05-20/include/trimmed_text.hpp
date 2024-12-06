#pragma once

#include <algorithm>
#include <memory>
#include <ranges>

#include "text.hpp"

namespace text {

/**
 * Decorated text with the space characters removed at the beginning and at the end.
 */
template <Text Txt>
class TrimmedText {  // no virtual functions, so we don't need inheritance. we have a Text concept.
public:
    explicit TrimmedText(Txt&& text) : origin_(std::forward<Txt>(text)) {}
    explicit TrimmedText(const Txt& text) : origin_(text) {}

    std::string content() const {
        std::string content = origin_.content();
        auto start = std::find_if_not(content.begin(), content.end(),
                                      [](unsigned char ch) { return std::isspace(ch); });
        auto end = std::find_if_not(content.rbegin(), content.rend(), [](unsigned char ch) {
                       return std::isspace(ch);
                   }).base();
        return (start < end) ? std::string(start, end) : std::string();
    }

private:
    Txt origin_;
};

}  // namespace text
