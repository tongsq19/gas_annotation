cmake_minimum_required(VERSION 3.8)
project(gas_annotation)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(googletest-release-1.8.1)
include_directories(googletest-release-1.8.1/googletest/include)
include_directories(googletest-release-1.8.1/googlemock/include)

set(SOURCE_FILES main.cpp src/hello.cpp test/test.cpp src/dataType.h src/Register.h src/uility.h)

add_executable(gas_annotation ${SOURCE_FILES})
target_link_libraries(gas_annotation gtest gtest_main)
target_link_libraries(gas_annotation gtest gmock_main)