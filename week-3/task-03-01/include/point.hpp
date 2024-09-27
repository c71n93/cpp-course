#pragma once

namespace geometry2d {

struct Point final {
    int64_t x;
    int64_t y;

    static Point bottom_left_most() {
        return Point{std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::min()};
    }
    static Point top_right_most() {
        return Point{std::numeric_limits<int64_t>::max(), std::numeric_limits<int64_t>::max()};
    }

    bool operator==(const Point&) const = default;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "x: " << p.x << " y: " << p.y;
    return os;
}

}  // namespace geometry2d
