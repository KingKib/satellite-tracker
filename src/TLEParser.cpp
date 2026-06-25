/**
 * @file TLEParser.cpp
 * @brief Implementation of the TLEParser class.
 * @author Kyle Kibby
 * @date 2026
 */

#include <string>
#include <stdexcept>
#include "satellite_tracker/TLEParser.h"

    
TLEData TLEParser::parse_record(
    const std::string& name,
    const std::string& line1,
    const std::string& line2)
{
    if (line1[0] != '1' || line2[0] != '2')
        throw std::invalid_argument("Invalid TLE: line1 must start with '1' and line2 must start with '2'");
    
    TLEData tle;

    tle.name  = name;
    tle.line1 = line1; 
    tle.line2 = line2;
    
    tle.epoch_time          = std::stod(line1.substr(18, 14));
    tle.catalog_number      = std::stoi(line1.substr(2, 5));
    tle.inclination         = std::stod(line2.substr(8, 8));
    tle.raan                = std::stod(line2.substr(17, 8));
    tle.eccentricity        = std::stod(line2.substr(26, 7)) / 10000000.0;
    tle.argument_of_perigee = std::stod(line2.substr(34, 8));
    tle.mean_anomaly        = std::stod(line2.substr(43, 8));
    tle.mean_motion         = std::stod(line2.substr(52, 11));

    return tle;
}


