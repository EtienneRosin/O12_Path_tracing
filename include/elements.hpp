#ifndef ELEMENTS_HPP_
#define ELEMENTS_HPP_

#include "vec3.hpp"
#include "ray.hpp"
#include "material.hpp"
#include "intersection.hpp"
#include "light.hpp"

class Element
{
public:
    Material material; ///< Material properties of the element.
    Vec3 center;       ///< Center of the element.
    /**
     * @brief Default constructor.
     */
    Element() : material(Material()), center(Vec3()) {}

    /**
     * @brief Virtual constructor.
     */
    virtual ~Element() {}

    /**
     * @brief Constructor with material properties.
     * @param mat The material associated with the element.
     */
    Element(const Material &mat, const Vec3 &c) : material(mat), center(c) {}

    /**
     * @brief Virtual method to check if a point is inside the element.
     * @param point The point to check.
     * @return true if the point is inside the element, false otherwise.
     */
    virtual bool contains(const Vec3 &point) const = 0;

    /**
     * @brief Virtual method to check if a point is on the border of the element.
     * @param point The point to check.
     * @return true if the point is on the border of the element, false otherwise.
     */
    virtual bool is_on_border(const Vec3 &point) const = 0;

    /**
     * @brief Virtual method to get the normal at a specific point on the element.
     * @param point The point at which to calculate the normal.
     * @return The normal vector at the given point.
     */
    virtual Vec3 get_normal(const Vec3 &point) const = 0;

    /**
     * @brief Calculate the intersection of a Ray with the Sphere.
     * @param ray The Ray to test for intersection.
     * @return intersection information (if no intersection is found then intersection.valid = false).
     */
    virtual Intersection intersect(const Ray &ray) const = 0;

    /**
     * @brief Tell if the source is visible from a point on the border of the Element.
     * @param light considered light.
     * @param point considered point.
     *
     * @return true if the light is visible from the point, false otherwise.
     */
    virtual bool is_light_visible_from_point(const Light &light, const Vec3 &point) const = 0;
};

/**
 * @brief Create a sphere object.
 */
class Sphere : public Element, public std::enable_shared_from_this<Sphere>
{
public:
    // Vec3 center;   ///< Center of the sphere.
    double radius; ///< Radius of the sphere.

    /**
     * @brief Constructor with center, radius, and basic material properties.
     *
     * @param c The center of the sphere.
     * @param r The radius of the sphere.
     * @param mat The material of the sphere.
     */
    Sphere(const Vec3 &c, double r, const Material &mat);

    // Disable copy constructor
    Sphere(const Sphere &) = delete;

    // Disable move constructor
    Sphere(Sphere &&) = delete;

    /**
     * @brief Return if the considered point is within the Sphere.
     * @param point The point to check.
     * @return true if the point lies within the Sphere, false otherwise.
     */
    bool contains(const Vec3 &point) const override;

    /**
     * @brief Return if the considered point is on the Sphere border.
     * @param point The point to check.
     * @return true if the point is on the Sphere border, false otherwise.
     */
    bool is_on_border(const Vec3 &point) const override;

    /**
     * @brief Return the normal of the Sphere at the given point.
     * @param point The point at which to calculate the normal (should be on the Sphere border).
     * @return The normal vector at the given point.
     */
    Vec3 get_normal(const Vec3 &point) const override;

    /**
     * @brief Calculate the intersection of a Ray with the Sphere.
     * @param ray The Ray to test for intersection.
     * @return intersection information (if no intersection is found then intersection.valid = false).
     */
    Intersection intersect(const Ray &ray) const override;

    /**
     * @brief Tell if the source is visible from a point on the border of the Element.
     * @param light considered light.
     * @param point considered point.
     *
     * @return true if the light is visible from the point, false otherwise.
     */
    bool is_light_visible_from_point(const Light &light, const Vec3 &point) const override;
};

#endif // ELEMENTS_HPP_