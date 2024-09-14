// -*- lsst-c++ -*-
/**
 * @file color.hpp
 * @brief Declaration of the Ray class.
 *
 * @details This file contains the declaration of a ray class ('Ray').
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */
#ifndef RAY_HPP_
#define RAY_HPP_

#include "vec3.hpp"

class Ray
{

public:
    const Vec3 source;    // source (S) of the ray
    const Vec3 direction; // direction (u) of the ray

    /**
     * @brief Default constructor.
     * @details Initializes the ray with source = (0,0,0) and direction = (0,0,0).
     */
    Ray();

    /**
     * @brief Constructor with source and direction.
     * @param source of the ray.
     * @param direction of the ray.
     */
    Ray(const Vec3 &source, const Vec3 &direction);

    /**
     * @brief Get the point M(t) = S + t * u of the ray.
     * @param t 'time' of propagation of the ray (must be positive).
     * @return Vec3 the considered point.
     */
    Vec3 at(float t) const;
};

Ray create_ray_from_points(const Vec3 &A, const Vec3 &B);

#endif // RAY_HPP_