#include "calculator.hpp"
#include "gtest/gtest.h"

TEST(RPNCalculatorTest, BasicOperations) {
    EXPECT_DOUBLE_EQ(calculate("3 4 +"), 7.0);
    EXPECT_DOUBLE_EQ(calculate("5 2 -"), 3.0);
    EXPECT_DOUBLE_EQ(calculate("2 3 *"), 6.0);
    EXPECT_DOUBLE_EQ(calculate("6 2 /"), 3.0);
}

TEST(RPNCalculatorTest, FloatingPointOperations) {
    EXPECT_DOUBLE_EQ(calculate("3.5 4.2 +"), 7.7);
    EXPECT_DOUBLE_EQ(calculate("5.1 2.3 -"), 2.8);
    EXPECT_DOUBLE_EQ(calculate("2.5 3.2 *"), 8.0);
    EXPECT_DOUBLE_EQ(calculate("7.5 2.5 /"), 3.0);
}

TEST(RPNCalculatorTest, ComplexExpressions) {
    EXPECT_DOUBLE_EQ(calculate("3 4 2 * +"), 11.0);
    EXPECT_DOUBLE_EQ(calculate("5 1 2 + 4 * + 3 -"), 14.0);
    EXPECT_DOUBLE_EQ(calculate("4 2 5 * + 1 3 - /"), -7.0);
}

TEST(RPNCalculatorTest, EdgeCases) {
    EXPECT_DOUBLE_EQ(calculate("0 5 +"), 5.0);
    EXPECT_DOUBLE_EQ(calculate("1 1 -"), 0.0);
    EXPECT_DOUBLE_EQ(calculate("999 1 +"), 1000.0);
    EXPECT_DOUBLE_EQ(calculate("-5 3 +"), -2.0);
}

TEST(RPNCalculatorTest, InvalidInput) {
    EXPECT_THROW(calculate(""), std::invalid_argument);
    EXPECT_THROW(calculate("3 +"), std::invalid_argument);
    EXPECT_THROW(calculate("3 4 + -"), std::invalid_argument);
    EXPECT_THROW(calculate("a b +"), std::invalid_argument);
}

TEST(RPNCalculatorTest, WhitespaceHandling) {
    EXPECT_DOUBLE_EQ(calculate("  3   4  +  "), 7.0);
    EXPECT_DOUBLE_EQ(calculate("3\n4\t+"), 7.0);
    EXPECT_DOUBLE_EQ(calculate("3 4 + "), 7.0);
}

TEST(RPNCalculatorTest, MultiDigitNumbers) {
    EXPECT_DOUBLE_EQ(calculate("10 20 +"), 30.0);
    EXPECT_DOUBLE_EQ(calculate("100 50 -"), 50.0);
    EXPECT_DOUBLE_EQ(calculate("12 34 *"), 408.0);
    EXPECT_DOUBLE_EQ(calculate("100 5 /"), 20.0);
}

TEST(RPNCalculatorTest, PrecisionHandling) {
    EXPECT_DOUBLE_EQ(calculate("0.1 0.2 +"), 0.3);
    EXPECT_DOUBLE_EQ(calculate("1.234 2.345 +"), 3.579);
    EXPECT_NEAR(calculate("1.0 3.0 /"), 0.333333, 1e-6);
    EXPECT_NEAR(calculate("2.0 3.0 /"), 0.666666, 1e-6);
}

TEST(RPNCalculatorTest, MixedIntegerAndFloatingPoint) {
    EXPECT_DOUBLE_EQ(calculate("3 4.5 +"), 7.5);
    EXPECT_DOUBLE_EQ(calculate("5.2 2 -"), 3.2);
    EXPECT_DOUBLE_EQ(calculate("2 3.5 *"), 7.0);
    EXPECT_DOUBLE_EQ(calculate("6.6 2.2 /"), 3.0);
}
