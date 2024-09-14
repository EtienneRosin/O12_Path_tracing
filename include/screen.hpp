// -*- lsst-c++ -*-
/**
 * @file screen.hpp
 * @brief Declaration of the Screen class.
 *
 * @details This file contains the declaration of a screen class.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "vec3.hpp"
#include "image.hpp"
#include "ray.hpp"
#include "scene.hpp"
#include "intersection.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>

/**
 * @class Screen
 * @brief Represents a "real world" screen that projects a scene to an image.
 */
class Screen
{
public:
    const float width;                      ///< Width of the screen in world units.
    const float height;                     ///< Height of the screen in world units.
    const int width_resolution;             ///< Number of pixels per screen width.
    const int height_resolution;            ///< Number of pixels per screen height.
    const float pixel_width;                ///< Width of a pixel in world units.
    const float pixel_height;               ///< Height of a pixel in world units.
    std::vector<std::vector<Color>> pixels; ///< 2D array of Color objects representing the image.

    /**
     * @brief Value constructor.
     * @param w Width of the screen in world units.
     * @param h Height of the screen in world units.
     * @param w_res Number of pixels per screen width.
     * @param h_res Number of pixels per screen height.
     */
    Screen(const float w, const float h, const int w_res, const int h_res);

    /**
     * @brief Return if the considered pixel belongs to the screen.
     * @param i x-axis index of the pixel.
     * @param j y-axis index of the pixel.
     *
     * @return true if the pixel belongs to the screen, false otherwise.
     */
    bool valid_pixel(int i, int j) const;

    /**
     * @brief Return the color of the pixel.
     * @param i x-axis index of the pixel.
     * @param j y-axis index of the pixel.
     *
     * @return Color of the pixel.
     */
    Color get_pixel_color(int i, int j) const;

    /**
     * @brief Get the center of the considered pixel.
     * @param i x-axis index of the pixel.
     * @param j y-axis index of the pixel.
     *
     * @return the pixel center.
     */
    Vec3 get_pixel_center(int i, int j);

    /**
     * @brief Get the ray coming from the camera to the pixel center.
     * @param i x-axis index of the pixel.
     * @param j y-axis index of the pixel.
     * @param camera_position position of the camera (considered as a point).
     *
     * @return the pixel center.
     */
    Ray get_ray_passing_through_pixel(int i, int j, const Vec3 &camera_position);

    /**
     * @brief Color the considered pixel.
     * @param i x-axis index of the pixel.
     * @param j y-axis index of the pixel.
     */
    void color_pixel(int i, int j, const Color &c);

    /**
     * @brief Save the screen image as a Portable pixmap.
     * @param filename name (and path) of the created Portable pixmap.
     */
    void save_image_as_ppm(const std::string &filename);

    /**
     * @brief Color the screen by ray tracing rays on the considered scene.
     * @param scene considered scene.
     * @param camera_position position of the camera.
     */
    void render_scene(Scene &scene, const Vec3 &camera_position, int max_hit);
};

#endif // SCREEN_HPP_