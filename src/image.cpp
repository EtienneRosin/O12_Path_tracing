// -*- lsst-c++ -*-
/**
 * @file color.hpp
 * @brief Implementation of the Image class.
 *
 * @details This file contains the implementation of an Image class which inherits
 * from Color, as well as functions to manipulate it.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */

#include "image.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
// #include <sstream>
#include <iomanip>

// Constructor that initializes the image with a specific width and height.
// All pixels are set to black by default (Color(0, 0, 0)).
Image::Image(int w, int h) : width(w), height(h), pixels(h, std::vector<Color>(w, Color(0.0, 0.0, 0.0))) {}

// Method to check if the given (x, y) coordinates are valid for the image.
bool Image::valid_pixel(int x, int y) const
{
    return (x >= 0 && x < width) && (y >= 0 && y < height);
}

// Method to set a pixel at (x, y) to a specific color. If (x, y) is out of bounds, no operation is performed.
void Image::set_pixel(int x, int y, const Color &color)
{
    if (valid_pixel(x, y))
    {
        pixels[y][x] = color; // Access the pixel at (x, y) and set it to the new color.
    }
    else
    {
        std::cerr << "Error: Attempt to set a pixel out of bounds (" << x << ", " << y << ")\n";
    }
}

// Method to get the color of the pixel at (x, y). If (x, y) is out of bounds, return black (Color(0, 0, 0)).
Color Image::get_pixel(int x, int y) const
{
    if (valid_pixel(x, y))
    {
        return pixels[y][x]; // Return the color of the pixel at (x, y).
    }
    else
    {
        std::cerr << "Error: Attempt to access a pixel out of bounds (" << x << ", " << y << ")\n";
        return Color(0.0, 0.0, 0.0); // Return black if the pixel is out of bounds.
    }
}

// Method to save the image to a file in PPM format (P3).
void Image::save_as_ppm(const std::string &filename) const
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    // Write the PPM header
    file << "P3\n";                         // PPM type (P3 is plain text format)
    file << width << " " << height << "\n"; // Image dimensions
    file << "255\n";                        // Maximum color value (255 for 8-bit colors)

    // Write pixel data
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            Color color = get_pixel(x, y).as_bytes(); // Convert color to byte representation
            file << color.r() << " "
                 << color.g() << " "
                 << color.b() << " ";
        }
        file << "\n"; // End of line for each row
    }

    file.close();
}