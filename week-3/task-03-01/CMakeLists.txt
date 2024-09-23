add_executable(task-03-01
    src/main.cpp
)
include_directories(include)
clang_tidy(task-03-01)

add_subdirectory(test)
