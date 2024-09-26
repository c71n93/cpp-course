#include <gtest/gtest.h>

#include "rectangle.hpp"
#include "rectangular_intersection.hpp"

using geometry2d::Rectangle;

TEST(RectangleIntersections, PointOutside) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({0, 0}, 0, 0);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({0, 0}, 0, 0));
}

TEST(RectangleIntersections, PointInside) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({1, 1}, 0, 0);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({1, 1}, 0, 0));
}

TEST(RectangleIntersections, LineOutside) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({-1, -1}, 0, 5);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({0, 0}, 0, 0));
}

TEST(RectangleIntersections, LineInside) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({1, 1}, 0, 2);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({1, 1}, 0, 2));
}

TEST(RectangleIntersections, LineIntersect) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({-1, 2}, 0, 10);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({0, 2}, 0, 4));
}

TEST(RectangleIntersections, RectangleOutside) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({5, 5}, 3, 10);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({0, 0}, 0, 0));
}

TEST(RectangleIntersections, RectangleIntersectPoint) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({4, 4}, 3, 10);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({4, 4}, 0, 0));
}

TEST(RectangleIntersections, RectangleIntersectLine) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({-1, 4}, 3, 10);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({0, 4}, 0, 4));
}

TEST(RectangleIntersections, RectangleInside) {
    const Rectangle rect1({0, 0}, 4, 4);
    const Rectangle rect2({1, 1}, 2, 2);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({1, 1}, 2, 2));
}

TEST(RectangleIntersections, RectangleIntersection) {
    const Rectangle rect1({-10, -10}, 4, 4);
    const Rectangle rect2({-8, -8}, 10, 10);
    const Rectangle result = rect1.intersection(rect2);
    EXPECT_EQ(result, Rectangle({-8, -8}, 2, 2));
}
