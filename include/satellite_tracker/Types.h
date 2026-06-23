/**
 * @file Types.h
 * @brief Core data structures shared across the satellite tracker.
 * @author Kyle Kibby
 * @date 2026
 */
#pragma once

#include <string>

/// @brief All satellite information
struct TLEData {
    /// Satellite name (from TLE data)
    std::string name;
    /// First line of the TLE data
    std::string line1;
    /// Second line of the TLE data, containing the orbital parameters
    std::string line2; 

    /// Catalog number of the satellite
    int catalog_number;
    /// Inclination angle of the satellite's orbit (degrees)
    double inclination;
    /// Right ascension of the ascending node (degrees)
    double raan;
    /// Eccentricity of the satellite's orbit (unitless)
    double eccentricity;  
    /// Argument of perigee (degrees)
    double argument_of_perigee; 
    /// Mean anomaly (degrees)
    double mean_anomaly;       
    /// Mean motion (revolutions per day)
    double mean_motion;         
    /// Epoch time of the TLE data
    double epoch_time;          
};

/// @brief Satellite positional information 
struct Position {
    /// Geographic latitude in degrees (-90 to 90)
    double latitude;  
    /// geographic longitude in degrees (-180 to 180)
    double longitude; 
    /// Altitude above Earth's surface in kilometers
    double altitude;  
};
