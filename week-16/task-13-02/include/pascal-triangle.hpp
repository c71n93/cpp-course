#pragma once

#include <iomanip>

class PascalsTriangle {
public:
    explicit PascalsTriangle(size_t n) : n_(n) {}

    void print(std::ostream& out) {
        if (n_ == 0) {
            return;
        }
        if (!calculated_) {
            triangle_ = calculate(n_);
            calculated_ = true;
        }
        const size_t max_width = num_digits(max_value(triangle_));
        for (int i = 0; i < n_; ++i) {
            out << std::string((n_ - i - 1) * (max_width + 1) / 2, ' ');
            for (const int num : triangle_[i]) {
                out << std::setw(max_width) << num << ' ';
            }
            out << '\n';
        }
    }

private:
    static std::vector<std::vector<int>> calculate(size_t n) {
        std::vector<std::vector<int>> triangle(n);
        for (int i = 0; i < n; ++i) {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
    static int max_value(const std::vector<std::vector<int>>& triangle) {
        return triangle.back()[triangle.back().size() / 2];
    }
    static size_t num_digits(int num) {
        size_t res = 0;
        while (num > 0) {
            num /= 10;
            res += 1;
        }
        return res;
    }

    size_t n_;
    bool calculated_ = false;
    std::vector<std::vector<int>> triangle_;
};
