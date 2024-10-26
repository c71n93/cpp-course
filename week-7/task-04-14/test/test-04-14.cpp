#include "gtest/gtest.h"
#include "is_class.hpp"

using is_class::is_class_v;
using is_class::IsClass;

TEST(IsClassTest, IsClassTest) {
    struct A {};
    static_assert(IsClass<A>::value);

    class B {};
    static_assert(is_class_v<B>);
    static_assert(not is_class_v<B*>);
    static_assert(not is_class_v<B&>);
    static_assert(is_class_v<const B>);

    enum class E {};
    static_assert(not IsClass<E>::value);

    union U {
        class UC {};
    };
    static_assert(not is_class_v<U>);
    static_assert(is_class_v<U::UC>);

    static_assert(not is_class_v<int>);

    static_assert(is_class_v<struct S>, "incomplete class");
    static_assert(is_class_v<class C>, "incomplete class");
}
