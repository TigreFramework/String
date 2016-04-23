cmake_minimum_required(VERSION 3.4)
project(String)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcryptopp")
include_directories(${root_SOURCE_DIR}/include/cryptopp563)
set(SOURCE_FILES main.cpp String.cpp String.h libcryptopp.a)
add_executable(String ${SOURCE_FILES})