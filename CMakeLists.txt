﻿# CMakeList.txt : Top-level CMake project file, do global configuration
cmake_minimum_required (VERSION 3.8)

project ("solution")

set(default_build_type "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT WIN32)
	add_definitions(-std=c++17 -Wno-psabi)
else()
	add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
endif()

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    message("Building in DEBUG mode...")
else()
	message("Building in RELEASE mode...")
endif()

# control where the static and shared libraries are built so that on windows we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY, "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# Include sub-projects.
add_subdirectory("Imports/GTestLib")
add_subdirectory ("SolutionLib")
add_subdirectory ("SampleApp")
add_subdirectory("test")


