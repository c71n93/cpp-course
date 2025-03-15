#pragma once

namespace functions {

#include <iostream>

int function(int x) { return x; }

using FunctionPtr = decltype(&function);

FunctionPtr intermediary() { return function; }

}  // namespace functions
