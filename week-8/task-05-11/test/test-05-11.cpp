#include "capitalized_text.hpp"
#include "gtest/gtest.h"
#include "text_from_file.hpp"
#include "text_from_string.hpp"
#include "trimmed_text.hpp"

namespace fs = std::filesystem;
using text::CapitalizedText;
using text::Text;
using text::TextFromFile;
using text::TextFromString;
using text::TrimmedText;

fs::path create_temp_file(const std::string& content) {
    fs::path temp_path = fs::temp_directory_path() / fs::path("tmp.txt");
    std::ofstream temp_file(temp_path);
    temp_file << content;
    temp_file.close();
    return temp_path;
}

#define TURN_OFF_TEMPFILE_TESTS

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(TextFromFileTest, ReadsFileSuccessfully) {
    const std::string content = "Hello, world!";
    const fs::path temp_file = create_temp_file(content);
    const TextFromFile text(temp_file);
    const std::string result = text.content();
    EXPECT_EQ(result, content);
    fs::remove(temp_file);
}
#endif

TEST(TextFromFileTest, ThrowsExceptionForNonExistentFile) {
    const fs::path non_existent_file = "non_existent_file.txt";
    EXPECT_THROW(
        {
            const TextFromFile text(non_existent_file);
            text.content();
        },
        std::invalid_argument);
}

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(TextFromFileTest, HandlesEmptyFile) {
    const fs::path temp_file = create_temp_file("");
    const TextFromFile text(temp_file);
    const std::string result = text.content();
    EXPECT_EQ(result, "");
    fs::remove(temp_file);
}
#endif

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(TextFromFileTest, ReadsMultilineFile) {
    const std::string content = "First line\nSecond line\nThird line";
    const fs::path temp_file = create_temp_file(content);
    const TextFromFile text(temp_file);
    const std::string result = text.content();
    EXPECT_EQ(result, content);
    fs::remove(temp_file);
}
#endif

TEST(CapitalizedTextTest, CapitalizedTextFromString) {
    const std::string content = "Hello, world!";
    const CapitalizedText text(TextFromString{content});
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(CapitalizedTextTest, CapitalizedTextFromFileText) {
    const std::string content = "Hello, world!";
    const fs::path temp_file = create_temp_file(content);
    const CapitalizedText text(TextFromFile{temp_file});
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}
#endif

TEST(TrimmedTextTest, TrimmedTextFromString) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const TrimmedText text(TextFromString{content});
    const std::string result = text.content();
    EXPECT_EQ(result, "Hello, world!");
}

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(TrimmedTextTest, TrimmedTextFromFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const TrimmedText text(TextFromFile{temp_file});
    const std::string result = text.content();
    EXPECT_EQ(result, "Hello, world!");
    fs::remove(temp_file);
}
#endif

TEST(EleganceTest, CapitalizedTrimmedTextFromString) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const Text& text = CapitalizedText{TrimmedText{TextFromString{content}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(EleganceTest, CapitalizedTrimmedTextFromFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const Text& text = CapitalizedText{TrimmedText{TextFromFile{temp_file}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}
#endif

TEST(EleganceTest, TrimmedCapitalizedTextFromString) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const Text& text = TrimmedText{CapitalizedText{TextFromString{content}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(EleganceTest, TrimmedCapitalizedTextFromFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const Text& text = TrimmedText{CapitalizedText{TextFromFile{temp_file}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}
#endif

TEST(EleganceTest, DecoratorOfAbstractStringText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    std::unique_ptr<Text> txt1 = std::make_unique<TextFromString>(content);
    std::unique_ptr<Text> txt2 = std::make_unique<CapitalizedText>(std::move(txt1));
    const Text& text = TrimmedText{std::move(txt2)};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

#ifndef TURN_OFF_TEMPFILE_TESTS
TEST(EleganceTest, DecoratorOfAbstractFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    std::unique_ptr<Text> txt1 = std::make_unique<TextFromFile>(temp_file);
    std::unique_ptr<Text> txt2 = std::make_unique<CapitalizedText>(std::move(txt1));
    const Text& text = TrimmedText{std::move(txt2)};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}
#endif
