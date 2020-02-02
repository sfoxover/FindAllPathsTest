# CMakeList.txt : Top-level CMake project file, do global configuration
cmake_minimum_required (VERSION 3.8)

set(APP_NAME "SampleCode")

file(GLOB_RECURSE EXE_SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.hpp include/*.hpp)

# Silence C++ 17 deprication warning
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Add source to this project's executable.
add_executable (${APP_NAME} ${EXE_SOURCE_FILES})

target_link_libraries(${APP_NAME} SolutionLib)

target_include_directories(${APP_NAME} PUBLIC include PRIVATE src)


