#pragma once

#include <cassert>
#include <iostream>
#include <source_location>

#include "noncopyable.hpp"

namespace logger {

class Logger : share::util::NonCopyable {
public:
    explicit Logger(const std::source_location location = std::source_location::current())
        : loc_(location) {
        for (int i = 0; i < nesting; ++i) {
            std::cout << "  ";
        }
        std::cout << "\033[1;34m[Logger]\033[0m Begin  function " << loc_.function_name()
                  << std::endl;
        ++nesting;
    }

    ~Logger() {
        --nesting;
        assert(nesting >= 0);
        for (int i = 0; i < nesting; ++i) {
            std::cout << "  ";
        }
        std::cout << "\033[1;33m[Logger]\033[0m End of function " << loc_.function_name()
                  << std::endl;
    }

private:
    std::source_location loc_;

    static int nesting;
};

int Logger::nesting = 0;

}  // namespace logger