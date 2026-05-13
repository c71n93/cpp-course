#include <gtest/gtest.h>

#include <list>

#include "smth_of.hpp"

using my_algorithm::all_of;
using my_algorithm::any_of;
using my_algorithm::has_one;
using my_algorithm::none_of;

TEST(HasOne, Array) {
    const std::array<std::string, 5> a{"one", "two", "three", "four", "five"};
    EXPECT_TRUE(has_one(a, "two"));
    EXPECT_FALSE(has_one(a, "six"));
}

TEST(AnyOfAllOfNoneOf, Vector) {
    const std::vector<int> vec = {1, 2, 3, 4, 5};  // NOLINT

    EXPECT_TRUE(any_of(vec, 2, 6));
    EXPECT_FALSE(any_of(vec, 6, 7));

    EXPECT_TRUE(all_of(vec, 1, 2, 3));
    EXPECT_FALSE(all_of(vec, 1, 2, 6));

    EXPECT_TRUE(none_of(vec, 6, 7, 8));
    EXPECT_FALSE(none_of(vec, 1, 6, 7));
}

TEST(AnyOfAllOfNoneOf, Set) {
    const std::set<int> s = {10, 20, 30, 40};  // NOLINT

    EXPECT_TRUE(any_of(s, 20, 50));
    EXPECT_FALSE(any_of(s, 50, 60));

    EXPECT_TRUE(all_of(s, 10, 20));
    EXPECT_FALSE(all_of(s, 10, 50));

    EXPECT_TRUE(none_of(s, 50, 60));
    EXPECT_FALSE(none_of(s, 20, 60));
}

TEST(AnyOfAllOfNoneOf, List) {
    const std::list<int> lst = {5, 10, 15, 20};  // NOLINT

    EXPECT_TRUE(any_of(lst, 10, 25));
    EXPECT_FALSE(any_of(lst, 30, 35));

    EXPECT_TRUE(all_of(lst, 5, 10));
    EXPECT_FALSE(all_of(lst, 5, 30));

    EXPECT_TRUE(none_of(lst, 25, 30));
    EXPECT_FALSE(none_of(lst, 10, 30));
}

TEST(AnyOfAllOfNoneOf, String) {
    const std::string str = "hello";  // NOLINT

    EXPECT_TRUE(any_of(str, 'h', 'x'));
    EXPECT_FALSE(any_of(str, 'x', 'y'));

    EXPECT_TRUE(all_of(str, 'h', 'e'));
    EXPECT_FALSE(all_of(str, 'h', 'z'));

    EXPECT_TRUE(none_of(str, 'x', 'y'));
    EXPECT_FALSE(none_of(str, 'h', 'y'));
}
