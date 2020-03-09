cmake_minimum_required(VERSION 2.8.9)
project(dining_ph)
set(CMAKE_BUILD_TYPE Release)

include_directories(inc)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})