#pragma once

#include "polygon.hpp"

class Triangle : public Polygon {
public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    double area() const override {
        const double sp = perimeter() / 2;
        return std::sqrt(sp * (sp - a_) * (sp - b_) * (sp - c_));
    }
    double perimeter() const override { return a_ + b_ + c_; }
    size_t num_of_sides() const override { return 3; }

    double a() const { return a_; }
    double b() const { return b_; }
    double c() const { return c_; }

private:
    double a_ = 0;
    double b_ = 0;
    double c_ = 0;
};
