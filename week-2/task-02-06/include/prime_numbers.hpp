#pragma once

#include <vector>

namespace math {

std::vector<std::uint64_t> prime_factors(std::uint64_t num) {
    std::vector<std::uint64_t> res{};
    std::uint64_t divider = 2;
    while (num != 1) {
        if (num % divider != 0) {
            divider++;
        } else {
            num /= divider;
            res.push_back(divider);
        }
    }
    return res;
}

}  // namespace math
