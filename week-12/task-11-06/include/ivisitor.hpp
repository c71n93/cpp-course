#pragma once

namespace geometry2d {

class Circle;
class Square;
class Triangle;
class Shape;

class IVisitor {
public:
    virtual ~IVisitor() = default;

    virtual void visit(const Circle& c) const = 0;
    virtual void visit(const Square& s) const = 0;
    virtual void visit(const Triangle& t) const = 0;
};

}  // namespace geometry2d
