// -*- lsst-c++ -*-
/**
 * @file color.cpp
 * @brief Implementation of the Color class.
 *
 * @details This file contains the implementation of an Image class which inherits
 * from Color, as well as functions to manipulate it.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#include "color.hpp"

Color Color::as_bytes() const
{
    return Color(
        static_cast<int>(std::clamp(r() * 255.0, 0.0, 255.0)),
        static_cast<int>(std::clamp(g() * 255.0, 0.0, 255.0)),
        static_cast<int>(std::clamp(b() * 255.0, 0.0, 255.0)));
};
