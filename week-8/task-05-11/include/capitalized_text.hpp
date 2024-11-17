#pragma once

#include <algorithm>
#include <memory>

#include "text.hpp"

namespace text {

/**
 * Decorated text with all letters capitalized.
 */
class CapitalizedText : public Text {
public:
    template <typename T>
        requires std::derived_from<T, Text>
    explicit CapitalizedText(const T& text) : CapitalizedText(std::make_unique<T>(text)) {}
    template <typename T>
        requires std::derived_from<T, Text>
    explicit CapitalizedText(T&& text)
        : CapitalizedText(std::make_unique<T>(std::forward<T>(text))) {}
    explicit CapitalizedText(std::unique_ptr<Text> text) : origin_(std::move(text)) {}

    std::string content() const override {
        std::string text = origin_->content();
        std::ranges::transform(text, text.begin(), [](unsigned char c) { return std::toupper(c); });
        return text;
    }

private:
    std::unique_ptr<Text> origin_;
};

}  // namespace text
