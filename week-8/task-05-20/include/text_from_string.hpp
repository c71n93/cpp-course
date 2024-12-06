#pragma once

#include <string>

#include "text.hpp"

namespace text {

/**
 * Dummy concrete text. It was created for testing.
 */
class TextFromString {
public:
    explicit TextFromString(const std::string& content) : content_(content) {}

    std::string content() const { return content_; }

private:
    std::string content_;
};

}  // namespace text
