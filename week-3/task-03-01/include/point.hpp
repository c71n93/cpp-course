#pragma once

namespace geometry2d {

struct Point final {
    int64_t x;
    int64_t y;

    bool operator==(const Point&) const = default;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "x: " << p.x << " y: " << p.y;
    return os;
}

}  // namespace geometry2d
