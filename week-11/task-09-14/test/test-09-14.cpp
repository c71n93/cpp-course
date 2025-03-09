#include "gtest/gtest.h"
#include "odd-iterator.hpp"

using iter::OddIterator;

TEST(OddIterator, Increment) {
    OddIterator it(1);
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 5);
}

TEST(OddIterator, PostIncrement) {
    OddIterator it(1);
    EXPECT_EQ(*it, 1);
    const auto prev = it++;
    EXPECT_EQ(*prev, 1);
    EXPECT_EQ(*it, 3);
}

TEST(OddIterator, Equality) {
    const OddIterator it1(1);
    const OddIterator it2(1);
    const OddIterator it3(3);

    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 == it3);
    EXPECT_FALSE(it2 == it3);
}

TEST(OddIterator, Inequality) {
    OddIterator it1(1);
    const OddIterator it2(3);

    EXPECT_TRUE(it1 != it2);
    ++it1;
    EXPECT_FALSE(it1 != it2);
}

TEST(OddIterator, RangeBasedFor) {
    const OddIterator begin(1);
    const OddIterator end(11);

    const std::vector<int> expected = {1, 3, 5, 7, 9};
    std::vector<int> result;

    for (auto it = begin; it != end; ++it) {
        result.push_back(*it);
    }

    EXPECT_EQ(result, expected);
}

TEST(OddIterator, Dereference) {
    OddIterator it(5);  // NOLINT
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 7);
}