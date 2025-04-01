#pragma once

namespace my_algorithm {

template <std::ranges::forward_range Range>
    requires requires {
        requires std::convertible_to<std::ranges::range_value_t<Range>, std::string_view>;
    }
std::string join(const Range& strings, const std::string& delimiter) {
    std::string res;
    for (auto it = std::begin(strings); it != std::end(strings); ++it) {
        if (it != std::begin(strings)) {
            res += delimiter;
        }
        res += *it;
    }
    return res;
}

}  // namespace my_algorithm
