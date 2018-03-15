cmake_minimum_required(VERSION 3.4)
project(String)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_TESTING false)

set(TEST_FILES main.cpp String.cpp String.h)
set(STRING_FILES String.cpp String.h)

add_executable(TesteStrings ${TEST_FILES})
add_library(String STATIC ${STRING_FILES})

