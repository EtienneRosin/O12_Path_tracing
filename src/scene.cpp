

#include "scene.hpp"

void Scene::add_element(std::shared_ptr<Element> element)
{
    elements.push_back(element);
};

void Scene::add_light(const Light &light)
{
    lights.push_back(light);
};

std::vector<Intersection> Scene::compute_intersections(const Ray &ray)
{
    std::vector<Intersection> intersections;

    for (const auto &element : elements)
    {
        Intersection intersection = element->intersect(ray);
        intersections.push_back(intersection);
        // if (intersection.valid)
        // {
        //     intersections.push_back(intersection);
        // }
    }
    return intersections;
};

// Find the first intersection between the ray and the scene.
Intersection Scene::find_first_intersection(const Ray &ray)
{
    std::vector<Intersection> intersections = compute_intersections(ray);
    // std::cout << "calculated intersections" << intersections << "\n";
    float minimal_time = std::numeric_limits<float>::infinity();
    Intersection first_intersection = Intersection();
    for (const auto &intersection : intersections)
    {
        if ((intersection.t <= minimal_time) && (intersection.valid))
        {
            minimal_time = intersection.t;
            first_intersection = intersection;
        }
    }
    return first_intersection;
};

bool Scene::light_is_visible_from_point_on_element(const Light &light, const Vec3 &point, const std::shared_ptr<const Element> &element)
{
    if (element->is_light_visible_from_point(light, point) == false)
    {
        return false;
    }

    Ray ray_to_light = create_ray_from_points(point, light.position);

    for (const auto &scene_element : elements)
    {
        if (scene_element != element)
        {
            Intersection intersection = scene_element->intersect(ray_to_light);

            if (intersection.valid && intersection.t < (light.position - point).norm())
            {
                return false;
            }
        }
    }

    return true;
};

std::vector<Intersection> Scene::propagate_ray(const Ray &ray, const int max_hit)
{
    std::vector<Intersection> optical_path;
    for (auto i = 0; i < max_hit; i++)
    {
        Intersection current_intersection = find_first_intersection(ray);
        if (current_intersection.valid)
        {
            optical_path.push_back(current_intersection);
        }
        else
        {
            optical_path.push_back(current_intersection);
            return optical_path;
        }
    }
    return optical_path;
};