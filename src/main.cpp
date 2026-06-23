/**
 * @file main.cpp
 * @brief Main entry point for the Satellite Tracker application.
 * @author Kyle Kibby
 * @date 17-06-2026
 */

#include <iostream>
#include "satellite_tracker/version.h" // Includes the generated version header file, which contains version information defined in CMakeLists.txt.
#include "satellite_tracker/Satellite.h"

int main() {
    std::cout << "=== Satellite Tracker v" << SATELLITE_TRACKER_VERSION << " ===\n";
    std::cout << "Loading ISS TLE data...\n";

    TLEData iss_data;

    iss_data.name = "ISS (ZARYA)";
    iss_data.line1 = "1 25544U 98067A   24001.00000000  .00000000  00000-0  00000-0 0  9999";
    iss_data.line2 = "2 25544  51.6400 000.0000 0001000 000.0000 000.0000 15.50000000000000";
    iss_data.inclination = 51.64;
    iss_data.raan = 0.0;
    iss_data.eccentricity = 0.0001;
    iss_data.argument_of_perigee = 0.0;
    iss_data.mean_anomaly = 0.0;
    iss_data.mean_motion = 15.5;
    iss_data.epoch_time = 24001.0;
    iss_data.catalog_number = 25544;


    Satellite iss(iss_data);
    iss.print();

    return 0;
}
