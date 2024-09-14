#include "ray.hpp"
#include "vec3.hpp"

#include <stdexcept>
#include <iostream>

// Default constructor: initializes source and direction to (0, 0, 0)
Ray::Ray() : source(Vec3()), direction(Vec3()) {}

// Constructor with source and direction
Ray::Ray(const Vec3 &source, const Vec3 &direction)
    : source(source), direction(direction) {}

// Method to get the point at time t along the ray
Vec3 Ray::at(float t) const
{
    if (t > 0)
    {
        return source + t * direction;
    }
    else
    {
        // Throw an exception if t is not positive
        throw std::invalid_argument(
            "Error: t must be strictly positive. Detected in file " + std::string(__FILE__) +
            " at line " + std::to_string(__LINE__));
    }
}

Ray create_ray_from_points(const Vec3 &A, const Vec3 &B)
{
    Vec3 direction = (B - A).normalize();
    return Ray(A, direction);
};