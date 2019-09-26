cmake_minimum_required(VERSION 3.5.1)
project(Vector)

set(CMAKE_CXX_STANDART 11)
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test/src")
set(TEST_DIR_HEADERS "${TEST_DIR}/headers")
set(TEST_DIR_SOURCES "${TEST_DIR}/sources")

add_executable(Vector ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/vector.h)

include_directories(/usr/include/cxxtest)
find_package(CxxTest)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(UnitTest runtest.cpp
        ${TEST_DIR_HEADERS}/testvector.h)

    target_link_libraries(UnitTest
        ${TEST_DIR_SOURCES}/testvector.cpp
        ${CXX_LIBRARIES})
endif()