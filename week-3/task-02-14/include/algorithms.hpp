#pragma once

#include <ranges>
#include <vector>

namespace my_algorithms {

template <std::ranges::random_access_range Range>
    requires std::permutable<std::ranges::iterator_t<Range>> &&
             requires(size_t i, Range r) { r[i]; }
void reverse(Range& v) {
    const size_t size = std::ranges::distance(v);
    for (size_t i = 0; i < size / 2; ++i) {
        std::swap(v[i], v[size - 1 - i]);
    }
}

}  // namespace my_algorithms
