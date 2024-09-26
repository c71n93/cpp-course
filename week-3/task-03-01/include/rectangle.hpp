#pragma once

#include "point.hpp"

namespace geometry2d {

class Rectangle;

template <typename T>
concept Rectangular = std::derived_from<Rectangle, T>;

class Rectangle {
public:
    Rectangle(const Point& bottom_left, int64_t height, int64_t width)
        : bottom_left_(bottom_left), top_right_(bottom_left_.x + width, bottom_left_.y + height) {
        if (height < 0 || width < 0) {
            throw std::invalid_argument("height and width should be positive numbers.");
        }
    }
    virtual ~Rectangle() {}

    size_t square() const { return height() * width(); }

    Rectangle intersection(Rectangle rhs) const {
        const Point bottom_left_new = Point{std::max(bottom_left_.x, rhs.bottom_left_.x),
                                            std::max(bottom_left_.y, rhs.bottom_left_.y)};
        const Point top_right_new = Point{std::min(top_right_.x, rhs.top_right_.x),
                                          std::min(top_right_.y, rhs.top_right_.y)};
        const Rectangle result{bottom_left_new, top_right_new};
        return result.is_valid() ? result : Rectangle({0, 0}, 0, 0);
    }

    size_t height() const { return top_right_.y - bottom_left_.y; }
    size_t width() const { return top_right_.x - bottom_left_.x; }
    Point bottom_left() const { return bottom_left_; }

protected:
    Rectangle(const Point& bottom_left, const Point& top_right)
        : bottom_left_(bottom_left), top_right_(top_right) {}

private:
    bool is_valid() const {
        return bottom_left_.x <= top_right_.x && bottom_left_.y <= top_right_.y;
    }

    Point bottom_left_{0, 0};
    Point top_right_{0, 0};
};

template <Rectangular T>
bool operator==(const T& rhs, const T& lhs) {
    return rhs.height() == lhs.height() && rhs.width() == lhs.width() &&
           rhs.bottom_left() == lhs.bottom_left();
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << "bottom left: " << r.bottom_left() << "\n";
    os << "height: " << r.height() << " width " << r.width();
    return os;
}

}  // namespace geometry2d
