cmake_minimum_required(VERSION 3.1)

add_executable(fiddle fiddle.cpp)
target_link_libraries(fiddle core)

set_target_properties(fiddle PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)