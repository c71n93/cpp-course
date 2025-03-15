#pragma once

namespace share::util {

class NonCopyable {
protected:
    NonCopyable() = default;

public:
    NonCopyable(const NonCopyable& other) = delete;
    NonCopyable& operator=(const NonCopyable& other) = delete;
};

}  // namespace share::util
