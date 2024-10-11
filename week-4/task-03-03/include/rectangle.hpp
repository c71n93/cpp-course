#pragma once

#include "polygon.hpp"

class Rectangle : public Polygon {
public:
    Rectangle(double height, double width) : height_(height), width_(width) {}

    double area() const override { return height_ * width_; }
    double perimeter() const override { return height_ * 2 + width_ * 2; }
    size_t num_of_sides() const final { return 4; }

    double height() const { return height_; }
    double width() const { return width_; }

private:
    double height_ = 0;
    double width_ = 0;
};
