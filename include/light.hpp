// -*- lsst-c++ -*-
/**
 * @file light.hpp
 * @brief Implementation of a Light struct that represents a light in the world.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "vec3.hpp"
#include "color.hpp"

struct Light
{
public:
    Vec3 position;
    Color color;

    /**
     * @brief Value constructor with source and direction.
     * @param pos position of the light.
     * @param col color of the light.
     */
    Light(const Vec3 &pos, const Color &col);
};

#endif // LIGHT_HPP_