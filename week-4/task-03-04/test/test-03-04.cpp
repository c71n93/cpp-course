#include <gtest/gtest.h>

#include "ambiguous.hpp"

TEST(Ambiguous, AmbiguousTest) {
    Derived d{};
    Base1& b1 = d;
    Base2& b2 = d;
    EXPECT_EQ(b1.foo(), 2);
    EXPECT_EQ(b2.foo(), 6);
}
