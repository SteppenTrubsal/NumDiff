cmake_minimum_required(VERSION 3.28.0)
project(NumDiff VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES "src/*.hpp")

add_executable(NumDiff ${SOURCES} "src/NumDiff.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NumDiff PROPERTY CXX_STANDARD 20)
endif()