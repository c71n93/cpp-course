#pragma once

namespace const_manipulations {

template <typename T>
struct AddConst {
    using type = const T;
};
template <typename T>
using AddConst_t = typename AddConst<T>::type;

template <typename T>
struct RemoveConst {
    using type = T;
};
template <typename T>
struct RemoveConst<const T> {
    using type = T;
};
template <typename T>
using RemoveConst_t = typename RemoveConst<T>::type;

}  // namespace const_manipulations