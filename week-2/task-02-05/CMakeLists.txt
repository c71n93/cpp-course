add_executable(task-02-05
    src/main.cpp
)

include_directories(include)

add_subdirectory(test)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}")
set_target_properties(task-02-05 PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
