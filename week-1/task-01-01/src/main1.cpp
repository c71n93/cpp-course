#include <iostream>

#define foo() main()

int foo() { std::cout << "Hi" << std::endl; }

#define main() bar()

int main() {}  // NOLINT
