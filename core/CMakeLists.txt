cmake_minimum_required(VERSION 2.8)

#project(core)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(core STATIC ${SRC_FILES})
target_include_directories(core PUBLIC ./include)

add_subdirectory(tests)