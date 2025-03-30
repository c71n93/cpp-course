#pragma once

namespace my_algorithm {

template <class InputIt, class OutputIt, class Fct, class Pred>
void transform_if(InputIt first, InputIt last, OutputIt dest, Fct transform, Pred pred) {
    while (first != last) {
        if (pred(*first)) {
            *(dest++) = transform(*first);
        }
        ++first;
    }
}

}  // namespace my_algorithm
