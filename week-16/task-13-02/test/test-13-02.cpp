#include "gtest/gtest.h"
#include "pascal-triangle.hpp"

class PascalsTriangleTest : public ::testing::Test {
protected:
    static std::string captureOutput(int rows) {
        std::stringstream ss;
        PascalsTriangle triangle(rows);
        triangle.print(ss);
        return ss.str();
    }
};

TEST_F(PascalsTriangleTest, HandlesZeroRows) {
    PascalsTriangle triangle(0);
    std::stringstream ss;
    triangle.print(ss);
    EXPECT_TRUE(ss.str().empty());
}

TEST_F(PascalsTriangleTest, HandlesSingleRow) {
    auto output = captureOutput(1);
    EXPECT_EQ(output, "1 \n");
}

TEST_F(PascalsTriangleTest, HandlesMultipleRows) {
    auto output = captureOutput(3);
    const std::string expected =
        "  1 \n"
        " 1 1 \n"
        "1 2 1 \n";
    EXPECT_EQ(output, expected);
}

TEST_F(PascalsTriangleTest, OutputFormatting) {
    auto output = captureOutput(5);  // NOLINT
    const std::string expected =
        "    1 \n"
        "   1 1 \n"
        "  1 2 1 \n"
        " 1 3 3 1 \n"
        "1 4 6 4 1 \n";
    EXPECT_EQ(output, expected);
}

TEST_F(PascalsTriangleTest, JustPrintATriangle) { PascalsTriangle(10).print(std::cout); }
