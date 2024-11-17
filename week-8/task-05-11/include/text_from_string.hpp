#pragma once

#include <string>

#include "text.hpp"

namespace text {

/**
 * Dummy concrete text. It was created for testing.
 */
class TextFromString : public Text {
public:
    explicit TextFromString(const std::string& content) : content_(content) {}

    std::string content() const override { return content_; }

private:
    std::string content_;
};

}  // namespace text
