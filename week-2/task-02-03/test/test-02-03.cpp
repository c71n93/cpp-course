#include <gtest/gtest.h>

#include "prime_numbers.hpp"

TEST(prime_factors, prime_factors_naive_test_1) {
    uint64_t num = 1;
    std::vector<uint64_t> res{};
    EXPECT_EQ(res, math::prime_factors_naive(num));
}

TEST(prime_factors, prime_factors_test_naive_medium) {
    uint64_t num = 21;
    std::vector<uint64_t> res{3, 7};
    EXPECT_EQ(res, math::prime_factors_naive(num));
}

TEST(prime_factors, prime_factors_naive_test_big) {
    uint64_t num = 364;
    std::vector<uint64_t> res{2, 2, 7, 13};
    EXPECT_EQ(res, math::prime_factors_naive(num));
}

TEST(prime_factors, prime_factors_tests) {
    for (uint64_t i = 0; i < 100000; i++) {
        EXPECT_EQ(math::prime_factors_naive(i), math::prime_factors(i));
    }
}
