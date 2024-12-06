#pragma once

#include "cstdlib"

namespace math {

double eulers_number(double precision) {
    double last = 1.0;
    double sum = 1.0;
    for (size_t iters = 1; last >= precision; iters++) {
        last /= static_cast<double>(iters);
        sum += last;
    }
    return sum;
}

}  // namespace math
