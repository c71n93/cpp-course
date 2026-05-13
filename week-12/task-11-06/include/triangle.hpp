#pragma once

#include <cmath>

#include "shape.hpp"

namespace geometry2d {

class Triangle : public Shape {
public:
    Triangle(double s1, double s2, double s3) : side1_(s1), side2_(s2), side3_(s3) {
        if (side1_ <= 0 || side2_ <= 0 || side3_ <= 0) {
            throw std::invalid_argument("All sides must be positive.");
        }
        if (side1_ + side2_ <= side3_ || side1_ + side3_ <= side2_ || side2_ + side3_ <= side1_) {
            throw std::invalid_argument("Invalid triangle sides.");
        }
    }

    double side1() const { return side1_; }
    double side2() const { return side2_; }
    double side3() const { return side3_; }

    double perimeter() const override { return side1_ + side2_ + side3_; }
    double area() const override {
        const double p = perimeter() / 2;
        return std::sqrt(p * (p - side1_) * (p - side2_) * (p - side3_));
    }

    void visit_by(const IVisitor& visitor) const override { visitor.visit(*this); }

private:
    double side1_, side2_, side3_;
};

}  // namespace geometry2d
