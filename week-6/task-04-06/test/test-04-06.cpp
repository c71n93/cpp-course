#include "gtest/gtest.h"
#include "multipush_back.hpp"

TEST(MultiPushTest, MultiPushTest) {
    std::vector<int> vec{};
    container::multipush_back(vec, 1, 2, 3, 4, 5);  // NOLINT
    for (int i = 0; i < 5; ++i) {                   // NOLINT
        EXPECT_EQ(vec[i], i + 1);
    }
}
