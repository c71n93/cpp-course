#include <gtest/gtest.h>

#include "list.hpp"

using container::List;

TEST(List, PushBackSingleElement) {
    List<int> list;
    list.push_back(42);  // NOLINT

    ASSERT_EQ(list.front(), 42);
    ASSERT_EQ(list.back(), 42);
}

TEST(List, PushBackMultipleElements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(List, PushFrontSingleElement) {
    List<int> list;
    list.push_front(42);  // NOLINT

    ASSERT_EQ(list.front(), 42);
    ASSERT_EQ(list.back(), 42);
}

TEST(List, PushFrontMultipleElements) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(List, PushFrontAndBack) {
    List<int> list;
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);

    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(List, IteratorIncrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(List, IteratorDecrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    ++it;
    ++it;
    EXPECT_EQ(*it, 3);
    --it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 1);
}

TEST(List, ConstFrontBack) {
    List<int> list;
    list.push_back(42);  // NOLINT

    const List<int>& const_list = list;
    EXPECT_EQ(const_list.front(), 42);
    EXPECT_EQ(const_list.back(), 42);
}

TEST(List, EmptyList) {
    const List<int> list;
    EXPECT_EQ(list.begin(), list.end());
}

TEST(List, RangeBasedForLoop) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    int expected_value = 1;
    for (const int value : list) {
        EXPECT_EQ(value, expected_value);
        ++expected_value;
    }
}
