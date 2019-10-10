cmake_minimum_required (VERSION 2.6)
project (FractalMandelbrot)
# The version number
#set (FractalMandelbrot_VERSION_MAJOR 1)
#set (FractalMandelbrot_VERSION_MINOR 0)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -pedantic -std=c++14")
project(FractalMandelbrot)

#configure a header file to pass some of the CMake settings to the source program
#configure_file {
#"${PROJECT_SOURCE_DIR}/FractalMandelbrotConfig.h.in"
#"${PROJECT_BINARY_DIR}/FractalMandelbrotConfig.h"
#}

# add the binary tree to the search path for include files
# so that we will find FractalMandelbrotConfig.h
#include_directories("$PROJECT_BINARY_DIR")
add_executable(
    main_exe
    shared_ptr.cpp
    main.cpp
    )

