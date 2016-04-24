cmake_minimum_required(VERSION 3.4)
project(String)
include_directories(./include/cryptopp563/)
link_directories(./include/cryptopp563/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcryptopp")
set(SOURCE_FILES main.cpp String.cpp String.h libcryptopp.a ./include/cryptopp563/rsa.h RsaString.cpp RsaString.h libcryptopp.a)
add_executable(Teste ${SOURCE_FILES})

add_library(RsaString STATIC RsaString.cpp)
add_library(String STATIC String.cpp)