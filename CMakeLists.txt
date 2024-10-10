cmake_minimum_required(VERSION 3.1) # Specify the minimum CMake version

project(buzzsim) # Define the project name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(TINYXML2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/tinyxml2")
set(EIGEN3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/eigen-3.4.0")

# Add the include directories
include_directories(${TINYXML2_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR})
set(TINYXML2_SRC "${TINYXML2_INCLUDE_DIR}/tinyxml2.cpp")

file(GLOB SOURCES src/*.cpp)

add_executable(RunBuzzsim ${SOURCES} ${TINYXML2_SRC})