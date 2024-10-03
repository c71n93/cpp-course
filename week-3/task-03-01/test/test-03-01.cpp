#include <gtest/gtest.h>

#include "rectangle.hpp"

using geometry2d::Rectangle;

TEST(RectangleSquare, Empty) { EXPECT_EQ(Rectangle().square(), 0); }

TEST(RectangleSquare, Point) { EXPECT_EQ(Rectangle({1, 2}, 0, 0).square(), 0); }

TEST(RectangleSquare, Line) { EXPECT_EQ(Rectangle({1, 2}, 0, 5).square(), 0); }

TEST(RectangleSquare, Rectangle) { EXPECT_EQ(Rectangle({-1, 2}, 12, 5).square(), 60); }

TEST(TwoRectanglesIntersections, PointOutside) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({0, 0}, 0, 0)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({0, 0}, 0, 0));
}

TEST(TwoRectanglesIntersections, PointInside) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({1, 1}, 0, 0)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({1, 1}, 0, 0));
}

TEST(TwoRectanglesIntersections, LineOutside) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({-1, -1}, 0, 5)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_TRUE(result.is_empty());
    EXPECT_EQ(result, Rectangle());
}

TEST(TwoRectanglesIntersections, LineInside) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({1, 1}, 0, 2)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({1, 1}, 0, 2));
}

TEST(TwoRectanglesIntersections, LineIntersect) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({-1, 2}, 0, 10)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({0, 2}, 0, 4));
}

TEST(TwoRectanglesIntersections, RectangleOutside) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({5, 5}, 3, 10)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_TRUE(result.is_empty());
    EXPECT_EQ(result, Rectangle());
}

TEST(TwoRectanglesIntersections, RectangleIntersectPoint) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({4, 4}, 3, 10)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({4, 4}, 0, 0));
}

TEST(TwoRectanglesIntersections, RectangleIntersectLine) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({-1, 4}, 3, 10)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({0, 4}, 0, 4));
}

TEST(TwoRectanglesIntersections, RectangleInside) {
    const std::vector<Rectangle> vec{Rectangle({0, 0}, 4, 4), Rectangle({1, 1}, 2, 2)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({1, 1}, 2, 2));
}

TEST(TwoRectanglesIntersections, RectangleIntersection) {
    const std::vector<Rectangle> vec{Rectangle({-10, -10}, 4, 4), Rectangle({-8, -8}, 10, 10)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({-8, -8}, 2, 2));
}

TEST(RectanglesIntersectionSquare, RectangleIntersection) {
    const std::vector<Rectangle> vec{Rectangle({-10, -10}, 4, 4), Rectangle({-8, -8}, 10, 10),
                                     Rectangle({-9, -9}, 3, 2)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle({-8, -8}, 2, 1));
    EXPECT_EQ(result.square(), 2);
}

TEST(RectanglesIntersectionSquare, RectangleEmptyIntersection) {
    const std::vector<Rectangle> vec{Rectangle({-10, -10}, 4, 4), Rectangle({-8, -8}, 10, 10),
                                     Rectangle({-5, -5}, 3, 2)};
    const Rectangle result = Rectangle::intersection(vec);
    EXPECT_EQ(result, Rectangle());
    EXPECT_EQ(result.square(), 0);
}
