#include "car_numbers.hpp"
#include "gtest/gtest.h"

TEST(RusCarNumbersTest, EmptyInput) {
    EXPECT_EQ(rus_car_numbers(""), std::vector<std::string>({}));
}

TEST(RusCarNumbersTest, NoNumbersInText) {
    const std::string text = R"(
        Just text without license plates.
        Examples: 12345, ABCDEF, !@#$%^&*
        Similar looking: AB12CD, X9Y9Z9
    )";
    EXPECT_EQ(rus_car_numbers(text), std::vector<std::string>({}));
}

TEST(RusCarNumbersTest, ValidNumbersWithoutRegion) {
    const std::string text = R"(
        Correct plates: A123BC, E555EE, K321AM
        Parking spots: M111MM and T444YX
        With trash: A123BC45 -> A123BC
        Almost valid: X999XZ -> invalid (Z)
    )";
    EXPECT_EQ(rus_car_numbers(text), std::vector<std::string>({"A123BC", "E555EE", "K321AM",
                                                               "M111MM", "T444YX", "A123BC"}));
}

TEST(RusCarNumbersTest, InvalidFormats) {
    const std::string text = R"(
        Invalid:
        ABC123 (wrong order)
        123ABC (starts with digits)
        A1B2C3 (alternating)
        A123BC45 (with region, but takes A123BC)
        A12BC (too short)
        Z999ZZ (invalid letter Z)
    )";
    EXPECT_EQ(rus_car_numbers(text), std::vector<std::string>({"A123BC"}));
}

TEST(RusCarNumbersTest, MixedContent) {
    const std::string text = R"(
        Valid: A777BC and C666CT
        Invalid: AB123C, X9Y9Z9
        With region: T123TX42 -> T123TX
        Trash: !Y222YA@
        Almost valid: O999OI -> invalid (I)
    )";
    EXPECT_EQ(rus_car_numbers(text),
              std::vector<std::string>({"A777BC", "C666CT", "T123TX", "Y222YA"}));
}

TEST(RusCarNumbersTest, EdgeCases) {
    const std::string text = R"(
        Edge cases:
        A001AX (minimum)
        X999XX (maximum)
        B000TB (zeros in digits)
        H555HH (same letters)
        Almost valid:
        A000AA0 (extra zero)
        Y123YF (invalid F)
    )";
    EXPECT_EQ(rus_car_numbers(text),
              std::vector<std::string>({"A001AX", "X999XX", "B000TB", "H555HH"}));
}

TEST(RusCarNumbersTest, AllValidLettersCombinations) {
    const std::string text = R"(
        All valid letters:
        A123BC, B456TE, E789KX
        K321AM, M111MO, H555OP
        O999PC, P777CT, C666TY
        T444YX, Y222XA, X888AB
    )";
    EXPECT_EQ(
        rus_car_numbers(text),
        std::vector<std::string>({"A123BC", "B456TE", "E789KX", "K321AM", "M111MO", "H555OP",
                                  "O999PC", "P777CT", "C666TY", "T444YX", "Y222XA", "X888AB"}));
}