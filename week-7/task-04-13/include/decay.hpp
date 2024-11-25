#pragma once

#include <type_traits>

#include "const_manipulations.hpp"

namespace decay {

template <typename T>
struct Decay {
private:
    using U = std::remove_reference_t<T>;

public:
    using type =
        std::conditional_t<std::is_array_v<U>,
                           std::add_pointer_t<std::remove_extent_t<U>>,  // Q[] -> Q*, where Q[]=U
                           std::conditional_t<std::is_function_v<U>,
                                              std::add_pointer_t<U>,  // R(A) -> * R(A),
                                                                      // where R(A)=U
                                              std::remove_cv_t<U>     // const volatile U -> U
                                              >>;
};
template <typename T>
using Decay_t = typename Decay<T>::type;

}  // namespace decay
