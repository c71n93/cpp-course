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

TEST(TextFromFileTest, ReadsFileSuccessfully) {
    const std::string content = "Hello, world!";
    const fs::path temp_file = create_temp_file(content);
    const TextFromFile text(temp_file);
    const std::string result = text.content();
    EXPECT_EQ(result, content);
    fs::remove(temp_file);
}

TEST(TextFromFileTest, ThrowsExceptionForNonExistentFile) {
    const fs::path non_existent_file = "non_existent_file.txt";
    EXPECT_THROW(
        {
            const TextFromFile text(non_existent_file);
            text.content();
        },
        std::invalid_argument);
}

TEST(TextFromFileTest, HandlesEmptyFile) {
    const fs::path temp_file = create_temp_file("");
    const TextFromFile text(temp_file);
    const std::string result = text.content();
    EXPECT_EQ(result, "");
    fs::remove(temp_file);
}

TEST(TextFromFileTest, ReadsMultilineFile) {
    const std::string content = "First line\nSecond line\nThird line";
    const fs::path temp_file = create_temp_file(content);
    const TextFromFile text(temp_file);
    const std::string result = text.content();
    EXPECT_EQ(result, content);
    fs::remove(temp_file);
}

TEST(CapitalizedTextTest, CapitalizedTextFromString) {
    const std::string content = "Hello, world!";
    const CapitalizedText text(TextFromString{content});
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

TEST(CapitalizedTextTest, CapitalizedTextFromFileText) {
    const std::string content = "Hello, world!";
    const fs::path temp_file = create_temp_file(content);
    const CapitalizedText text(TextFromFile{temp_file});
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}

TEST(TrimmedTextTest, TrimmedTextFromString) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const TrimmedText text(TextFromString{content});
    const std::string result = text.content();
    EXPECT_EQ(result, "Hello, world!");
}

TEST(TrimmedTextTest, TrimmedTextFromFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const TrimmedText text(TextFromFile{temp_file});
    const std::string result = text.content();
    EXPECT_EQ(result, "Hello, world!");
    fs::remove(temp_file);
}

TEST(EleganceTest, CapitalizedTrimmedTextFromString) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const Text auto text = CapitalizedText{TrimmedText{TextFromString{content}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

TEST(EleganceTest, CapitalizedTrimmedTextFromFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const Text auto text = CapitalizedText{TrimmedText{TextFromFile{temp_file}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}

TEST(EleganceTest, TrimmedCapitalizedTextFromString) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const Text auto text = TrimmedText{CapitalizedText{TextFromString{content}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
}

TEST(EleganceTest, TrimmedCapitalizedTextFromFileText) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const Text auto text = TrimmedText{CapitalizedText{TextFromFile{temp_file}}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}

TEST(ConstructorTest, ContVariableConstructed) {
    const std::string content = "     \n\t   Hello, world! \t      \n    ";
    const fs::path temp_file = create_temp_file(content);
    const Text auto txt = TextFromFile{temp_file};
    const Text auto text = TrimmedText{CapitalizedText{txt}};
    const std::string result = text.content();
    EXPECT_EQ(result, "HELLO, WORLD!");
    fs::remove(temp_file);
}
