// -*- lsst-c++ -*-
/**
 * @file vec3.cpp
 * @brief Implementation of the Vec3 class.
 *
 * @details This file contains the implementation of the constructors, operators, and
 * other functions for the Vec3 class which models a 3D vector.
 */

#include "vec3.hpp"
#include <stdexcept> // For handling exceptions like length_error and runtime_error
#include <cmath>     // For std::sqrt

// Default constructor
Vec3::Vec3() : std::array<double, 3>{0.0, 0.0, 0.0} {}

// Values constructor
Vec3::Vec3(double x, double y, double z)
{
    (*this)[0] = x;
    (*this)[1] = y;
    (*this)[2] = z;
}

// Constructor with initializer list
Vec3::Vec3(std::initializer_list<double> l)
{
    // Check that the initializer list has exactly 3 elements
    if (l.size() != 3)
    {
        throw std::length_error("Vec3 requires exactly 3 elements.");
    }
    // Copy the elements from the initializer list into the array
    std::copy(l.begin(), l.end(), this->begin());
}

// Copy constructor (delegates to std::array copy constructor)
Vec3::Vec3(const Vec3 &u) = default;

// Assignment operator
Vec3 &Vec3::operator=(const Vec3 &u)
{
    if (this != &u)
    { // Avoid self-assignment
        std::copy(u.begin(), u.end(), this->begin());
    }
    return *this;
}

// Element-wise addition operator
Vec3 &Vec3::operator+=(const Vec3 &u)
{
    for (size_t i = 0; i < 3; ++i)
    {
        (*this)[i] += u[i];
    }
    return *this;
}

// Element-wise subtraction operator
Vec3 &Vec3::operator-=(const Vec3 &u)
{
    for (size_t i = 0; i < 3; ++i)
    {
        (*this)[i] -= u[i];
    }
    return *this;
}

// Scalar multiplication operator
Vec3 &Vec3::operator*=(const double &a)
{
    for (size_t i = 0; i < 3; ++i)
    {
        (*this)[i] *= a;
    }
    return *this;
}

// Scalar division operator (with division by zero check)
Vec3 &Vec3::operator/=(const double &a)
{
    if (a == 0.0)
    {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    for (size_t i = 0; i < 3; ++i)
    {
        (*this)[i] /= a;
    }
    return *this;
}

// Non-modifying element-wise addition
Vec3 Vec3::operator+(const Vec3 &u) const
{
    Vec3 result = *this;
    result += u; // Use the += operator we already defined
    return result;
}

// Non-modifying element-wise subtraction
Vec3 Vec3::operator-(const Vec3 &u) const
{
    Vec3 result = *this;
    result -= u; // Use the -= operator we already defined
    return result;
}

// Non-modifying scalar multiplication
Vec3 Vec3::operator*(const double &a) const
{
    Vec3 result = *this;
    result *= a; // Use the *= operator we already defined
    return result;
}

// Non-modifying scalar division (with division by zero check)
Vec3 Vec3::operator/(const double &a) const
{
    if (a == 0.0)
    {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    Vec3 result = *this;
    result /= a; // Use the /= operator we already defined
    return result;
}

// Output stream operator
std::ostream &operator<<(std::ostream &os, const Vec3 &v)
{
    os << "Vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

// Scalar multiplication `a * v` (non-modifying)
Vec3 operator*(const double &a, const Vec3 &u)
{
    return u * a; // Use the member function `u * a`
}

// Dot product of this vector and another vector
double Vec3::dot(const Vec3 &other) const
{
    double result = 0.0;
    for (size_t i = 0; i < 3; ++i)
    {
        result += (*this)[i] * other[i];
    }
    return result;
}

// Euclidean norm of this vector
double Vec3::norm() const
{
    return std::hypot((*this)[0], (*this)[1], (*this)[2]);
}

Vec3 Vec3::normalize() const
{
    double n = norm();
    if (n == 0)
    {
        throw std::runtime_error("Cannot normalize a zero-length vector");
    }
    return *this / n;
}

// Cross product of this vector and another vector
Vec3 cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3{
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]};
}

// Hadamard product of this vector and another vector
Vec3 Hadamard(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}