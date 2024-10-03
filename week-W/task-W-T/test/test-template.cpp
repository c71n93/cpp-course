#include <gtest/gtest.h>

TEST(Dummy, DummyTestSuccess) {
    std::cout << "Hello" << std::endl;
    EXPECT_TRUE(true);
}
