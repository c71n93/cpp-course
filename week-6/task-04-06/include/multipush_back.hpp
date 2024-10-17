#pragma once

#include <utility>

namespace container {

template <typename Cont>
concept BackPushable = std::ranges::range<Cont> &&
                       requires(Cont c, std::ranges::range_value_t<Cont> v) { c.push_back(v); };

template <BackPushable Cont, typename... Elem>
void multipush_back(Cont& container, Elem&&... elems) {
    (container.push_back(std::forward<Elem>(elems)), ...);
}

}  // namespace container
