#include "gtest/gtest.h"
#include "calculator.hpp"

TEST(RPNCalculatorTest, BasicOperations) {
    EXPECT_EQ(calculate("3 4 +"), 7);      // 3 + 4
    EXPECT_EQ(calculate("5 2 -"), 3);      // 5 - 2
    EXPECT_EQ(calculate("2 3 *"), 6);      // 2 * 3
    EXPECT_EQ(calculate("6 2 /"), 3);      // 6 / 2
}

TEST(RPNCalculatorTest, ComplexExpressions) {
    EXPECT_EQ(calculate("3 4 2 * +"), 11);     // 3 + (4 * 2)
    EXPECT_EQ(calculate("5 1 2 + 4 * + 3 -"), 14); // 5 + ((1+2)*4) - 3
    EXPECT_EQ(calculate("4 2 5 * + 1 3 - /"), -7); // (4 + 2*5) / (1-3)
}

TEST(RPNCalculatorTest, EdgeCases) {
    EXPECT_EQ(calculate("0 5 +"), 5);       // 0 + 5
    EXPECT_EQ(calculate("1 1 -"), 0);       // 1 - 1
    EXPECT_EQ(calculate("999 1 +"), 1000);  // large number
    EXPECT_EQ(calculate("-5 3 +"), -2);     // negative number
}

TEST(RPNCalculatorTest, InvalidInput) {
    EXPECT_THROW(calculate(""), std::invalid_argument);      // empty
    EXPECT_THROW(calculate("3 +"), std::invalid_argument);   // missing operand
    EXPECT_THROW(calculate("3 4 + -"), std::invalid_argument); // extra operator
    EXPECT_THROW(calculate("a b +"), std::invalid_argument); // non-numbers
    EXPECT_THROW(calculate("3 0 /"), std::runtime_error);    // division by zero
}

TEST(RPNCalculatorTest, WhitespaceHandling) {
    EXPECT_EQ(calculate("  3   4  +  "), 7);  // extra spaces
    EXPECT_EQ(calculate("3\n4\t+"), 7);       // different whitespace
    EXPECT_EQ(calculate("3 4 + "), 7);        // trailing space
}

TEST(RPNCalculatorTest, MultiDigitNumbers) {
    EXPECT_EQ(calculate("10 20 +"), 30);      // 10 + 20
    EXPECT_EQ(calculate("100 50 -"), 50);     // 100 - 50
    EXPECT_EQ(calculate("12 34 *"), 408);     // 12 * 34
    EXPECT_EQ(calculate("100 5 /"), 20);      // 100 / 5
}
