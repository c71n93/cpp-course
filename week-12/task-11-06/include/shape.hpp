#pragma once

#include "ivisitor.hpp"

namespace geometry2d {

class Shape {
public:
    virtual ~Shape() = default;

    virtual void visit_by(const IVisitor& visitor) const = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

}  // namespace geometry2d
