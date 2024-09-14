// -*- lsst-c++ -*-
/**
 * @file color.hpp
 * @brief Declaration of the Image class.
 *
 * @details This file contains the declaration of an Image class which inherits
 * from Color, as well as functions to manipulate it.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "color.hpp"
#include <vector>

class Image
{
private:
    int width;                              // Width of the image
    int height;                             // Height of the image
    std::vector<std::vector<Color>> pixels; // 2D array of Color objects representing the image

public:
    /**
     * @brief Constructor for an image of given width and height.
     * @details Initializes all pixels to black (Color(0, 0, 0)).
     *
     * @param w The width of the image.
     * @param h The height of the image.
     */
    Image(int w, int h);

    /**
     * @brief Get the width of the image.
     * @return The width of the image.
     */
    int get_width() const { return width; }

    /**
     * @brief Get the height of the image.
     * @return The height of the image.
     */
    int get_height() const { return height; }

    /**
     * @brief Checks if the pixel coordinates (x, y) are valid.
     *
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return True if the pixel is within the image boundaries, false otherwise.
     */
    bool valid_pixel(int x, int y) const;

    /**
     * @brief Set a pixel at a specific (x, y) position.
     * @details Replaces the pixel at the given coordinates with a new Color value.
     *
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @param color The new Color to set at the pixel.
     */
    void set_pixel(int x, int y, const Color &color);

    /**
     * @brief Get the pixel color at a specific (x, y) position.
     * @details Returns the Color of the pixel at the given coordinates.
     *
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return The Color of the pixel at (x, y).
     */
    Color get_pixel(int x, int y) const;

    /**
     * @brief Save the image to a file in PPM format.
     * @details This method writes the image data to a file in plain text PPM format (P3).
     *
     * @param filename The name of the file where the image will be saved.
     * @throws std::runtime_error if there is an issue with file creation or writing.
     */
    void save_as_ppm(const std::string &filename) const;
};

#endif // IMAGE_HPP_