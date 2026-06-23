/**
 * @file Satellite.h
 * @brief Declaration of the Satellite class.
 * 
 * The Satellite class stores a satellite's name and parsed TLE data,
 * and provides accessors and summary-print functionality.
 * 
 * @author Kyle Kibby
 * @date 2026
 */
#pragma once

#include <string>
#include "satellite_tracker/Types.h"

/// @brief Represents a single satellite and its orbital data
class Satellite {
    private:
        TLEData tle_data_;

    public:
        /// @brief Accepts parameter tle_data of type TLEData to be stored internally in Satellite
        /// @param tle_data TlE orbital data used to initialize this satellite
        explicit Satellite(const TLEData& tle_data);
        /// @brief Gets satellite name from input
        /// @return Returns the satellite name as a string constant
        const std::string& get_name() const;
        /// @brief Gets tle data from input
        /// @return A constant reference to this satellite's TLE orbital data
        const TLEData& get_tle_data() const;
        /// @brief prints the name and tle data 
        void print() const;
};
