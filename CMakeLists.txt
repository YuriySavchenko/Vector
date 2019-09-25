cmake_minimum_required(VERSION 3.5)
project(Vector)

set(CMAKE_CXX_STANDART 11)
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

add_executable(Vector ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/vector.h)
