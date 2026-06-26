/**
 * @file test_main.cpp
 * @brief Test environment for TLEParser
 * @author Kyle Kibby
 * @date 2026
 */

#include <string>
#include <memory>
#include <catch2/catch_test_macros.hpp>
#include "satellite_tracker/TLEParser.h"
#include "satellite_tracker/Propagator.h"

const std::string name = "ISS (ZARYA)";
const std::string line1 = "1 25544U 98067A   24001.00000000  .00000000  00000-0  00000-0 0  9999";
const std::string line2 = "2 25544  51.6400 000.0000 0001000 000.0000 000.0000 15.50000000000000";

TEST_CASE("Valid ISS TLE parses correct orbital elements")
{
    TLEData tle = TLEParser::parse_record(name, line1, line2);
    REQUIRE(tle.eccentricity == 0.0001);
    REQUIRE(tle.inclination == 51.64);
    REQUIRE(tle.mean_motion == 15.5);
    REQUIRE(tle.catalog_number == 25544);
}

TEST_CASE("TLE throws error when wrong line1 is passed")
{
    REQUIRE_THROWS_AS(
        TLEParser::parse_record("ISS", "X 25544...", line2),
        std::invalid_argument
    );
}

TEST_CASE("TLE throws error when wrong line2 is passed")
{
    REQUIRE_THROWS_AS(
        TLEParser::parse_record("ISS", line1, "X 25544..."),
        std::invalid_argument
    );
}

TEST_CASE("Propagator returns non-zero position at t=0")
{
    TLEData tle_data = TLEParser::parse_record(name, line1, line2);
    auto sat = std::make_shared<Satellite>(tle_data);
    Propagator propagator(sat);
    Position pos = propagator.propagate(0.0);

    REQUIRE(pos.altitude != 0.0);
    REQUIRE(pos.altitude > 200.0);   // ISS is never below 200km
    REQUIRE(pos.altitude < 600.0);   // ISS is never above 600km
}

TEST_CASE("Propagator does not exceed range bounds")
{
    TLEData tle_data = TLEParser::parse_record(name, line1, line2);
    auto sat = std::make_shared<Satellite>(tle_data);
    Propagator propagator(sat);
    Position pos = propagator.propagate(0.0);

    REQUIRE(pos.latitude >= -90.0);
    REQUIRE(pos.latitude <= 90.0);
}

TEST_CASE("Propagator correctly produces variable results")
{
    TLEData tle_data = TLEParser::parse_record(name, line1, line2);
    auto sat = std::make_shared<Satellite>(tle_data);
    Propagator propagator(sat);
    Position pos1 = propagator.propagate(0.0);
    Position pos2 = propagator.propagate(90.0);

    REQUIRE(pos1.latitude != pos2.latitude);
}
