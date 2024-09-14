// -*- lsst-c++ -*-
/**
 * @file scene.hpp
 * @brief Implementation of a Scene class that represents the world.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "light.hpp"
#include "elements.hpp"
#include "ray.hpp"
#include "intersection.hpp"

#include <vector>
#include <memory>

class Scene
{
public:
    std::vector<Light> lights;                      ///< List of the scene lights.
    std::vector<std::shared_ptr<Element>> elements; ///< List of the scene elements, handled thanks to unique pointers.

    /**
     * @brief Default constructor for Scene.
     */
    Scene() : lights(), elements() {}

    // delete the affectation operator and copy constructor.
    Scene(const Scene &) = delete;

    Scene &operator=(const Scene &) = delete;

    /**
     * @brief Add a light to the scene.
     * @param light Considered light.
     */
    void add_light(const Light &light);

    /**
     * @brief Add an element (sphere, box, ...) to the scene.
     * @param element Considered element (as a pointer).
     */
    void add_element(std::shared_ptr<Element> element);

    /**
     * @brief Throw the ray through the scene and return all the geometrical intersections of the ray.
     * @param ray The considered ray.
     *
     * @return The vector of intersections.
     */
    std::vector<Intersection> compute_intersections(const Ray &ray);

    /**
     * @brief Find the first intersection between the ray and the scene.
     * @param ray The considered ray.
     *
     * @return The first intersection.
     */
    Intersection find_first_intersection(const Ray &ray);

    /**
     * @brief Propagate the ray throught the scene.
     * @param ray The considered ray.
     * @param max_hit number o.f reflexions allowed
     *
     * @return Optical path.
     */
    std::vector<Intersection> propagate_ray(const Ray &ray, const int max_hit);

    /**
     * @brief Tell if the light is visible from a point belonging to an element.
     * @param light Considered light.
     * @param point Considered point.
     * @param element Considered element.
     *
     * @return true is the light is visible, false otherwise.
     */
    bool light_is_visible_from_point_on_element(const Light &light, const Vec3 &point, const std::shared_ptr<const Element> &element);
};

#endif // SCENE_HPP_