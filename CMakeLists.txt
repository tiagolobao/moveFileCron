cmake_minimum_required (VERSION 3.5.1)

add_definitions(-std=c++11)

project (moveFileCron)

include_directories(inc)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(mvc ${SOURCES})
