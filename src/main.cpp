/**
 * @file main.cpp
 * @brief Main entry point for the Satellite Tracker application.
 * @author Kyle Kibby
 * @date 17-06-2026
 */

#include <iostream>
#include "satellite_tracker/version.h" // Includes the generated version header file, which contains version information defined in CMakeLists.txt.

int main() {
    std::cout << "=== Satellite Tracker v" << SATELLITE_TRACKER_VERSION << " ===\n";
    std::cout << "System initialized. No TLEs loaded.\n";
    return 0;
}
