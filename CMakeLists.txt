cmake_minimum_required(VERSION 2.8)

project(ref_copy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

include_directories(inc)

file(
  GLOB_RECURSE
  src_files
  src/*
  )

add_executable(
  ref_copy
  src/main.cpp
  ${src_files}
  )












