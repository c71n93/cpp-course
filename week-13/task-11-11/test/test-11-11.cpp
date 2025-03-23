#include <gtest/gtest.h>

#include <list>

#include "transform_if.hpp"

using my_algorithm::transform_if;

TEST(TransformIfTest, SimpleTransformAndFilter) {
    const std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output;

    transform_if(
        input.begin(), input.end(), std::back_inserter(output), [](int x) { return x * x; },
        [](int x) { return x % 2 == 0; });

    const std::vector<int> expected = {4, 16};
    EXPECT_EQ(output, expected);
}

TEST(TransformIfTest, StringTransformAndFilter) {
    const std::vector<std::string> input = {"apple", "banana", "cherry", "date"};
    std::vector<std::string> output;

    transform_if(
        input.begin(), input.end(), std::back_inserter(output),
        [](const std::string& s) {
            std::string result = s;
            std::transform(result.begin(), result.end(), result.begin(),
                           [](auto&& e) { return std::toupper(e); });
            return result;
        },
        [](const std::string& s) { return s.length() > 5; });  // NOLINT

    const std::vector<std::string> expected = {"BANANA", "CHERRY"};
    EXPECT_EQ(output, expected);
}

TEST(TransformIfTest, EmptyInputRange) {
    constexpr std::vector<int> input;
    std::vector<int> output;

    transform_if(
        input.begin(), input.end(), std::back_inserter(output), [](int x) { return x * 2; },
        [](int x) { return x > 0; });

    EXPECT_TRUE(output.empty());
}

TEST(TransformIfTest, NoElementsSatisfyPredicate) {
    const std::vector<int> input = {1, 3, 5, 7};
    std::vector<int> output;

    transform_if(
        input.begin(), input.end(), std::back_inserter(output), [](int x) { return x * 2; },
        [](int x) { return x % 2 == 0; });

    EXPECT_TRUE(output.empty());
}

TEST(TransformIfTest, AllElementsSatisfyPredicate) {
    const std::vector<int> input = {2, 4, 6, 8};
    std::vector<int> output;

    transform_if(
        input.begin(), input.end(), std::back_inserter(output), [](int x) { return x / 2; },
        [](int x) { return x % 2 == 0; });

    const std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(output, expected);
}

TEST(TransformIfTest, ListInput) {
    const std::list<int> input = {10, 20, 30, 40};
    std::vector<int> output;

    transform_if(
        input.begin(), input.end(), std::back_inserter(output), [](int x) { return x + 1; },
        [](int x) { return x > 15; });  // NOLINT

    const std::vector<int> expected = {21, 31, 41};
    EXPECT_EQ(output, expected);
}
