# CMakeList.txt : Top-level CMake project file, do global configuration
cmake_minimum_required (VERSION 3.8)

set(LIB_NAME "SolutionLib")

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.hpp include/*.hpp)
file(GLOB_RECURSE LIB_HEADERS "src/*.h" "include/*.h")

# Silence C++ 17 deprication warning
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Add source to this project's executable.
add_library(${LIB_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_include_directories(${LIB_NAME} PUBLIC include PUBLIC src)


