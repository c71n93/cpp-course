#include "decay.hpp"
#include "gtest/gtest.h"

using decay::Decay_t;

template <typename T, typename U>
constexpr bool is_decay_equ = std::is_same_v<Decay_t<T>, U>;

TEST(ConstManipulationTest, AddConstTest) {
    static_assert(is_decay_equ<int, int>);
    static_assert(!is_decay_equ<int, float>);
    static_assert(is_decay_equ<int&, int>);
    static_assert(is_decay_equ<int&&, int>);
    static_assert(is_decay_equ<const int&, int>);
    static_assert(is_decay_equ<int[2], int*>);
    static_assert(!is_decay_equ<int[4][2], int*>);
    static_assert(!is_decay_equ<int[4][2], int**>);
    static_assert(is_decay_equ<int[4][2], int(*)[2]>);
    static_assert(is_decay_equ<int(int), int (*)(int)>);
}
