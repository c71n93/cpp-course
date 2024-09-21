cmake_minimum_required(VERSION 3.26)
project(cpp-course)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip # release 1.15.2
)
FetchContent_MakeAvailable(googletest)
enable_testing()

function(cpp_test SOURCE_NAME)
    get_filename_component(TARGET_NAME ${SOURCE_NAME} NAME_WE)
    add_executable(
            ${TARGET_NAME}
            ${SOURCE_NAME}
    )
    target_link_libraries(
            ${TARGET_NAME}
            GTest::gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests(${TARGET_NAME})
endfunction(cpp_test)

set(DIRS week-W week-1)
foreach(DIR ${DIRS})
    add_subdirectory(${DIR})
endforeach()

file(GLOB_RECURSE
        ALL_CXX_SOURCE_FILES
        *.[chi]pp *.[chi]xx *.cc *.hh *.ii *.[CHI]
)
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    add_custom_target(
            clang-format
            COMMAND ${CLANG_FORMAT}
            -i
            -style=file
            ${ALL_CXX_SOURCE_FILES}
    )
endif()
