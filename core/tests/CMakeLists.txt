cmake_minimum_required(VERSION 2.6)

add_executable(coreTests main.cpp)
target_link_libraries(coreTests gtest gtest_main core)

add_test(NAME coreTests COMMAND coreTests)