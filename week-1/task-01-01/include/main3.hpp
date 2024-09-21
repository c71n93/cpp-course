#pragma once

#include <iostream>

class Hi {
public:
    Hi() { std::cout << "Hi" << std::endl; }
};

Hi hello{};
