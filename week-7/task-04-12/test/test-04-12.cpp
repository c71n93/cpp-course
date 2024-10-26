#include <type_traits>

#include "const_manipulations.hpp"
#include "gtest/gtest.h"

using const_manipulations::AddConst_t;
using const_manipulations::RemoveConst_t;

struct Test {
    int a;
};

TEST(ConstManipulationTest, AddConstTest) {
    static_assert(std::is_same<AddConst_t<int>, std::add_const<int>::type>::value);
    static_assert(std::is_same<AddConst_t<const int>, std::add_const<const int>::type>::value);
    static_assert(std::is_same<AddConst_t<int&>, std::add_const<int&>::type>::value);  // int&, int&
    static_assert(std::is_same<AddConst_t<const int&>, std::add_const<const int&>::type>::value);

    static_assert(std::is_same<AddConst_t<Test>, std::add_const<Test>::type>::value);
    static_assert(std::is_same<AddConst_t<const Test>, std::add_const<const Test>::type>::value);
    static_assert(
        std::is_same<AddConst_t<Test&>, std::add_const<Test&>::type>::value);  // Test&, Test&
    static_assert(std::is_same<AddConst_t<const Test&>, std::add_const<const Test&>::type>::value);
}

TEST(ConstManipulationTest, RemoveConstTest) {
    static_assert(std::is_same<RemoveConst_t<int>, std::remove_const<int>::type>::value);
    static_assert(
        std::is_same<RemoveConst_t<const int>, std::remove_const<const int>::type>::value);
    static_assert(std::is_same<RemoveConst_t<int&>, std::remove_const<int&>::type>::value);
    static_assert(
        std::is_same<RemoveConst_t<const int&>,
                     std::remove_const<const int&>::type>::value);  // const int&, const int&

    static_assert(std::is_same<RemoveConst_t<Test>, std::remove_const<Test>::type>::value);
    static_assert(
        std::is_same<RemoveConst_t<const Test>, std::remove_const<const Test>::type>::value);
    static_assert(std::is_same<RemoveConst_t<Test&>, std::remove_const<Test&>::type>::value);
    static_assert(
        std::is_same<RemoveConst_t<const Test&>,
                     std::remove_const<const Test&>::type>::value);  // const Test&, const Test&
}
