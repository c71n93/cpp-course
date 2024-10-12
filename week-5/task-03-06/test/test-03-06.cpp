#include "container.hpp"
#include "gtest/gtest.h"

TEST(ContainerTest, ConstructsWithSize) {
    const size_t size = 23;
    const Container<int> cont(size);
    EXPECT_EQ(cont.size(), size);
    EXPECT_NO_FATAL_FAILURE(cont.front());
    EXPECT_NO_FATAL_FAILURE(cont.back());
}

TEST(ContainerTest, ConstructsEmpty) {
    const Container<int> cont{};
    EXPECT_EQ(cont.size(), 0);
    EXPECT_DEBUG_DEATH(cont.front(), "");
    EXPECT_DEBUG_DEATH(cont.back(), "");
    EXPECT_DEBUG_DEATH(cont[0], "");
}

TEST(ContainerTest, ConstructsWithSizeAndValue) {
    constexpr size_t size = 5;
    constexpr int value = 42;
    const Container<int> cont(size, value);
    EXPECT_EQ(cont.size(), size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(cont[i], value);
    }
}

TEST(ContainerTest, CopyConstructor) {
    constexpr size_t size = 4;
    constexpr int value = 7;
    const Container<int> cont1(size, value);
    const Container<int> cont2 = cont1;
    EXPECT_EQ(cont1.size(), cont2.size());
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(cont1[i], cont2[i]);
    }
}

TEST(ContainerTest, MoveConstructor) {
    constexpr size_t size = 3;
    constexpr int move_value = 9;
    Container<int> cont1(size, move_value);
    Container<int> cont2 = std::move(cont1);
    EXPECT_EQ(cont2.size(), size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(cont2[i], move_value);
    }
    EXPECT_EQ(cont1.size(), 0);  // cont1 should be empty after move
}

TEST(ContainerTest, AssignmentOperator) {
    constexpr size_t size1 = 2;
    constexpr size_t size2 = 4;
    constexpr int value1 = 5;
    constexpr int value2 = 8;
    Container<int> cont1(size1, value1);
    const Container<int> cont2(size2, value2);
    cont1 = cont2;
    EXPECT_EQ(cont1.size(), size2);
    for (size_t i = 0; i < size2; ++i) {
        EXPECT_EQ(cont1[i], value2);
    }
}

TEST(ContainerTest, MoveAssignmentOperator) {
    constexpr size_t size1 = 3;
    constexpr size_t size2 = 6;
    constexpr int value1 = 3;
    constexpr int value2 = 6;
    Container<int> cont1(size1, value1);
    Container<int> cont2(size2, value2);
    cont1 = std::move(cont2);
    EXPECT_EQ(cont1.size(), size2);
    for (size_t i = 0; i < size2; ++i) {
        EXPECT_EQ(cont1[i], value2);
    }
    EXPECT_EQ(cont2.size(), 0);  // cont2 should be empty after move
}

TEST(ContainerTest, FrontAndBack) {
    constexpr size_t size = 5;
    constexpr int initial_value = 10;
    constexpr int front_value = 1;
    constexpr int back_value = 99;
    Container<int> cont(size, initial_value);
    EXPECT_EQ(cont.front(), initial_value);
    EXPECT_EQ(cont.back(), initial_value);
    cont[0] = front_value;
    cont[size - 1] = back_value;
    EXPECT_EQ(cont.front(), front_value);
    EXPECT_EQ(cont.back(), back_value);
}

TEST(ContainerTest, Clear) {
    constexpr size_t size = 7;
    constexpr int value = 3;
    Container<int> cont(size, value);
    cont.clear();
    EXPECT_EQ(cont.size(), 0);
    EXPECT_DEBUG_DEATH(cont.front(), "");
    EXPECT_DEBUG_DEATH(cont.back(), "");
}

TEST(ContainerTest, Empty) {
    const Container<int> empty_cont;
    EXPECT_TRUE(empty_cont.empty());
    constexpr size_t size = 4;
    constexpr int value = 10;
    const Container<int> non_empty_cont(size, value);
    EXPECT_FALSE(non_empty_cont.empty());
}

TEST(ContainerTest, PushToEmptyContainer) {
    Container<int> cont;
    constexpr int new_value = 42;
    EXPECT_EQ(cont.size(), 0);
    EXPECT_TRUE(cont.empty());
    cont.push(new_value);
    EXPECT_EQ(cont.size(), 1);
    EXPECT_FALSE(cont.empty());
    EXPECT_EQ(cont.front(), new_value);
    EXPECT_EQ(cont.back(), new_value);
}

TEST(ContainerTest, PushWithoutResizing) {
    constexpr size_t initial_size = 1;
    constexpr int initial_value = 10;
    constexpr int new_value = 42;
    Container<int> cont(initial_size, initial_value);
    ASSERT_EQ(cont.size(), initial_size);
    ASSERT_EQ(cont.capacity(), initial_size);
    cont.push(new_value);
    EXPECT_EQ(cont.size(), 2);
    EXPECT_EQ(cont[1], new_value);
    EXPECT_EQ(cont.front(), initial_value);
    EXPECT_EQ(cont.back(), new_value);
}

TEST(ContainerTest, PushWithResizing) {
    constexpr size_t initial_size = 2;
    constexpr int initial_value = 7;
    constexpr int new_value = 42;
    Container<int> cont(initial_size, initial_value);
    ASSERT_EQ(cont.size(), initial_size);
    ASSERT_EQ(cont.capacity(), initial_size);
    cont.push(new_value);
    EXPECT_GT(cont.capacity(), initial_size);
    EXPECT_EQ(cont.size(), 3);
    EXPECT_EQ(cont[2], new_value);
}

TEST(ContainerTest, PushMultipleWithResizing) {
    constexpr size_t initial_size = 2;
    constexpr int initial_value = 7;
    constexpr size_t num_new_values = 5;
    const int new_values[num_new_values] = {8, 9, 10, 11, 12};
    Container<int> cont(initial_size, initial_value);
    for (const int value : new_values) {
        cont.push(value);
    }
    EXPECT_EQ(cont.size(), initial_size + num_new_values);
    EXPECT_GT(cont.capacity(), initial_size);
    for (size_t i = 0; i < num_new_values; ++i) {
        EXPECT_EQ(cont[initial_size + i], new_values[i]);
    }
}

TEST(ContainerTest, PushLargeNumberOfElements) {
    Container<int> cont;
    constexpr int large_number = 1000;
    for (int i = 0; i < large_number; ++i) {
        cont.push(i);
    }
    EXPECT_EQ(cont.size(), large_number);
    EXPECT_EQ(cont.capacity(), 1024);
    for (int i = 0; i < large_number; ++i) {
        EXPECT_EQ(cont[i], i);
    }
}

TEST(ContainerTest, PushAfterClear) {
    constexpr size_t initial_size = 3;
    constexpr int initial_value = 10;
    constexpr int new_value = 42;
    Container<int> cont(initial_size, initial_value);
    cont.clear();
    cont.push(new_value);
    EXPECT_EQ(cont.size(), 1);
    EXPECT_FALSE(cont.empty());
    EXPECT_EQ(cont.front(), new_value);
    EXPECT_EQ(cont.back(), new_value);
}
