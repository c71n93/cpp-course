#include <gtest/gtest.h>

#include "prime-nums.hpp"

TEST(PrimeFactors, PrimeFactorsNaiveTest1) {
    const uint64_t num = 1;
    const std::vector<uint64_t> res{};
    EXPECT_EQ(res, math::prime_factors_naive(num));
}

TEST(PrimeFactors, PrimeFactorsNaiveTestMedium) {
    const uint64_t num = 21;
    const std::vector<uint64_t> res{3, 7};
    EXPECT_EQ(res, math::prime_factors_naive(num));
}

TEST(PrimeFactors, PrimeFactorsNaiveTestBig) {
    const uint64_t num = 364;
    const std::vector<uint64_t> res{2, 2, 7, 13};
    EXPECT_EQ(res, math::prime_factors_naive(num));
}

TEST(PrimeFactors, PrimeFactorsTest) {
    const uint64_t iters = 100000;
    for (uint64_t i = 0; i < iters; i++) {
        EXPECT_EQ(math::prime_factors_naive(i), math::prime_factors(i));
    }
}
