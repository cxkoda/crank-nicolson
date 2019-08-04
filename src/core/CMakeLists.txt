cmake_minimum_required(VERSION 3.13)

add_library(core STATIC
  grid.cpp
)

target_include_directories(core PRIVATE .)
