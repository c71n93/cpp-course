#pragma once

#include <cmath>
#include <vector>

namespace math {

std::vector<uint64_t> prime_factors_naive(uint64_t num) {
    std::vector<uint64_t> res{};
    uint64_t divider = 2;
    while (num > 1) {
        if (num % divider == 0) {
            num /= divider;
            res.push_back(divider);
        } else {
            divider++;
        }
    }
    return res;
}

std::vector<uint64_t> prime_factors(uint64_t num) {
    std::vector<uint64_t> res{};
    uint64_t sqrt = static_cast<uint64_t>(std::sqrt(num)) + 1;
    uint64_t divider = 2;
    while (divider < sqrt && num > 1) {
        if (num % divider == 0) {
            num /= divider;
            res.push_back(divider);
        } else {
            divider++;
        }
    }
    if (num > 1) {
        res.push_back(num);
    }
    return res;
}

}  // namespace math
