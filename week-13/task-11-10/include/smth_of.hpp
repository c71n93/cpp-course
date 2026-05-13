#pragma once
#include <ranges>

namespace my_algorithm {

template <std::ranges::range Range, typename T>
    requires std::convertible_to<T, typename Range::value_type>
bool has_one(const Range& range, T&& value) {
    return std::ranges::find(range, std::forward<T>(value)) != range.end();
}

template <std::ranges::range Range, typename... Args>
    requires(std::convertible_to<Args, typename Range::size_type> && ...)
bool any_of(const Range& range, Args&&... args) {
    return (has_one(range, std::forward<Args>(args)) || ...);
}

template <std::ranges::range Range, typename... Args>
    requires(std::convertible_to<Args, typename Range::size_type> && ...)
bool all_of(const Range& range, Args&&... args) {
    return (has_one(range, std::forward<Args>(args)) && ...);
}

template <std::ranges::range Range, typename... Args>
    requires(std::convertible_to<Args, typename Range::size_type> && ...)
bool none_of(const Range& range, Args&&... args) {
    return (!has_one(range, std::forward<Args>(args)) && ...);
}

}  // namespace my_algorithm
