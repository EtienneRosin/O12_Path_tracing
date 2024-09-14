#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include "vec3.hpp"

class Material
{
public:
    Vec3 albedo;       // Diffuse color of the material (e.g., the color seen under diffuse light)
    float reflectance; ///< reflectance of the material (should be in [0, 1]).
    // float specular; // Specular coefficient (controls the shininess of the surface)

    /**
     * @brief Constructor with basic material properties.
     * @param albedo The diffuse color of the material.
     * @param reflectance The specular coefficient (optional, default is 0.1f for matte surfaces).
     */
    Material(const Vec3 &albedo, float reflectance = 0.7)
        : albedo(albedo), reflectance(reflectance) {}

    /**
     * @brief Default constructor.
     * Initializes with default values: white color and no specular reflection.
     */
    Material()
        : albedo(Vec3(1.0, 1.0, 1.0)), reflectance(0.0f) {}
};

#endif // MATERIAL_HPP_