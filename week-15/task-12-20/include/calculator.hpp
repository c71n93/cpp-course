#pragma once

#include <stack>
#include <sstream>

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate(const std::string& str) {
    std::stack<int> stack;
    for (auto it = std::cbegin(str); it != std::cend(str);) {
        if (static_cast<bool>(std::isspace(*it))) {
            while (it != std::cend(str) && static_cast<bool>(std::isspace(*it))) { ++it; }
        } else if (static_cast<bool>(std::isdigit(*it))) {
            std::istringstream iss(std::string(it, std::cend(str)));
            int val;
            iss >> val;
            stack.push(val);
            std::advance(it, iss.tellg());
        } else if (is_operator(*it)) {
            const int b = stack.top(); stack.pop();
            const int a = stack.top(); stack.pop();
            switch (*it) {
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
                    throw std::runtime_error("unexpected operator");
            }
            ++it;
        } else {
            throw std::runtime_error("unexpected symbol");
        }
    }
    return stack.top();
}
