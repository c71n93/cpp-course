#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>

#include "algorithms.hpp"

TEST(Reverse, ReverseEmptyTest) {
    std::vector<int> vec_ref(0);
    std::vector<int> vec_check = vec_ref;
    std::ranges::reverse(vec_ref);
    my_algorithms::reverse(vec_check);
    EXPECT_EQ(vec_ref, vec_check);
}

TEST(Reverse, ReverseSingleTest) {
    std::vector<int> vec_ref(1);
    std::iota(vec_ref.begin(), vec_ref.end(), 0);
    std::vector<int> vec_check = vec_ref;
    std::ranges::reverse(vec_ref);
    my_algorithms::reverse(vec_check);
    EXPECT_EQ(vec_ref, vec_check);
}

TEST(Reverse, ReverseTest) {
    constexpr size_t sz = 100;
    std::vector<int> vec_ref(sz);
    std::iota(vec_ref.begin(), vec_ref.end(), 0);
    std::vector<int> vec_check = vec_ref;
    std::ranges::reverse(vec_ref);
    my_algorithms::reverse(vec_check);
    EXPECT_EQ(vec_ref, vec_check);
}
