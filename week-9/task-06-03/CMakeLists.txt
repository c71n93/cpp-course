add_library(entity)
target_sources(entity
    PUBLIC
        FILE_SET CXX_MODULES FILES
        src/entity.cppm
)

add_executable(task-06-03
        src/main.cpp
)
target_link_libraries(task-06-03 PRIVATE entity)

# clang_tidy(task-06-03) clang-tidy 18.1.8 does not support modules!
