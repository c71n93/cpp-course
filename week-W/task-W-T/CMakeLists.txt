add_executable(task-W-T
    src/main.cpp
)

add_subdirectory(test)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}")
set_target_properties(task-W-T PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
