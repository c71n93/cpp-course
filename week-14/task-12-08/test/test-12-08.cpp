#include "gtest/gtest.h"
#include "tokenize.hpp"

using my_algorithm::tokenize;

TEST(TokenizeTest, HandlesEmptyString) {
    EXPECT_EQ(tokenize("", {' ', ','}), std::vector<std::string>({}));
}

TEST(TokenizeTest, HandlesNoDelimiters) {
    EXPECT_EQ(tokenize("hello", {}), std::vector<std::string>({"hello"}));
}

TEST(TokenizeTest, SingleDelimiterBetweenTokens) {
    EXPECT_EQ(tokenize("a,b,c", {','}), std::vector<std::string>({"a", "b", "c"}));
}

TEST(TokenizeTest, MultipleDelimitersBetweenTokens) {
    EXPECT_EQ(tokenize("hello, world!how?are.you", {' ', ',', '!', '?', '.'}),
              std::vector<std::string>({"hello", "world", "how", "are", "you"}));
}

TEST(TokenizeTest, LeadingAndTrailingDelimiters) {
    EXPECT_EQ(tokenize("  ,,test,,case,,  ", {' ', ','}),
              std::vector<std::string>({"test", "case"}));
}

TEST(TokenizeTest, ConsecutiveDelimiters) {
    EXPECT_EQ(tokenize("a,,  ,b", {',', ' '}), std::vector<std::string>({"a", "b"}));
}

TEST(TokenizeTest, MixedDelimitersAndNoTokens) {
    EXPECT_EQ(tokenize(", , ,", {',', ' '}), std::vector<std::string>({}));
}

TEST(TokenizeTest, ComplexRealWorldCase) {
    EXPECT_EQ(tokenize("  John;Doe,42;New York;USA  ", {' ', ',', ';'}),
              std::vector<std::string>({"John", "Doe", "42", "New", "York", "USA"}));
}