#include "gtest/gtest.h"
#include "pi.hpp"

TEST(PiTest, PiTest) { EXPECT_NEAR(pi(1000000), 3.14, 0.01); }
