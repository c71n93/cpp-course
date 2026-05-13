#include <list>
#include <vector>

#include "gtest/gtest.h"
#include "join.hpp"

using my_algorithm::join;

TEST(JoinTest, HandlesEmptyRange) {
    const std::vector<std::string> empty_vec;
    EXPECT_EQ(join(empty_vec, ","), "");
}

TEST(JoinTest, HandlesSingleString) {
    const std::list<std::string> single = {"hello"};
    EXPECT_EQ(join(single, " "), "hello");
}

TEST(JoinTest, JoinsMultipleStrings) {
    const std::vector<std::string> strings = {"a", "b", "c"};
    EXPECT_EQ(join(strings, ","), "a,b,c");
}

TEST(JoinTest, WorksWithStringView) {
    const std::vector<std::string_view> sv = {"x", "y", "z"};
    EXPECT_EQ(join(sv, "->"), "x->y->z");
}

TEST(JoinTest, HandlesMultiCharDelimiter) {
    const std::vector<std::string> strings = {"1", "2", "3"};
    EXPECT_EQ(join(strings, "###"), "1###2###3");
}

TEST(JoinTest, WorksWithNonOwningTypes) {
    const char* cstrings[] = {"quick", "brown", "fox"};
    EXPECT_EQ(join(cstrings, "..."), "quick...brown...fox");
}
