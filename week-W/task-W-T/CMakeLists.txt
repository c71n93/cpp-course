add_executable(task-W-T
    src/main.cpp
)

add_subdirectory(test)

clang_tidy(task-W-T)
