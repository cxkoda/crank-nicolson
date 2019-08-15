cmake_minimum_required(VERSION 2.6)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(coreTests ${SRC_FILES})
target_link_libraries(coreTests gtest gtest_main core)

add_test(NAME coreTests COMMAND coreTests)