add_executable(task-02-03
    src/main.cpp
)
include_directories(include)
clang_tidy(task-02-03)

add_subdirectory(test)
