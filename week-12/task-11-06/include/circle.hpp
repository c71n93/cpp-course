#pragma once

#include <numbers>

#include "ivisitor.hpp"
#include "shape.hpp"

namespace geometry2d {

class Circle : public Shape {
public:
    static constexpr double pi = std::numbers::pi;

    explicit Circle(double r) : radius_(r) {
        if (radius_ <= 0) {
            throw std::invalid_argument("Radius must be positive.");
        }
    }

    double radius() const { return radius_; }

    double perimeter() const override { return 2 * pi * radius_; }
    double area() const override { return pi * radius_ * radius_; }

    void visit_by(const IVisitor& visitor) const override { visitor.visit(*this); }

private:
    double radius_;
};

}  // namespace geometry2d
