#include <gtest/gtest.h>

#include <array>
#include <iterator>
#include <list>

#include "find.hpp"

TEST(FindFunctionTests, ElementPresentInArray) {
    constexpr std::array<int, 5> data = {1, 3, 5, 7, 9};
    auto it = my_algorithms::find(data.begin(), data.end(), 5);  // NOLINT
    ASSERT_NE(it, data.end());
    EXPECT_EQ(*it, 5);
}

TEST(FindFunctionTests, ElementNotPresentInArray) {
    constexpr std::array<int, 5> data = {1, 3, 5, 7, 9};
    auto it = my_algorithms::find(data.begin(), data.end(), 4);
    EXPECT_EQ(it, data.end());
}

TEST(FindFunctionTests, ElementPresentInList) {
    std::list<int> data = {10, 20, 30, 40};                       // NOLINT
    auto it = my_algorithms::find(data.begin(), data.end(), 30);  // NOLINT
    ASSERT_NE(it, data.end());
    EXPECT_EQ(*it, 30);
}

TEST(FindFunctionTests, ElementNotPresentInList) {
    std::list<int> data = {10, 20, 30, 40};                       // NOLINT
    auto it = my_algorithms::find(data.begin(), data.end(), 25);  // NOLINT
    EXPECT_EQ(it, data.end());
}

TEST(FindFunctionTests, EmptyContainer) {
    constexpr std::array<int, 0> data;
    auto it = my_algorithms::find(data.begin(), data.end(), 10);  // NOLINT
    EXPECT_EQ(it, data.end());
}

TEST(FindFunctionTests, SingleElementFound) {
    constexpr std::array<int, 1> data = {42};
    auto it = my_algorithms::find(data.begin(), data.end(), 42);  // NOLINT
    ASSERT_NE(it, data.end());
    EXPECT_EQ(*it, 42);
}

TEST(FindFunctionTests, SingleElementNotFound) {
    constexpr std::array<int, 1> data = {42};
    auto it = my_algorithms::find(data.begin(), data.end(), 99);  // NOLINT
    EXPECT_EQ(it, data.end());
}
