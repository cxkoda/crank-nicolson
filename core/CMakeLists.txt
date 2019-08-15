cmake_minimum_required(VERSION 3.1)

#project(core)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(core STATIC ${SRC_FILES})
target_include_directories(core PUBLIC ./include)

set_target_properties(core PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_subdirectory(tests)