# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(multithreaded_observer)

# Directory googletest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest")

# Option
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-promo
        -Wno-deprecated-declarations
    )
endif()

# Source files
set(SOURCES
    source/main.cpp
    include/observer.h
)

# Source test files
set(TEST_SOURCES
    test/observer_test.cpp
    include/observer.h
)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})

if(UNIX)
    find_package(Threads)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
endif()

# Link target
target_link_libraries(${PROJECT_NAME})
target_link_libraries(
    ${PROJECT_NAME}_test
    gtest
    gtest_main
)