#pragma once

#include <filesystem>
#include <fstream>

#include "text.hpp"

namespace text {

/**
 * Concrete text that is content from file.
 */
class TextFromFile {
public:
    explicit TextFromFile(const std::filesystem::path& path) : path_(path) {}

    std::string content() const {
        // "Best way" of reading from file
        // (check https://gist.github.com/klmr/849cbb0c6e872dff0fdcc54787a66103)
        auto file = std::ifstream{path_};
        if (!file.is_open()) {
            throw std::invalid_argument("Can't open file with path '" + path_.string() + "'");
        }
        constexpr auto read_size = std::size_t{4096};
        file.exceptions(std::ios_base::badbit);
        auto out = std::string{};
        auto buf = std::string(read_size, '\0');
        while (file.read(buf.data(), read_size)) {
            out.append(buf, 0, file.gcount());
        }
        out.append(buf, 0, file.gcount());
        return out;
    }

private:
    std::filesystem::path path_;
};

}  // namespace text
