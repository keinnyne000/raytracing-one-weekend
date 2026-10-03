cmake_minimum_required(VERSION 3.20)

project(raytracing_one_weekend LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17) # Sets C++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Stops CMake silently using other version
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Makes a compile_commands.json in build/
set(CMAKE_CXX_EXTENSIONS OFF) # use std=c++17 not -std=gnu++17

# Default to Release: the ray tracer is much slower unoptimized
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

add_executable(row main.cpp)

target_compile_options(row PRIVATE -Wall -Wextra -Wpedantic)
