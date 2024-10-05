#pragma once

#include <cmath>
#include <numbers>

#include "shape.hpp"

class Ellipse : public Shape {
public:
    Ellipse(double a, double b) : a_(a), b_(b) {}

    double area() const override { return std::numbers::pi * a_ * b_; }
    double perimeter() const override {
        const double sum_ab = a_ + b_;
        return std::numbers::pi * (3 * sum_ab - std::sqrt(3 * sum_ab * sum_ab + 4 * a_ * b_));
    }

    double a() const { return a_; }
    double b() const { return b_; }

private:
    double a_ = 0;
    double b_ = 0;
};
