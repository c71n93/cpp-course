#pragma once

#include <iostream>

namespace functions {

std::function<void(int& p)> do_it(int& param) {
    param++;
    static int counter = 1;
    std::cout << "do it #" << counter << ": param = " << param << std::endl;
    counter++;
    return [](int& p) { do_it(p); };
}

}  // namespace functions
