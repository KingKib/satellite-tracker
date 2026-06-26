```markdown
# SatelliteTracker

A modern C++17 satellite tracking application that parses Two-Line Element (TLE) data and propagates satellite orbits using the SGP4 orbital propagation model.

The project is built with CMake and emphasizes clean architecture, portability, modern C++ practices, and automated testing.

---

## Features

- Parse standard NORAD Two-Line Element (TLE) files
- Propagate satellite orbits using the SGP4 model
- Display real satellite position data
- Cross-platform builds with CMake
- Modern C++17 codebase
- Unit testing with Catch2
- Modular architecture for future expansion

---

## Architecture

The application is organized into three primary components:

### `TLEParser`

Responsible for reading and validating TLE files before constructing satellite objects.

### `Satellite`

Represents a satellite and stores:

- Satellite name
- TLE data
- Orbital information

### `Propagator`

Uses the SGP4 library to compute a satellite's position for a given time.

Overall workflow:

```

TLE File
│
▼
TLEParser
│
▼
Satellite
│
▼
Propagator (SGP4)
│
▼
Position Output

```

---

## Requirements

To build this project, you will need:

- CMake 3.20+
- A C++17 compatible compiler
  - GCC
  - Clang / AppleClang
  - MSVC
- A CMake generator
  - Ninja (recommended)
  - Ninja Multi-Config
  - Visual Studio

---

## Dependencies

External libraries used by the project:

| Library | Purpose |
|---------|---------|
| libsgp4 | SGP4 orbital propagation |
| Catch2 | Unit testing framework |

---

## Project Structure

```

SatelliteTracker/
├── build/
├── external/
│   └── sgp4/
├── include/
│   └── satellite_tracker/
│       ├── Propagator.h
│       ├── Satellite.h
│       ├── TLEParser.h
│       ├── Types.h
│       └── version.h.in
├── src/
│   ├── main.cpp
│   ├── Propagator.cpp
│   ├── Satellite.cpp
│   ├── TLEParser.cpp
│   └── CMakeLists.txt
├── tests/
│   ├── test_main.cpp
│   └── CMakeLists.txt
├── CMakeLists.txt
├── CMakePresets.json
├── README.md
└── .gitignore

````

---

## Building

### Clone the Repository

```bash
git clone https://github.com/KingKib/satellite-tracker.git
cd satellite-tracker
git submodule update --init --recursive
```

### Configure

Using Ninja (recommended):

```bash
cmake --preset ninja-debug
````

Default generator:

```bash
cmake -S . -B build
```

---

### Build

Using Ninja:

```bash
cmake --build --preset ninja-debug
```

Default generator:

```bash
cmake --build build
```

---

## Running

### Ninja

Windows

```powershell
.\build\ninja-debug\src\satellite_tracker.exe
```

Linux/macOS

```bash
./build/ninja-debug/src/satellite_tracker
```

### Default Build

Windows

```powershell
.\build\src\satellite_tracker.exe
```

Linux/macOS

```bash
./build/src/satellite_tracker
```

---

## Example Output

```text
=== Satellite Tracker v0.1.0 ===
Loading ISS TLE data...
Satellite: ISS (ZARYA) orbital parameters
Inclination: 51.6400
Right Ascension of The Ascending Node: 0.0000
Eccentricity: 0.0001
Argument of Perigee: 0.0000
Mean Anomaly: 0.0000
Mean Motion: 15.5000
Epoch Time: 24001.0000
Position - Lat: -0.0775 Lon: -0.0614 Alt: 423.9351
```

*(Example values shown for illustration.)*

---

## Testing

Configure the project with testing enabled and build:

```bash
cmake --build --preset ninja-debug
```

Run all tests:

```bash
ctest --test-dir build/ninja-debug --output-on-failure
```

Or execute the test binary directly:

```bash
./build/ninja-debug/tests/satellite_tracker_tests
```

---

## Version

Current version:

**0.1.0**

The project version is automatically derived from the `project()` declaration in the top-level `CMakeLists.txt`.

---

## Built With

* C++17
* CMake
* Ninja
* Clang / GCC / MSVC
* SGP4 orbital propagation
* libsgp4
* Catch2
