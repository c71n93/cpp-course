#pragma once

#include "shape.hpp"

class Polygon : public Shape {
public:
    virtual size_t num_of_sides() const = 0;
};
