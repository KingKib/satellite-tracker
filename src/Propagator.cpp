/**
 * @file Propagator.cpp
 * @brief Implementation of Propagator class
 * @author Kyle Kibby
 * @date 2026
 */

#include "satellite_tracker/Propagator.h"

Propagator::Propagator(std::shared_ptr<const Satellite> satellite)
    : satellite_(satellite)
{
}

Position Propagator::propagate(double minutes_since_epoch) const
{
    return Position{0.0, 0.0, 0.0};
}
