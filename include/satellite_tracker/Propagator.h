/**
 * @file Propagator.h
 * @brief The Propagator class is responsible for calculating the 
 * position of a satellite at a given time based on its TLE data.
 * 
 * @author Kyle Kibby
 * @date 2026
 */
#pragma once

#include <memory>
#include "satellite_tracker/Satellite.h"

class Propagator {
    private:
        std::shared_ptr<const Satellite> satellite_;

    public:
         /**
         * @brief Constructs a Propagator for a given Satellite.
         * @param satellite The satellite for which to propagate position.
         */
        explicit Propagator(std::shared_ptr<const Satellite> satellite);
        /**
         * @brief Propagates the satellite's position based on the time since epoch.
         * @param minutes_since_epoch The time in minutes since the TLE epoch.
         * @return The propagated Position of the satellite.
         */
        Position propagate(double minutes_since_epoch) const;
};


