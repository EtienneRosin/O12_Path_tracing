#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "vec3.hpp"
#include "elements.hpp"

// Forward declaration of the Element class
class Element;

#include <memory>

/**
 * @brief Struct to hold intersection information between a Ray and an Element.
 */
struct Intersection
{
    Vec3 point;                             ///< The point of intersection.
    double t;                               ///< The "time" or distance along the ray to the intersection point.
    std::shared_ptr<const Element> element; ///< The element of the intersection (const to prevent modification).
    bool valid;                             ///< True if the intersection is valid, false otherwise.

    /**
     * @brief Default constructor for Intersection.
     */
    Intersection() : point(Vec3()), t(0.0), element(nullptr), valid(false) {}

    /**
     * @brief Constructor for Intersection with given point and time.
     * @param p The point of intersection.
     * @param time The distance along the ray to the intersection point.
     */
    Intersection(const Vec3 &p, double time, std::shared_ptr<const Element> elem) : point(p), t(time), element(elem), valid(true) {}
};

#endif // INTERSECTION_HPP_