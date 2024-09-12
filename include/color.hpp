// -*- lsst-c++ -*-
/**
 * @file color.hpp
 * @brief Declaration of the Color class.
 *
 * @details This file contains the declaration of a color class ('Color') which inherits
 * from Vec3, as well as functions to manipulate it.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef COLOR_HPP_
#define COLOR_HPP_

#include "vec3.hpp"

class Color : public Vec3
{
public:
    /**
     * @brief Constructor with RGB values.
     * @details Initializes the color with red, green, and blue components.
     * The values should be in the range [0, 1].
     *
     * @param r Red component of the color (0.0 to 1.0).
     * @param g Green component of the color (0.0 to 1.0).
     * @param b Blue component of the color (0.0 to 1.0).
     */
    Color(float r, float g, float b) : Vec3(r, g, b) {}

    /**
     * @brief Default constructor.
     * @details Initializes the color to black (0.0, 0.0, 0.0).
     */
    Color() : Vec3(0.0, 0.0, 0.0) {}

    Color(const Vec3 &v) : Vec3(v) {} // Constructor to initialize from Vec3

    /**
     * @brief Get the red component.
     * @details Returns the red component of the color.
     *
     * @return The red component as a float in the range [0, 1].
     */
    float r() const { return x(); }

    /**
     * @brief Get the green component.
     * @details Returns the green component of the color.
     *
     * @return The green component as a float in the range [0, 1].
     */
    float g() const { return y(); }

    /**
     * @brief Get the blue component.
     * @details Returns the blue component of the color.
     *
     * @return The blue component as a float in the range [0, 1].
     */
    float b() const { return z(); }

    /**
     * @brief Convert the Color components from float to byte.
     * @details It clamps the component values within the range [0, 255].
     *
     * @return The color in bytes.
     */
    Color as_bytes() const;
};

#endif