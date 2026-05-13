#pragma once

#include "ivisitor.hpp"
#include "shape.hpp"

namespace geometry2d {

class Square : public Shape {
public:
    explicit Square(double s) : side_(s) {
        if (side_ <= 0) {
            throw std::invalid_argument("Side must be positive.");
        }
    }

    double side() const { return side_; }

    double perimeter() const override { return 4 * side_; }
    double area() const override { return side_ * side_; }

    void visit_by(const IVisitor& visitor) const override { visitor.visit(*this); }

private:
    double side_;
};

}  // namespace geometry2d
