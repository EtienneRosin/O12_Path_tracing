// -*- lsst-c++ -*-
/**
 * @file color.hpp
 * @brief Declaration of background functions to color the background of a screen.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

#include "screen.hpp"
#include "color.hpp"

/**
 * @brief Apply a gradient background to the screen.
 * @details This function applies a vertical gradient from a top color to a bottom color.
 *
 * @param screen The screen to which the background will be applied.
 * @param top_color The color at the top of the screen.
 * @param bottom_color The color at the bottom of the screen.
 */
void apply_gradient_background(Screen &screen, const Color &top_color, const Color &bottom_color);

/**
 * @brief Apply an homogeneous color to the screen.
 *
 * @param screen The screen to which the background will be applied.
 * @param color The considered color.
 */
void apply_solid_background(Screen &screen, const Color &color);

/**
 * @brief Apply a repeating pattern (a square) to the screen.
 *
 * @param screen The screen to which the background will be applied.
 * @param color1 The color at the top of the screen.
 * @param color2 The color at the bottom of the screen.
 * @param square_size cziicn
 */
void apply_checkerboard_background(Screen &screen, const Color &color1, const Color &color2, int square_size);

#endif // BACKGROUND_HPP_