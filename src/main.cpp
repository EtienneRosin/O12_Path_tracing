#include <iostream>

#include "vec3.hpp"
// #include "image.hpp"
#include "ray.hpp"
#include "elements.hpp"
#include "screen.hpp"
#include "background.hpp"
#include "intersection.hpp"
#include "light.hpp"

#include <vector>

using namespace std;

/* pour compiler :
    - se mettre dans le dossier /build/
    - marquer "make"
    - l'exécutable est: "build/main"
    */
int main()
{

    /* -------------------------------------------------------------------------------------- */
    // const int WIDTH = 16;
    // const int HEIGHT = 9;
    // const int WIDTH_RESOLUTION = 1600;
    // const int HEIGHT_RESOLUTION = 900;
    // Screen screen = Screen(WIDTH, HEIGHT, WIDTH_RESOLUTION, HEIGHT_RESOLUTION);
    // Color top_color(0.0f, 0.0f, 1.0f);    // Bleu en haut
    // Color bottom_color(0.0f, 1.0f, 0.0f); // Vert en bas

    // // Appliquer le fond en dégradé à l'aide de la fonction externe
    // // apply_gradient_background(screen, top_color, bottom_color);
    // apply_checkerboard_background(screen, top_color, bottom_color, 10);

    // // Vous pouvez ensuite enregistrer l'image ou continuer à manipuler l'écran
    // screen.save_image_as_ppm("../output/output_image.ppm");
    /* -------------------------------------------------------------------------------------- */
    // Ray ray = Ray(Vec3(), Vec3(1, 0, 0));
    // Material mat = Material();
    // // Sphere sphere = Sphere(Vec3(10, 0, 0), 5, mat);
    // std::shared_ptr<Sphere> sphere = std::make_shared<Sphere>(Vec3(10, 0, 0), 5, mat);

    // Intersection inter = sphere->intersect(ray);
    // if (inter.valid)
    // {
    //     std::cout << "Intersection at point: " << inter.point << " at t = " << inter.t << std::endl;
    // }
    // else
    // {
    //     std::cout << "No intersection found." << std::endl;
    // }
    /* -------------------------------------------------------------------------------------- */
    Scene scene = Scene();

    Ray ray = Ray(Vec3(), Vec3(1, 0, 1));
    // Material mat = Material(Vec3(1, 1, 0));

    std::shared_ptr<Sphere> sphere_1 = std::make_shared<Sphere>(Vec3(0, 0, -5), 2, Material(Vec3(0.5, 0.5, 0.5), 0.75));
    std::shared_ptr<Sphere> sphere_2 = std::make_shared<Sphere>(Vec3(5, 0, -10), 5, Material(Vec3(1, 0.5, 0.5), 0.75));

    std::shared_ptr<Sphere> sphere_3 = std::make_shared<Sphere>(Vec3(-20, 0, -15), 10, Material(Vec3(0, 0.5, 0.5), 0.75));

    scene.add_element(sphere_1);
    scene.add_element(sphere_2);
    scene.add_element(sphere_3);

    Light s_1 = Light(Vec3(-5, 5, -1), Color(1, 1, 1));

    Light s_2 = Light(Vec3(-5, -5, -1), Color(1, 1, 1));

    scene.add_light(s_1);
    scene.add_light(s_2);

    /* ---- */
    const float WIDTH = 1.6 * 2;
    const float HEIGHT = 0.9 * 2;
    const int WIDTH_RESOLUTION = 160 * 20;
    const int HEIGHT_RESOLUTION = 90 * 20;
    Screen screen = Screen(WIDTH, HEIGHT, WIDTH_RESOLUTION, HEIGHT_RESOLUTION);

    // // Appliquer le fond en dégradé à l'aide de la fonction externe
    // Color top_color(0.0f, 0.0f, 8.0f);    // Bleu en haut
    // Color bottom_color(1.0f, 1.0f, 1.0f); // Vert en bas
    // apply_gradient_background(screen, top_color, bottom_color);
    // // apply_checkerboard_background(screen, top_color, bottom_color, 10);

    screen.render_scene(scene, Vec3(0, 0, 1), 5);
    screen.save_image_as_ppm("../output/first_try.ppm");
    // std::vector<Intersection> intersections = scene.compute_intersections(ray);

    // for (const auto &intersection : intersections)
    // {
    //     if (intersection.valid)
    //     {
    //         std::cout << "Intersection at point: " << intersection.point << " at t = " << intersection.t << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "No intersection found." << std::endl;
    //     }
    // }

    // Intersection first_intersection = scene.find_first_intersection(ray);
    // if (first_intersection.valid)
    // {
    //     cout << first_intersection.element->is_light_visible_from_point(s_1, first_intersection.point) << "\n";
    //     cout << "Source is visible from first intersection : " << scene.light_is_visible_from_point_on_element(s_1, first_intersection.point, first_intersection.element) << "\n";
    // }
    // else
    // {

    //     cout << "Invalid intersection" << "\n";
    // }
    // std::cout << "First Intersection at point: " << first_intersection.point << " at t = " << first_intersection.t << std::endl;

    return 0;
}
