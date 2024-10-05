#include <gtest/gtest.h>

#include "different_inheritance.hpp"

using inheritance::Derived, inheritance::Base1, inheritance::Base2, inheritance::VirtualBase;

TEST(Casts, RightCasts) {
    const Derived d{1};
    const Base1& b1 = d;
    const VirtualBase& vb = d;

    // downcast (may be static_cast)
    EXPECT_NO_THROW(const Derived& db = dynamic_cast<const Derived&>(b1));
    // downcast from virtual base (should be dynamic_cast)
    EXPECT_NO_THROW(const Derived& dvb = dynamic_cast<const Derived&>(vb));
    // side cast (should be dynamic_cast)
    EXPECT_NO_THROW(const Base2& b2b1 = dynamic_cast<const Base2&>(b1));
}

TEST(Casts, WrongCasts) {
    const Base1 b1{2};
    const VirtualBase& vb1 = b1;

    // bad downcast
    EXPECT_THROW(const Derived& db = dynamic_cast<const Derived&>(b1), std::bad_cast);
    // bad downcast from virtual base (after upcast)
    EXPECT_THROW(const Derived& dvb = dynamic_cast<const Derived&>(vb1), std::bad_cast);
    // bad side cast
    EXPECT_THROW(const Base2& b2b1 = dynamic_cast<const Base2&>(b1), std::bad_cast);
}
