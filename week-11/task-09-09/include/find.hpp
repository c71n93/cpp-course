#pragma once
#include <iterator>

namespace my_algorithms {

template <typename ForwardIt, typename T = typename std::iterator_traits<ForwardIt>::value_type>
ForwardIt find(ForwardIt first, ForwardIt last, const T& value) {
    using IterDiff = typename std::iterator_traits<ForwardIt>::difference_type;
    ForwardIt it;
    IterDiff count = std::distance(first, last);
    IterDiff step;
    if (count == 0) {
        return last;
    }
    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (*it < value) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return *first == value ? first : last;
}

}  // namespace my_algorithms
