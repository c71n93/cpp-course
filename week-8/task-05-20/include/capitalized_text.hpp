#pragma once

#include <algorithm>
#include <memory>

#include "text.hpp"

namespace text {

/**
 * Decorated text with all letters capitalized.
 */
template <Text Txt>
class CapitalizedText {  // no virtual functions, so we don't need inheritance. we have a concept.
public:
    explicit CapitalizedText(Txt&& text) : origin_(std::forward<Txt>(text)) {}
    explicit CapitalizedText(const Txt& text) : origin_(text) {}

    std::string content() const {
        std::string text = origin_.content();
        std::ranges::transform(text, text.begin(), [](unsigned char c) { return std::toupper(c); });
        return text;
    }

private:
    Txt origin_;
};

}  // namespace text
