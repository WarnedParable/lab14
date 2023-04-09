cmake_minimum_required(VERSION 3.24)
project(14labh C)

set(CMAKE_C_STANDARD 11)

include_directories(vector)

link_directories(vector)

add_executable(14labh main.c)

target_link_libraries(${PROJECT_NAME} vector)