cmake_minimum_required(VERSION 3.1)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(coreTests ${SRC_FILES})
target_link_libraries(coreTests gtest gtest_main core)

set_target_properties(coreTests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_test(NAME coreTests COMMAND coreTests)