#include <gtest/gtest.h>

#include "prime_numbers.hpp"

TEST(prime_factors, prime_factors_test_1) {
    std::uint64_t num = 1;
    std::vector<std::uint64_t> res{};
    EXPECT_EQ(res, math::prime_factors(num));
}

TEST(prime_factors, prime_factors_test_medium) {
    std::uint64_t num = 21;
    std::vector<std::uint64_t> res{3, 7};
    EXPECT_EQ(res, math::prime_factors(num));
}

TEST(prime_factors, prime_factors_test_big) {
    std::uint64_t num = 364;
    std::vector<std::uint64_t> res{2, 2, 7, 13};
    EXPECT_EQ(res, math::prime_factors(num));
}
