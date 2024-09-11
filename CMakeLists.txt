cmake_minimum_required(VERSION 3.10)
project(PathfindingProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)

# Define the executable
add_executable(pathfinding_project
    src/grid.cpp
    src/pathfinding.cpp
    src/agent.cpp
    src/main.cpp
)
