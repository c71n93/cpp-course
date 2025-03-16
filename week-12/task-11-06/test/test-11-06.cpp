#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <sstream>

#include "serializer.hpp"

using geometry2d::Circle;
using geometry2d::Serializer;
using geometry2d::Shape;
using geometry2d::Square;
using geometry2d::Triangle;

std::string capture_output(const std::function<void()>& printer_func) {
    const std::ostringstream oss;
    auto old_cout_buffer = std::cout.rdbuf(oss.rdbuf());
    printer_func();
    std::cout.rdbuf(old_cout_buffer);
    return oss.str();
}

TEST(Serializer, ShapeCircle) {
    const Serializer serializer{};
    const std::unique_ptr<Shape> shape = std::make_unique<Circle>(4);
    const std::string expected_output =
        "Circle:\n"
        "\tradius: 4\n"
        "\t\tperimeter: 25.1327\n"
        "\t\tarea: 50.2655\n";
    const std::string output = capture_output([&]() { shape->visit_by(serializer); });
    EXPECT_EQ(output, expected_output);
}

TEST(Serializer, ShapeSquare) {
    const Serializer serializer{};
    const std::unique_ptr<Shape> shape = std::make_unique<Square>(5);
    const std::string expected_output =
        "Square:\n"
        "\tside: 5\n"
        "\t\tperimeter: 20\n"
        "\t\tarea: 25\n";
    const std::string output = capture_output([&]() { shape->visit_by(serializer); });
    EXPECT_EQ(output, expected_output);
}

TEST(Serializer, ShapeTriangle) {
    const Serializer serializer{};
    const std::unique_ptr<Shape> shape = std::make_unique<Triangle>(3, 4, 5);
    const std::string expected_output =
        "Triangle:\n"
        "\tside1: 3\n"
        "\tside2: 4\n"
        "\tside3: 5\n"
        "\t\tperimeter: 12\n"
        "\t\tarea: 6\n";
    const std::string output = capture_output([&]() { shape->visit_by(serializer); });
    EXPECT_EQ(output, expected_output);
}

TEST(Serializer, InvalidCircleRadius) { EXPECT_THROW(Circle(-1), std::invalid_argument); }

TEST(Serializer, InvalidSquareSide) { EXPECT_THROW(Square(0), std::invalid_argument); }

TEST(Serializer, InvalidTriangleSides) {
    EXPECT_THROW(Triangle(1, 2, 3), std::invalid_argument);
    EXPECT_THROW(Triangle(-1, 2, 2), std::invalid_argument);
}
