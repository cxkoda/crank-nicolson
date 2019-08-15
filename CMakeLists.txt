cmake_minimum_required(VERSION 3.1)

# PROJECT'S NAME
project(crank CXX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# Testing

#option(PACKAGE_TESTS "Build the tests" ON)
#if(PACKAGE_TESTS)
#    enable_testing()
#    add_subdirectory(tests)
#endif()

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest")

enable_testing()

add_subdirectory(core)
add_subdirectory(application)