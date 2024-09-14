// -*- lsst-c++ -*-
/**
 * @file screen.cpp
 * @brief Implementation of the Screen class.
 *
 * @details This file contains the Implementation of a screen class.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */

#include "screen.hpp"
// #include "ray.hpp"
// #include "vec3.hpp"

// #include <ranges>

// Value constructor
Screen::Screen(const float w, const float h, const int w_res, const int h_res) : width(w), height(h), width_resolution(w_res), height_resolution(h_res), pixel_width(w / w_res), pixel_height(h / h_res), pixels(
                                                                                                                                                                                                              h_res,
                                                                                                                                                                                                              std::vector<Color>(
                                                                                                                                                                                                                  w_res,
                                                                                                                                                                                                                  Color(0.0, 0.0, 0.0))) {};

// Return if the considered pixel belongs to the screen.
bool Screen::valid_pixel(int i, int j) const
{
    return (i >= 0 && i < width_resolution) && (j >= 0 && j < height_resolution);
};

// Return the color of the pixel.
Color Screen::get_pixel_color(int i, int j) const
{
    if (valid_pixel(i, j))
    {
        return pixels[j][i]; // Return the color of the pixel at (x, y).
    }
    else
    {
        std::cerr << "Error: Attempt to access a pixel out of bounds (" << i << ", " << j << ")\n";
        return Color(0.0, 0.0, 0.0); // Return black if the pixel is out of bounds.
    }
};

// Get the center of the considered pixel.
Vec3 Screen::get_pixel_center(int i, int j)
{
    if (valid_pixel(i, j))
    {
        float x = -width / 2 + (i + 0.5f) * pixel_width;
        float y = height / 2 - (j + 0.5f) * pixel_height;
        return Vec3(x, y, 0.0f);
    }
    else
    {
        std::cerr << "Error: Attempt to set a pixel out of bounds (" << i << ", " << j << ")\n";
        return Vec3();
    }
};

// Get the ray coming from the camera to the pixel center.
Ray Screen::get_ray_passing_through_pixel(int i, int j, const Vec3 &camera_position)
{
    if (valid_pixel(i, j))
    {
        Vec3 pixel_center = get_pixel_center(i, j);
        Vec3 ray_direction = (pixel_center - camera_position).normalize();
        return Ray(pixel_center, ray_direction);
    }
    else
    {
        std::cerr << "Error: Attempt to set a pixel out of bounds (" << i << ", " << j << ")\n";
        return Ray();
    }
};

// Color the considered pixel.
void Screen::color_pixel(int i, int j, const Color &c)
{
    if (valid_pixel(i, j))
    {
        pixels[j][i] = c;
    }
    else
    {
        std::cerr << "Error: Attempt to set a pixel out of bounds (" << i << ", " << j << ")\n";
    }
};

// Save the screen image as a Portable pixmap.
void Screen::save_image_as_ppm(const std::string &filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    // Write the PPM header
    file << "P3\n";                                               // PPM type (P3 is plain text format)
    file << width_resolution << " " << height_resolution << "\n"; // Image dimensions
    file << "255\n";                                              // Maximum color value (255 for 8-bit colors)

    // Write pixel data
    for (int j = 0; j < height_resolution; ++j)
    {
        std::clog << "\rLines to save remaining: " << (height_resolution - j) << ' ' << std::flush;
        for (int i = 0; i < width_resolution; ++i)
        {
            Color color = get_pixel_color(i, j).as_bytes(); // Convert color to byte representation
            // std::cout << "(R, G, B) = (" << color.r() << ", " << color.g() << ", " << color.b() << ")\n";
            file << color.r() << " "
                 << color.g() << " "
                 << color.b() << " ";
        }
        file << "\n"; // End of line for each row
    }

    file.close();
    // std::cout << "\n";
    std::cout << std::flush;
};

// Color the screen by ray tracing rays on the considered scene.
// void Screen::render_scene(Scene &scene, const Vec3 &camera_position, int max_hit)
// {
//     for (int j = 0; j < height_resolution; ++j)
//     {
//         for (int i = 0; i < width_resolution; ++i)
//         {
//             Ray current_ray = get_ray_passing_through_pixel(i, j, camera_position);
//             std::vector<Intersection> optical_path = scene.propagate_ray(current_ray, max_hit);
//             Color pixel_color = Color();

//             if (optical_path.size() != 1)
//             { // meaning that the ray hits nothing
//               // color_pixel(i, j, pixel_color); // we put a black color.
//               // we keep the background color

//                 for (auto intersection_ptr = optical_path.rbegin(); intersection_ptr != optical_path.rend(); ++intersection_ptr)
//                 {
//                     Vec3 normal_at_point = intersection_ptr->element->get_normal(intersection_ptr->point);

//                     for (auto light_ptr = scene.lights.begin(); light_ptr != scene.lights.end(); ++light_ptr)
//                     {
//                         if (scene.light_is_visible_from_point_on_element(*light_ptr, intersection_ptr->point, intersection_ptr->element))
//                         {
//                             Ray light_ray = create_ray_from_points(light_ptr->position, intersection_ptr->point);
//                             float cos_theta = normal_at_point.dot(light_ray.direction);

//                             // calculate Lambert' law
//                             pixel_color += Hadamard(intersection_ptr->element->material.albedo, light_ptr->color) * cos_theta;
//                         }
//                     }
//                     pixel_color *= intersection_ptr->element->material.reflectance;
//                     // std::cout << *it << " ";
//                 }
//             }
//             // else the ray hits nothing and we keep the background color
//         }
//     }
// };

void Screen::render_scene(Scene &scene, const Vec3 &camera_position, int max_hit)
{
    for (int j = 0; j < height_resolution; ++j)

    {
        std::clog << "\rLines to render remaining: " << (height_resolution - j) << ' ' << std::flush;
        for (int i = 0; i < width_resolution; ++i)
        {
            Ray current_ray = get_ray_passing_through_pixel(i, j, camera_position);
            std::vector<Intersection> optical_path = scene.propagate_ray(current_ray, max_hit);
            Color pixel_color = Color(0.0, 0.0, 0.0); // Initialiser la couleur à noir

            if (optical_path.size() != 1)
            {
                // std::cout << "une d'intersection" << "\n";
                // Si le rayon intersecte quelque chose, calcule la couleur en fonction des intersections
                for (const auto &intersection : optical_path)
                {
                    Vec3 normal_at_point = intersection.element->get_normal(intersection.point);

                    for (const auto &light : scene.lights)
                    {
                        if (scene.light_is_visible_from_point_on_element(light, intersection.point, intersection.element))
                        {
                            Ray light_ray = create_ray_from_points(intersection.point, light.position);
                            float cos_theta = normal_at_point.dot(light_ray.direction);
                            // std::cout << "cos theta = " << cos_theta << "\n";
                            // Calcul de la couleur avec la loi de Lambert
                            pixel_color += Hadamard(intersection.element->material.albedo, light.color) * cos_theta;
                        }
                    }
                    // std::cout << "(R, G, B) = (" << pixel_color.r() << ", " << pixel_color.g() << ", " << pixel_color.b() << ")\n";
                    pixel_color *= intersection.element->material.reflectance;
                }
                // std::cout << "(R, G, B) = (" << pixel_color.r() << ", " << pixel_color.g() << ", " << pixel_color.b() << ")\n";
                color_pixel(i, j, pixel_color); // Assigne la couleur au pixel
            }
        }
    }
    std::cout << std::flush;
    // std::cout << "\n";
}