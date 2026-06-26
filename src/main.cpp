/**
 * @file main.cpp
 * @brief Main entry point for the Satellite Tracker application.
 * @author Kyle Kibby
 * @date 17-06-2026
 */

#include <iostream>
#include <memory>
#include "satellite_tracker/version.h" // Includes the generated version header file, which contains version information defined in CMakeLists.txt.
#include "satellite_tracker/Satellite.h"
#include "satellite_tracker/TLEParser.h"
#include "satellite_tracker/Propagator.h"

int main() {
    std::cout << "=== Satellite Tracker v" << SATELLITE_TRACKER_VERSION << " ===\n";
    std::cout << "Loading ISS TLE data...\n";

    const std::string name = "ISS (ZARYA)";
    const std::string line1 = "1 25544U 98067A   24001.00000000  .00000000  00000-0  00000-0 0  9999";
    const std::string line2 = "2 25544  51.6400 000.0000 0001000 000.0000 000.0000 15.50000000000000";

    TLEData iss_data = TLEParser::parse_record(name, line1, line2);

    auto iss = std::make_shared<Satellite>(iss_data);
    iss->print();

    Propagator propagator(iss);
    Position pos = propagator.propagate(0.0);

    std::cout << "Position - Lat: " << pos.latitude
              << " Lon: " << pos.longitude
              << " Alt: " << pos.altitude << '\n';

    return 0;
}
