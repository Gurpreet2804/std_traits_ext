#
# std_tarits_ext
#

cmake_minimum_required(VERSION 3.2)

#
# Building in-tree is not allowed (we take care of your craziness).
#
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the source code and call cmake from there. Thank you.")
endif()

#
# Messags
#

message(VERBOSE "*")
message(VERBOSE "* ${PROJECT_NAME} v${PROJECT_VERSION}")
message(VERBOSE "* Copyright (c) Gurpreet Singh <gurpreet2804@gmail.com>")
message(VERBOSE "*")

project(std_tarits_ext VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include(CTest)
enable_testing()

#
# CMake configuration
#
set(PROJECT_CMAKE_MODULES cmake/modules)
set(PROJECT_DEPS_DIR deps)
set(PROJECT_TEST_DIR test)

set(PROJECT_RUNTIME_OUTPUT_DIRECTORY bin)

set(
    CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}/${PROJECT_CMAKE_MODULES}
)

#find_package(Threads REQUIRED)
find_package(GoogleTest REQUIRED)


if(${GOOGLETEST_FOUND})
    add_subdirectory(${PROJECT_TEST_DIR})
endif(${GOOGLETEST_FOUND})

add_executable(std_tarits_ext main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
