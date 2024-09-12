#include <iostream>
#include "render_images.hpp"
#include "vec3.hpp"
#include "image.hpp"

using namespace std;

/* pour compiler :
    - se mettre dans le dossier /build/
    - marquer "make"
    - l'exécutable est: "build/main"
     */
int main()
{
    // int width = 100;
    // int height = 100;
    // std::string save_path = "../output/test.ppm";
    // render_image(width, height, save_path);

    // Vec3 v1 = {1.0, 2.0, 3.0};
    // Vec3 v2 = {4.0, 5.0, 6.0};

    // // Dot product
    // double dotProduct = v1.dot(v2);
    // std::cout << "Dot product: " << dotProduct << std::endl; // Outputs: 32.0

    // // Norm
    // double normV1 = v1.norm();
    // std::cout << "Norm of v1: " << normV1 << std::endl; // Outputs: 3.74166

    // // Cross product
    // Vec3 crossProduct = cross(v1, v2);
    // Vec3 HadamardProduct = Hadamard(v1, v2);
    // std::cout << "Cross product: " << crossProduct << std::endl; // Outputs: Vec3(-3.0, 6.0, -3.0)

    // std::cout << "Hadamard product: " << HadamardProduct << std::endl; // Outputs: Vec3(-3.0, 6.0, -3.0)

    // // Create a 256x256 image
    const int WIDTH = 1600;
    const int HEIGHT = 900;
    Image img(WIDTH, HEIGHT);

    // Define the start color (light blue) and end color (white)

    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            // Calculate the normalized position (from 0.0 to 1.0)
            double t = (static_cast<double>(x + y) / (WIDTH + HEIGHT));

            // Define the start color (light blue) and end color (white)
            Color startColor(0.678, 0.747, 1); // Light blue
            Color endColor(1.0, 1.0, 1.0);     // White

            // Interpolate between the start color and the end color
            Color pixelColor = startColor * (1.0 - t) + endColor * t;

            // Set the pixel color
            img.set_pixel(x, y, pixelColor);
        }
    }

    // Save the image as a PPM file
    img.save_as_ppm("../output/gradient.ppm");

    // // Set some pixels to different colors
    // img.set_pixel(10, 10, Color(1.0, 0.0, 0.0)); // Red
    // img.set_pixel(20, 20, Color(0.0, 1.0, 0.0)); // Green
    // img.set_pixel(30, 30, Color(0.0, 0.0, 1.0)); // Blue

    // Save the image to a PPM file
    img.save_as_ppm("../output/output.ppm");

    return (0);
}
