#include <gtest/gtest.h>

#include <numbers>

#include "eulers-num.hpp"

TEST(EulersNumber, EulersNumberTest) {
    for (double eps = 1.0; eps > 10e-16; eps /= 10) {  // NOLINT
        EXPECT_NEAR(std::numbers::e, math::eulers_number(eps), eps);
    }
}
