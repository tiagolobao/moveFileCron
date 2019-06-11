cmake_minimum_required (VERSION 3.10.2)

project (moveFileCron)

include_directories(inc)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(mvc ${SOURCES})
