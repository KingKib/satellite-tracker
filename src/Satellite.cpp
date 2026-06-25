/**
 * @file Satellite.cpp
 * @brief Implementation of the Satellite class.
 * @author Kyle Kibby
 * @date 2026
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "satellite_tracker/Satellite.h"

Satellite::Satellite(const TLEData& tle_data)
    : tle_data_(tle_data)
{
}

const std::string& Satellite::get_name() const
{
    return tle_data_.name;
}

const TLEData& Satellite::get_tle_data() const
{
    return tle_data_;
}

void Satellite::print() const
{
    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "Satellite: " << tle_data_.name << " orbital parameters" << '\n';
    std::cout << "Inclination: " << tle_data_.inclination << '\n';
    std::cout << "Right Ascension of The Ascending Node: " << tle_data_.raan << '\n';
    std::cout << "Eccentricity: " << tle_data_.eccentricity << '\n';
    std::cout << "Argument of Perigee: " << tle_data_.argument_of_perigee << '\n';
    std::cout << "Mean Anomaly: " << tle_data_.mean_anomaly << '\n';
    std::cout << "Mean Motion: " << tle_data_.mean_motion << '\n';
    std::cout << "Epoch Time: " << tle_data_.epoch_time << '\n';
}
