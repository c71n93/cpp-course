#include "gtest/gtest.h"
#include "title_case.hpp"

using my_algorithms::title_case;

TEST(TitleCaseTest, HandlesEmptyString) {
    std::string str;
    title_case(str);
    EXPECT_EQ(str, "");
}

TEST(TitleCaseTest, HandlesSingleWord) {
    std::string str = "hello";
    title_case(str);
    EXPECT_EQ(str, "Hello");
}

TEST(TitleCaseTest, HandlesMultipleWords) {
    std::string str = "heLLo, woRLD";
    title_case(str);
    EXPECT_EQ(str, "Hello, World");
}

TEST(TitleCaseTest, HandlesLeadingAndTrailingSpaces) {
    std::string str = "  test  CASE  ";
    title_case(str);
    EXPECT_EQ(str, "  Test  Case  ");
}

TEST(TitleCaseTest, HandlesMixedCaseWithNumbers) {
    std::string str = "1st plaCE";
    title_case(str);
    EXPECT_EQ(str, "1st Place");
}

TEST(TitleCaseTest, HandlesAllUppercase) {
    std::string str = "ALL UPPER";
    title_case(str);
    EXPECT_EQ(str, "All Upper");
}
