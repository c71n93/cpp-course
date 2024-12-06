if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang") # for some reason not working with gcc
    cpp_test(test-05-11.cpp)
endif ()
