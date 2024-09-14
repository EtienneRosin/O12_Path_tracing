// -*- lsst-c++ -*-
/**
 * @file light.cpp
 * @brief Declaration of a Light class that represents a light in the world.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */

#include "light.hpp"

Light::Light(const Vec3 &pos, const Color &col) : position(pos), color(col)
{
    if (pos.z() > 0)
    {
        std::cerr << "Error: z component of the light should be lesser than 0.\n";
    }
}
