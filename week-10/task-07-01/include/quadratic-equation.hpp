#pragma once
#include <cmath>
#include <stdexcept>
#include <utility>
#include <variant>

namespace math {

std::variant<std::monostate, double, std::pair<double, double>> quadratic_equation_solution(
    double a, double b, double c) {
    if (a == 0.0) {
        throw std::invalid_argument("Coefficient 'a' should not be 0");
    }
    const double d_squared = b * b - 4 * a * c;
    if (d_squared < 0) {
        return std::variant<std::monostate, double, std::pair<double, double>>{};
    } else if (d_squared == 0) {
        return std::variant<std::monostate, double, std::pair<double, double>>{
            std::in_place_type<double>, -b / (2 * a)};
    } else {
        const double d = std::sqrt(d_squared);
        return std::variant<std::monostate, double, std::pair<double, double>>{
            std::in_place_type<std::pair<double, double>>, (-b - d) / 2 * a, (-b + d) / 2 * a};
    }
}

}  // namespace math
