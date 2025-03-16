#pragma once

#include <iostream>

#include "circle.hpp"
#include "ivisitor.hpp"
#include "square.hpp"
#include "triangle.hpp"

namespace geometry2d {

class Serializer : public IVisitor {
public:
    void visit(const Circle &c) const override {
        std::cout << "Circle:" << std::endl;
        std::cout << "\tradius: " << c.radius() << std::endl;
        std::cout << "\t\tperimeter: " << c.perimeter() << std::endl;
        std::cout << "\t\tarea: " << c.area() << std::endl;
    }
    void visit(const Square &s) const override {
        std::cout << "Square:" << std::endl;
        std::cout << "\tside: " << s.side() << std::endl;
        std::cout << "\t\tperimeter: " << s.perimeter() << std::endl;
        std::cout << "\t\tarea: " << s.area() << std::endl;
    }
    void visit(const Triangle &t) const override {
        std::cout << "Triangle:" << std::endl;
        std::cout << "\tside1: " << t.side1() << std::endl;
        std::cout << "\tside2: " << t.side2() << std::endl;
        std::cout << "\tside3: " << t.side3() << std::endl;
        std::cout << "\t\tperimeter: " << t.perimeter() << std::endl;
        std::cout << "\t\tarea: " << t.area() << std::endl;
    }
};

}  // namespace geometry2d
