#pragma once

#include "ellipse.hpp"

class Circle : public Ellipse {
public:
    explicit Circle(double r) : Ellipse(r, r) {}

    double perimeter() const override { return 2 * std::numbers::pi * radius(); }

    double radius() const { return Ellipse::a(); }
};
