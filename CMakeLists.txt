cmake_minimum_required(VERSION 3.1) # Specify the minimum CMake version

project(buzzsim) # Define the project name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(RunBuzzsim ${SOURCES})