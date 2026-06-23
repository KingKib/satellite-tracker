/**
 * @file TLEParser.h
 * @brief Declaration of the TLEParser class.
 * 
 * The TLEParser class provides a static method to parse TLE data
 * from its raw string format into a structured TLEData object.
 * 
 * @author Kyle Kibby
 * @date 2026
 */
#pragma once

#include <string>
#include <stdexcept>

#include "satellite_tracker/Types.h"

/**
 * @class TLEParser
 * @brief Utility class for parsing raw Two-Line Element (TLE) strings into TLEData structs.
 *
 * All methods are static. This class is never instantiated.
 */
class TLEParser {
public:
    /**
     * @brief Parses a three-line TLE record into a TLEData struct.
     *
     * Validates that line1 begins with '1' and line2 begins with '2',
     * then extracts orbital elements from fixed-width fields.
     *
     * @param name  The satellite name (line 0 of a TLE file).
     * @param line1 The first TLE line, beginning with '1'.
     * @param line2 The second TLE line, beginning with '2'.
     * @return A populated TLEData struct.
     * @throws std::invalid_argument if line1 or line2 fail validation.
     */
    static TLEData parse_record(
        const std::string& name,
        const std::string& line1,
        const std::string& line2);
};
