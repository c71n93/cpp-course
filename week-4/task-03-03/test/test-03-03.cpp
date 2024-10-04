#include <gtest/gtest.h>

#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

TEST(PolygonsTest, RectangleTest) {
    const Rectangle rect{5.5, 3.5};
    const Polygon& polygon = rect;
    const Shape& shape = polygon;
    EXPECT_EQ(polygon.num_of_sides(), 4);
    EXPECT_DOUBLE_EQ(shape.perimeter(), rect.width() * 2 + rect.height() * 2);
    EXPECT_DOUBLE_EQ(shape.area(), rect.width() * rect.height());
}

TEST(PolygonsTest, SquareTest) {
    const Square square{2.28};
    const Polygon& polygon = square;
    const Shape& shape = polygon;
    EXPECT_EQ(polygon.num_of_sides(), 4);
    EXPECT_DOUBLE_EQ(shape.perimeter(), square.width() * 4);
    EXPECT_DOUBLE_EQ(shape.area(), square.width() * square.width());
}

TEST(PolygonsTest, TriangleTest) {
    const Triangle triangle{3, 4, 5};
    const Polygon& polygon = triangle;
    const Shape& shape = polygon;
    EXPECT_EQ(polygon.num_of_sides(), 3);
    EXPECT_DOUBLE_EQ(shape.perimeter(), triangle.a() + triangle.b() + triangle.c());
    EXPECT_DOUBLE_EQ(shape.area(), triangle.a() * triangle.b() / 2);
}
