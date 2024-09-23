#pragma once

namespace geometry2d {

struct Point final {
    int64_t x;
    int64_t y;
};

class Rectangle final {
public:
    Rectangle(const Point& left_down, size_t height, size_t width)
        : left_down_(left_down), height_(height), width_(width) {}

    size_t square() const { return height_ * width_; }

    Rectangle intersection(Rectangle rhs) {
        return Rectangle(Point{0, 0}, 0, 0);  // TODO
    }

private:
    Point left_down_{0, 0};
    size_t height_ = 0;
    size_t width_ = 0;
};

}  // namespace geometry2d
