/**
 * @file Propagator.cpp
 * @brief Implementation of Propagator class
 * @author Kyle Kibby
 * @date 2026
 */

#include "satellite_tracker/Propagator.h"
#include <Tle.h>
#include <SGP4.h>
#include <cmath>

Propagator::Propagator(std::shared_ptr<const Satellite> satellite)
    : satellite_(satellite)
{
}

Position Propagator::propagate(double minutes_since_epoch) const
{
    const TLEData& tle_data = satellite_->get_tle_data();

    libsgp4::Tle tle(tle_data.name, tle_data.line1, tle_data.line2);
    libsgp4::SGP4 sgp4(tle);
    libsgp4::Eci eci = sgp4.FindPosition(minutes_since_epoch);

    libsgp4::Vector position = eci.Position();

    constexpr double PI = 3.14159265358979323846;
    constexpr double EARTH_RADIUS_KM = 6371.0;
    double r = std::sqrt(position.x * position.x + position.y * position.y + position.z * position.z);
    double altitude = r - EARTH_RADIUS_KM;
    double latitude = std::asin(position.z / r) * (180.0 / PI);
    double longitude = std::atan2(position.y, position.x) * (180.0 / PI);

    return Position{latitude, longitude, altitude};
}
