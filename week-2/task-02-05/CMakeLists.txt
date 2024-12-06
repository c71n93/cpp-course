add_executable(task-02-05
    src/main.cpp
)
include_directories(include)
clang_tidy(task-02-05)

add_subdirectory(test)
