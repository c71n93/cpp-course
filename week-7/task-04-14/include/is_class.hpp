#pragma once

#include <type_traits>

namespace is_class {

template <class T>
struct IsClass {
private:
    template <class>
    static constexpr std::false_type test(...);
    template <class U>
    static constexpr std::integral_constant<bool, !std::is_union<U>::value> test(
        int U::*);  // only class has member pointers

public:
    static constexpr auto value = decltype(test<T>(nullptr))::value;
};

template <class T>
constexpr bool is_class_v = IsClass<T>::value;

}  // namespace is_class
