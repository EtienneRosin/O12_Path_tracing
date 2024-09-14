// -*- lsst-c++ -*-
/**
 * @file color.hpp
 * @brief Implementation of background functions to color the background of a screen.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */

#include "background.hpp"

// Apply a gradient background to the screen.
void apply_gradient_background(Screen &screen, const Color &top_color, const Color &bottom_color)
{
    for (int j = 0; j < screen.height_resolution; ++j)
    {
        // Calculate the interpolation factor based on the vertical position
        float t = static_cast<float>(j) / static_cast<float>(screen.height_resolution - 1);

        // Interpolate between the top and bottom colors
        Color blended_color = top_color * (1.0f - t) + bottom_color * t;

        // Set the blended color to the row of pixels
        for (int i = 0; i < screen.width_resolution; ++i)
        {
            screen.color_pixel(i, j, blended_color);
        }
    }
};

// Apply an homogeneous color to the screen.
void apply_solid_background(Screen &screen, const Color &color)
{
    for (int j = 0; j < screen.height_resolution; ++j)
    {
        for (int i = 0; i < screen.width_resolution; ++i)
        {
            screen.color_pixel(i, j, color);
        }
    }
};

// Apply a repeating pattern (a square) to the screen.
void apply_checkerboard_background(Screen &screen, const Color &color1, const Color &color2, int square_size)
{
    for (int j = 0; j < screen.height_resolution; ++j)
    {
        for (int i = 0; i < screen.width_resolution; ++i)
        {
            bool is_color1 = ((i / square_size) % 2 == (j / square_size) % 2);
            screen.color_pixel(i, j, is_color1 ? color1 : color2);
        }
    }
};