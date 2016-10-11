cmake_minimum_required(VERSION 3.4)
project(String)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_TESTING false)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cryptopp)

set(TEST_FILES main.cpp String.cpp String.h RsaString.cpp RsaString.h)
set(STRING_FILES String.cpp String.h RsaString.cpp RsaString.h)
set(RSASTRING_FILES RsaString.cpp RsaString.h)

add_executable(TesteStrings ${TEST_FILES})
add_library(RsaString STATIC ${RSASTRING_FILES})
add_library(String STATIC ${STRING_FILES})

target_link_libraries(TesteStrings cryptopp-static)
target_link_libraries(RsaString cryptopp-static)
target_link_libraries(String cryptopp-static)

