#include "gtest/gtest.h"
#include "self-pointed-function.hpp"

using functions::do_it;

TEST(SelfPointedFunction, Call) {
    constexpr int initial = 42;
    int var = initial;  // NOLINT
    auto do_it_again = do_it(var);
    EXPECT_EQ(var, initial + 1);
    do_it_again(var);
    EXPECT_EQ(var, initial + 2);
}
