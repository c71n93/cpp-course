#include <gtest/gtest.h>

#include <source_location>

#include "logger.hpp"

using logger::Logger;

void foo() { const Logger logger{}; }

void bar() {
    const Logger logger{};
    foo();
}

TEST(Logger, logs) {
    const Logger log{};
    bar();
}
