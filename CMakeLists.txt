cmake_minimum_required(VERSION 3.10)
project(GenerativeCinema CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source File Compilation Tracking
set(SERVER_SOURCES
    server/src/main.cpp
    server/src/solver_bridge.cpp
    server/src/audio_renderer.cpp
)

# Header Directory Inclusion
include_directories(server/include)

# Executable Output Build Target
add_executable(generative_cinema_server ${SERVER_SOURCES})

# Hardware-level optimization compiler flags for maximum bare-metal throughput
target_compile_options(generative_cinema_server PRIVATE -O3 -Wall -Wextra -pthread)
