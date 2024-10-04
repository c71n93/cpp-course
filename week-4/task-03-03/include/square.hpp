#pragma once

#include "rectangle.hpp"

class Square : public Rectangle {
public:
    explicit Square(double side) : Rectangle(side, side) {}

    double side() const { return Rectangle::height(); }
};
