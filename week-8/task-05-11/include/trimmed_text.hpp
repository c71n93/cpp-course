#pragma once

#include <algorithm>
#include <memory>
#include <ranges>

#include "text.hpp"

namespace text {

/**
 * Decorated text with the space characters removed at the beginning and at the end.
 */
class TrimmedText : public Text {
public:
    template <typename T>
        requires std::derived_from<T, Text>
    explicit TrimmedText(const T& text) : TrimmedText(std::make_unique<T>(text)) {}
    template <typename T>
        requires std::derived_from<T, Text>
    explicit TrimmedText(T&& text) : TrimmedText(std::make_unique<T>(std::forward<T>(text))) {}
    explicit TrimmedText(std::unique_ptr<Text> text) : origin_(std::move(text)) {}

    std::string content() const override {
        std::string content = origin_->content();
        auto start = std::find_if_not(content.begin(), content.end(),
                                      [](unsigned char ch) { return std::isspace(ch); });
        auto end = std::find_if_not(content.rbegin(), content.rend(), [](unsigned char ch) {
                       return std::isspace(ch);
                   }).base();
        return (start < end) ? std::string(start, end) : std::string();
    }

private:
    std::unique_ptr<Text> origin_;
};

}  // namespace text
