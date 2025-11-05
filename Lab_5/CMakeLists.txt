cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDAR 17)
set(CMAKE_CXX_STANDAR_REQUIRED ON)

project(practica_5_1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(bin)
