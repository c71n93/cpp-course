#include <numbers>

#include "eulers-num.hpp"
#include "gtest/gtest.h"

constexpr size_t n_tests = 16;
constexpr std::array<double, n_tests> create_test_sample() {
    std::array<double, n_tests> sample{};
    double eps = 1.0;
    for (size_t i = 0; i < n_tests; eps /= 10, i++) {  // NOLINT
        sample[i] = math::eulers_number(eps);
    }
    return sample;
}

TEST(EulersNumber, EulersNumberTest) {
    constexpr std::array<double, n_tests> sample = create_test_sample();
    double eps = 1.0;
    for (size_t i = 0; i < n_tests; eps /= 10, i++) {  // NOLINT
        EXPECT_NEAR(std::numbers::e, sample[i], eps);
    }
}
