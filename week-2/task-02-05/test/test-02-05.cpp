#include <gtest/gtest.h>

#include <numbers>

#include "eulers-num.hpp"

TEST(eulers_number, eulers_number_test) {
    for (double eps = 1.0; eps > 10e-16; eps /= 10) {
        EXPECT_NEAR(std::numbers::e, math::eulers_number(eps), eps);
    }
}
