#include <gtest/gtest.h>

#include <ranges>
#include <sstream>
#include <vector>

TEST(Views, Istream) {
    std::istringstream input("1 2 3 4 5");
    auto stream_view = std::ranges::views::istream<int>(input);

    std::vector<int> result;
    std::ranges::copy(stream_view, std::back_inserter(result));
    const std::vector<int> expected = {1, 2, 3, 4, 5};

    EXPECT_EQ(result, expected);
}

TEST(Views, Counted) {
    const std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    auto counted_view = std::views::counted(std::ranges::next(vec.begin(), 2), 3);

    const std::vector<int> result(counted_view.begin(), counted_view.end());

    EXPECT_EQ(result, (std::vector<int>{3, 4, 5}));
}

TEST(Views, JoinStrings) {
    const std::vector<std::string> words = {"hello", " ", "world"};
    const std::string result =
        std::string(std::views::join(words).begin(), std::views::join(words).end());

    EXPECT_EQ(result, "hello world");
}

TEST(Views, JoinNestedVecs) {
    const std::vector<std::vector<int>> nested = {{1, 2}, {3, 4}, {5, 6}};
    auto join_view = nested | std::ranges::views::join;

    const std::vector<int> result(join_view.begin(), join_view.end());
    const std::vector<int> expected = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ(result, expected);
}

TEST(Views, Stride) {
    const std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    auto stride_view = vec | std::views::stride(2);

    const std::vector<int> result(stride_view.begin(), stride_view.end());

    EXPECT_EQ(result, (std::vector<int>{1, 3, 5, 7}));
}

TEST(Views, JoinAndStride) {
    const std::vector<std::vector<int>> nested = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    auto join_view = nested | std::ranges::views::join;
    auto stride_view = join_view | std::ranges::views::stride(2);

    std::vector<int> result;
    std::ranges::copy(stride_view, std::back_inserter(result));
    const std::vector<int> expected = {1, 3, 5, 7};

    EXPECT_EQ(result, expected);
}
