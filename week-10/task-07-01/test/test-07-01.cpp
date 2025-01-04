#include "gtest/gtest.h"
#include "quadratic-equation.hpp"

using math::quadratic_equation_solution;

TEST(QuadraticEquationSolutionTest, NoSolutions) {
    auto result = quadratic_equation_solution(1.0, 0.0, 1.0);
    ASSERT_TRUE(std::holds_alternative<std::monostate>(result));
}

TEST(QuadraticEquationSolutionTest, OneSolution) {
    auto result = quadratic_equation_solution(1.0, -2.0, 1.0);  // NOLINT
    ASSERT_TRUE(std::holds_alternative<double>(result));
    const double solution = std::get<double>(result);
    EXPECT_DOUBLE_EQ(solution, 1.0);
}

TEST(QuadraticEquationSolutionTest, OneSolution2) {
    auto result = quadratic_equation_solution(1.0, -4.0, 4.0);  // NOLINT
    ASSERT_TRUE(std::holds_alternative<double>(result));
    const double solution = std::get<double>(result);
    EXPECT_DOUBLE_EQ(solution, 2.0);
}

TEST(QuadraticEquationSolutionTest, TwoSolutionsDistinct) {
    auto result = quadratic_equation_solution(1.0, -3.0, 2.0);  // NOLINT
    ASSERT_TRUE((std::holds_alternative<std::pair<double, double>>(result)));
    auto solutions = std::get<std::pair<double, double>>(result);

    EXPECT_DOUBLE_EQ(solutions.first, 1.0);
    EXPECT_DOUBLE_EQ(solutions.second, 2.0);
}

TEST(QuadraticEquationSolutionTest, LinearEquation) {
    EXPECT_THROW(quadratic_equation_solution(0.0, 2.0, -4.0);, std::invalid_argument);  // NOLINT
}

TEST(QuadraticEquationSolutionTest, ZeroCoefficientCase) {
    EXPECT_THROW(quadratic_equation_solution(0.0, 0.0, 1.0);, std::invalid_argument);
}

TEST(QuadraticEquationSolutionTest, AllZeroCoefficients) {
    EXPECT_THROW(quadratic_equation_solution(0.0, 0.0, 0.0);, std::invalid_argument);
}
