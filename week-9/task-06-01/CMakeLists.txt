add_executable(task-06-01
        src/entity.cpp
        src/main.cpp
)
include_directories(include)
clang_tidy(task-06-01)