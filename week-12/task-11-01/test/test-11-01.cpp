#include "gtest/gtest.h"
#include "self-pointed-function.hpp"

using functions::FunctionPtr;
using functions::intermediary;

TEST(SelfPointedFunction, Call) {
    FunctionPtr f = intermediary();
    constexpr int x = 10;
    EXPECT_EQ(f(x), x);
}
