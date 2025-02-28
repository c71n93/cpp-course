#include <gtest/gtest.h>

#include "shared.hpp"

using memory::Shared;

class Base {
public:
    explicit Base(int a) : a_(a) {}
    virtual ~Base() = default;

    int a_;
};

class Derived : public Base {
public:
    Derived(int a, int b) : Base(a), b_(b) {}

    int b_;
};

TEST(SharedPtr, DefaultConstructor) {
    const Shared<int> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_FALSE(ptr);
}

TEST(SharedPtr, ConstructorWithValue) {
    const Shared<int> ptr(new int(42));
    EXPECT_EQ(*ptr, 42);
    EXPECT_TRUE(ptr);
}

TEST(SharedPtr, ConstructorWithValueInheritance) {
    const Shared<Base> ptr(new Derived(41, 42));
    EXPECT_EQ(ptr->a_, 41);
    EXPECT_EQ(dynamic_cast<Derived*>(ptr.get())->b_, 42);
}

TEST(SharedPtr, CopyConstructor) {
    const Shared<int> ptr1(new int(42));
    const Shared<int> ptr2(ptr1);
    EXPECT_EQ(*ptr1, 42);
    EXPECT_EQ(*ptr2, 42);
}

TEST(SharedPtr, CopyConstructorInheritance) {
    const Shared<Derived> ptr_derived(new Derived(41, 42));
    const Shared<Base> ptr_base(ptr_derived);
    EXPECT_EQ(ptr_base->a_, 41);
    EXPECT_EQ(dynamic_cast<Derived*>(ptr_base.get())->b_, 42);
}

TEST(SharedPtr, MoveConstructor) {
    Shared<int> ptr1(new int(42));  // NOLINT
    const Shared<int> ptr2(std::move(ptr1));
    EXPECT_EQ(*ptr2, 42);
    EXPECT_EQ(ptr1.get(), nullptr);  // NOLINT
}

TEST(SharedPtr, MoveConstructorInheritance) {
    Shared<Derived> ptr_derived(new Derived(41, 42));  // NOLINT
    const Shared<Base> ptr_base(std::move(ptr_derived));
    EXPECT_EQ(ptr_base->a_, 41);
    EXPECT_EQ(dynamic_cast<Derived*>(ptr_base.get())->b_, 42);
    EXPECT_EQ(ptr_derived.get(), nullptr);  // NOLINT
}

TEST(SharedPtr, CopyAssignment) {
    const Shared<int> ptr1(new int(42));
    Shared<int> ptr2;
    ptr2 = ptr1;
    EXPECT_EQ(*ptr1, 42);
    EXPECT_EQ(*ptr2, 42);
}

TEST(SharedPtr, CopyAssignmentInheritance) {
    const Shared<Derived> ptr_derived(new Derived(41, 42));
    Shared<Base> ptr_base;
    ptr_base = ptr_derived;
    EXPECT_EQ(ptr_base->a_, 41);
    EXPECT_EQ(dynamic_cast<Derived*>(ptr_base.get())->b_, 42);
}

TEST(SharedPtr, MoveAssignment) {
    Shared<int> ptr1(new int(42));  // NOLINT
    Shared<int> ptr2;
    ptr2 = std::move(ptr1);
    EXPECT_EQ(*ptr2, 42);
    EXPECT_EQ(ptr1.get(), nullptr);  // NOLINT
}

TEST(SharedPtr, MoveAssignmentInheritance) {
    Shared<Derived> ptr_derived(new Derived(41, 42));  // NOLINT
    Shared<Base> ptr_base;
    ptr_base = std::move(ptr_derived);
    EXPECT_EQ(ptr_base->a_, 41);
    EXPECT_EQ(dynamic_cast<Derived*>(ptr_base.get())->b_, 42);
    EXPECT_EQ(ptr_derived.get(), nullptr);
}

TEST(SharedPtr, Swap) {
    Shared<int> ptr1(new int(42));  // NOLINT
    Shared<int> ptr2(new int(99));  // NOLINT
    ptr1.swap(ptr2);
    EXPECT_EQ(*ptr1, 99);
    EXPECT_EQ(*ptr2, 42);
}

