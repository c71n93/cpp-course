#include <type_traits>

#include "const_manipulations.hpp"
#include "gtest/gtest.h"

using const_manipulations::AddConst_t;
using const_manipulations::RemoveConst_t;

struct Test {
    int a;
};

TEST(ConstManipulationTest, AddConstTest) {
    static_assert(std::is_same_v<AddConst_t<int>, std::add_const_t<int>>);
    static_assert(std::is_same_v<AddConst_t<const int>, std::add_const_t<const int>>);
    static_assert(std::is_same_v<AddConst_t<int&>, std::add_const_t<int&>>);  // int&, int&
    static_assert(std::is_same_v<AddConst_t<const int&>, std::add_const_t<const int&>>);

    static_assert(std::is_same_v<AddConst_t<Test>, std::add_const_t<Test>>);
    static_assert(std::is_same_v<AddConst_t<const Test>, std::add_const_t<const Test>>);
    static_assert(std::is_same_v<AddConst_t<Test&>, std::add_const_t<Test&>>);  // Test&, Test&
    static_assert(std::is_same_v<AddConst_t<const Test&>, std::add_const_t<const Test&>>);
}

TEST(ConstManipulationTest, RemoveConstTest) {
    static_assert(std::is_same_v<RemoveConst_t<int>, std::remove_const_t<int>>);
    static_assert(std::is_same_v<RemoveConst_t<const int>, std::remove_const_t<const int>>);
    static_assert(std::is_same_v<RemoveConst_t<int&>, std::remove_const_t<int&>>);
    static_assert(std::is_same_v<RemoveConst_t<const int&>,
                                 std::remove_const_t<const int&>>);  // const int&, const int&

    static_assert(std::is_same_v<RemoveConst_t<Test>, std::remove_const_t<Test>>);
    static_assert(std::is_same_v<RemoveConst_t<const Test>, std::remove_const_t<const Test>>);
    static_assert(std::is_same_v<RemoveConst_t<Test&>, std::remove_const_t<Test&>>);
    static_assert(std::is_same_v<RemoveConst_t<const Test&>,
                                 std::remove_const_t<const Test&>>);  // const Test&, const Test&
}
