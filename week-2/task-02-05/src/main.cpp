#include <iostream>

#include "eulers-num.hpp"

int main() {
    constexpr double eps = 0.1;
    std::cout << "Euler's number with precision " << eps << " equals " << math::eulers_number(eps)
              << std::endl;
    return 0;
}
