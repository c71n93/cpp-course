#pragma once

#include "point.hpp"
#include "ranges"

namespace geometry2d {

class Rectangle {
public:
    Rectangle() : is_empty_(true) {}
    Rectangle(const Point& bottom_left, int64_t height, int64_t width)
        : bottom_left_(bottom_left), top_right_(bottom_left_.x + width, bottom_left_.y + height) {
        if (height < 0 || width < 0) {
            throw std::invalid_argument("height and width should be positive numbers");
        }
    }
    Rectangle(const Point& bottom_left, const Point& top_right)
        : bottom_left_(bottom_left), top_right_(top_right) {
        if (!is_valid(bottom_left_, top_right_)) {
            throw std::invalid_argument("invalid points for rectangle");
        }
    }

    bool operator==(const Rectangle& rhs) const = default;

    size_t square() const { return height() * width(); }
    size_t height() const { return top_right_.y - bottom_left_.y; }
    size_t width() const { return top_right_.x - bottom_left_.x; }
    const Point& bottom_left() const { return bottom_left_; }
    bool is_empty() const { return is_empty_; }

    template <typename RectangleRange>
        requires std::ranges::input_range<RectangleRange> &&
                 std::same_as<std::ranges::range_value_t<RectangleRange>, Rectangle>
    static Rectangle intersection(RectangleRange&& range) {
        if (std::ranges::empty(range)) {
            return Rectangle();
        }
        Point bottom_left = Point::bottom_left_most();
        Point top_right = Point::top_right_most();
        std::ranges::for_each(range, [&bottom_left, &top_right](const auto& rect) {
            bottom_left = Point{std::max(bottom_left.x, rect.bottom_left_.x),
                                std::max(bottom_left.y, rect.bottom_left_.y)};
            top_right = Point{std::min(top_right.x, rect.top_right_.x),
                              std::min(top_right.y, rect.top_right_.y)};
        });
        return is_valid(bottom_left, top_right) ? Rectangle(bottom_left, top_right) : Rectangle();
    }

private:
    static bool is_valid(const Point& bottom_left, const Point& top_right) {
        return bottom_left.x <= top_right.x && bottom_left.y <= top_right.y;
    }

    bool is_empty_ = false;
    Point bottom_left_{0, 0};
    Point top_right_{0, 0};
};

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    if (r.is_empty()) {
        os << "empty";
    } else {
        os << "bottom left: " << r.bottom_left() << "\n";
        os << "height: " << r.height() << " width " << r.width();
    }
    return os;
}

}  // namespace geometry2d
