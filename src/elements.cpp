#include "elements.hpp"

Sphere::Sphere(const Vec3 &c, double r, const Material &mat) : Element(mat, c), radius(std::fmax(0, r)) {}

Intersection Sphere::intersect(const Ray &ray) const
{
    Vec3 oc = ray.source - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        double sqrtDiscriminant = std::sqrt(discriminant);
        double t1 = (-b - sqrtDiscriminant) / (2.0 * a);
        double t2 = (-b + sqrtDiscriminant) / (2.0 * a);

        // Find the leastest positive solution
        if (t1 > 0 && t2 > 0)
        {
            double t = std::min(t1, t2);
            return Intersection(ray.at(t), t, shared_from_this());
        }
        else if (t1 > 0)
        {
            return Intersection(ray.at(t1), t1, shared_from_this());
        }
        else if (t2 > 0)
        {
            return Intersection(ray.at(t2), t2, shared_from_this());
        }
    }

    return Intersection();
}

Vec3 Sphere::get_normal(const Vec3 &point) const
{
    return (point - center).normalize();
}

bool Sphere::contains(const Vec3 &point) const
{
    return (point - center).norm() <= radius;
}

bool Sphere::is_on_border(const Vec3 &point) const
{

    double distance = (point - center).norm();

    // check if the distance is equal to the spehre radius with a tolerance
    const double tolerance = 1e-6;
    return std::fabs(distance - radius) < tolerance;
};

// Tell if the source is visible from a point on the border of the Element.
bool Sphere::is_light_visible_from_point(const Light &light, const Vec3 &point) const
{
    if (is_on_border(point) == false)
    {
        // std::cout << "point is not on border" << "\n";
        return false;
    }
    Vec3 normal = get_normal(point);
    float dot_product = normal.dot((light.position - point).normalize());
    // std::cout << "dot_product = " << dot_product << "\n";
    return dot_product >= 0;
};