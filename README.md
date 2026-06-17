# SatelliteTracker
A C++17 satellite tracking application built with CMake.
This project is currently in early development (v0.1.0).

## Overview
Satellite tracker is a C++ application designed to demonstrate modern CMake-based project structure, compiler, portability, and clean build configuration practices.

## Requirements
To build this project, you need the following:

- CMake 3.20+
- A C++17 compatible compiler
    - GCC
    - Clang/AppleClang
    - MSVC
- A CMake generator
    - Ninja
    - Ninja Multi Config
    - VSC Multi Config

## Project Structure
satellite-tracker/
    build/
    external/
    include/
        satellite_tracker/
            version.h.in
    src/
        CMakeLists.txt
        main.cpp
    tests/
        CMakeLists.txt
        test_main.cpp
    .gitignore
    CMakeLists.txt
    CMakePresets.json
    README.md

## Build Instructions
1. Configure the project

Using Ninja (Recommended):
cmake --preset ninja-debug

Using default:
cmake -S . -B build

2. Build the project

Using Ninja: 
cmake --build --preset ninja-debug

Using default:
cmake --build build

3. Run the program

Using ninja (Windows)
.\build\ninja-debug\src\satellite_tracker.exe

Using ninja (Linux/macOS)
.\build\ninja-debug\src\satellite_tracker

Using default (Windows)
.\build\src\satellite_tracker.exe

Using default (Linux/macOS)
.\build\src\satellite_tracker

### Expected Output
=== Satellite Tracker v0.1.0 ===
System initialized. No TLEs loaded.

## Version
Current version: 0.1.0
Version is automatically derived from the CMakeLists.txt project() declaration.

## Built With
C++17 | CMake 4.3 | Ninja | Clang
