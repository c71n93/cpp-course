#pragma once

#include <iostream>

namespace functions {

/**
 * function returns itself.
 */
std::function<void(int& p)> do_it(int& param) {
    param++;
    static int counter = 1;
    std::cout << "do it #" << counter << ": param = " << param << std::endl;
    counter++;
    return [](int& p) { do_it(p); };
}

void* foo();
template <auto F>
void* addressF() {
    return reinterpret_cast<void*>(F);
}
/**
 * function returns pointer to itself.
 */
void* foo() { return addressF<foo>(); }

}  // namespace functions
