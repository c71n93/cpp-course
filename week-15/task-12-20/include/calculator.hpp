#pragma once

#include <cassert>
#include <sstream>
#include <stack>

inline bool is_operator(const std::string& str) {
    if (str.size() != 1) {
        return false;
    }
    const char c = str[0];
    return c == '+' || c == '-' || c == '*' || c == '/';
}

inline bool may_be_number(const std::string& str) {
    return (str[0] == '-' && str.size() > 1) || static_cast<bool>(std::isdigit(str[0]));
}

double calculate(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("empty string");
    }
    std::stack<double> stack;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token) {
        assert(!token.empty());
        if (may_be_number(token)) {
            stack.push(std::stod(token));
        } else if (is_operator(token)) {
            if (stack.size() < 2) {
                throw std::invalid_argument("too few arguments for operation");
            }
            const double b = stack.top();
            stack.pop();
            const double a = stack.top();
            stack.pop();
            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    throw std::invalid_argument("unexpected operator");
            }
        } else {
            throw std::invalid_argument("unexpected token");
        }
    }
    return stack.top();
}
