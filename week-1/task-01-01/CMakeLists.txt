add_executable(task-01-01-1
        src/main1.cpp
)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}")
set_target_properties(task-01-01-1 PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
