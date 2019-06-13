cmake_minimum_required (VERSION 3.5.1)

add_definitions(-std=c++11)

project (moveFileCron_tests)

include_directories(../inc units)

file(GLOB_RECURSE SOURCES "../src/functions.cpp" "tests.cpp" "units/*.cpp")

add_executable(tests ${SOURCES})
