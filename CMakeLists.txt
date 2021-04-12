# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(multithreaded_observer)

# Directory googletest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest")

# Options
set(CMAKE_CXX_STANDARD 17)

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
    test/source/observer_test.cpp
    include/observer.h
)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

if(UNIX)
    find_package(Threads)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
endif()

if(TEST)
    add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})
    target_link_libraries(${PROJECT_NAME}_test
        gtest
        gtest_main
    )
endif()