TEST(SharedPtr, BooleanConversion) {
    Shared<int> ptr;
    EXPECT_FALSE(ptr);
    ptr = Shared<int>(new int(42));  // NOLINT
    EXPECT_TRUE(ptr);
}

TEST(SharedPtr, UseCountSingleOwner) {
    const Shared<int> ptr(new int(42));
    EXPECT_EQ(ptr.use_count(), 1);
}

TEST(SharedPtr, UseCountCopyConstructor) {
    const Shared<int> ptr1(new int(42));
    const Shared<int> ptr2(ptr1);
    EXPECT_EQ(ptr1.use_count(), 2);
    EXPECT_EQ(ptr2.use_count(), 2);
}

TEST(SharedPtr, UseCountCopyAssignment) {
    const Shared<int> ptr1(new int(42));
    Shared<int> ptr2;
    ptr2 = ptr1;
    EXPECT_EQ(ptr1.use_count(), 2);
    EXPECT_EQ(ptr2.use_count(), 2);
}

TEST(SharedPtr, UseCountMoveConstructor) {
    Shared<int> ptr1(new int(42));  // NOLINT
    const Shared<int> ptr2(std::move(ptr1));
    EXPECT_EQ(ptr2.use_count(), 1);
    EXPECT_EQ(ptr1.get(), nullptr);  // NOLINT
}

TEST(SharedPtr, UseCountMoveAssignment) {
    Shared<int> ptr1(new int(42));  // NOLINT
    Shared<int> ptr2;
    ptr2 = std::move(ptr1);
    EXPECT_EQ(ptr2.use_count(), 1);
    EXPECT_EQ(ptr1.get(), nullptr);  // NOLINT
}

TEST(SharedPtr, UseCountInheritanceCopy) {
    const Shared<Derived> ptr_derived(new Derived(41, 42));
    const Shared<Base> ptr_base(ptr_derived);
    EXPECT_EQ(ptr_derived.use_count(), 2);
    EXPECT_EQ(ptr_base.use_count(), 2);
}

TEST(SharedPtr, UseCountInheritanceMove) {
    Shared<Derived> ptr_derived(new Derived(41, 42));  // NOLINT
    const Shared<Base> ptr_base(std::move(ptr_derived));
    EXPECT_EQ(ptr_base.use_count(), 1);
    EXPECT_EQ(ptr_derived.get(), nullptr);  // NOLINT
}

TEST(SharedPtr, UseCountAfterReset) {
    Shared<int> ptr1(new int(42));  // NOLINT
    const Shared<int> ptr2(ptr1);
    ptr1 = Shared<int>();            // Reset ptr1
    EXPECT_EQ(ptr1.use_count(), 0);  // NOLINT
    EXPECT_EQ(ptr2.use_count(), 1);
}

TEST(SharedPtr, UseCountAfterSwap) {
    Shared<int> ptr1(new int(42));  // NOLINT
    Shared<int> ptr2(new int(99));  // NOLINT
    ptr1.swap(ptr2);
    EXPECT_EQ(ptr1.use_count(), 1);
    EXPECT_EQ(ptr2.use_count(), 1);
}

TEST(SharedPtr, UseCountNullptrDefaultConstructor) {
    const Shared<int> ptr;
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtr, UseCountNullptrAfterMove) {
    Shared<int> ptr1(new int(42));  // NOLINT
    const Shared<int> ptr2(std::move(ptr1));
    EXPECT_EQ(ptr1.use_count(), 0);  // NOLINT
    EXPECT_EQ(ptr2.use_count(), 1);
}

TEST(SharedPtr, UseCountNullptrAfterReset) {
    Shared<int> ptr(new int(42));  // NOLINT
    ptr = Shared<int>();           // Reset to nullptr
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtr, UseCountNullptrAfterReleaseAll) {
    Shared<int> ptr1(new int(42));  // NOLINT
    Shared<int> ptr2(ptr1);
    ptr1 = Shared<int>();  // Release one owner
    ptr2 = Shared<int>();  // Release the other owner
    EXPECT_EQ(ptr1.use_count(), 0);
    EXPECT_EQ(ptr2.use_count(), 0);
}
