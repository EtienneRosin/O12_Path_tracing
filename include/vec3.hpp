// -*- lsst-c++ -*-
/**
 * @file vec3.hpp
 * @brief Declaration of the Vec3 class.
 *
 * @details This file contains the declaration of a 3D vector class ('Vec3') which inherits
 * from std::array<double, 3>, as well as algebraic operations and functions to manipulate it.
 *
 * @version 0.1
 * @date 2024
 * @author Etienne Rosin
 */

#ifndef VEC3_HPP_
#define VEC3_HPP_

#include <iostream>
#include <array>
#include <initializer_list>
#include <stdexcept>
#include <cmath>

class Vec3 : public std::array<double, 3>
{
public:
    /**
     * @brief Default constructor.
     * @details Initializes the vector with {0.0, 0.0, 0.0}.
     * @note We will denote as 'v' the current instance of Vec3.
     */
    Vec3();

    /**
     * @brief Values constructor.
     * @param x, y, z The components of the vector.
     */
    Vec3(double x, double y, double z);

    /**
     * @brief Constructor with initializer list.
     * @details Initializes the vector with the values provided in the list.
     *
     * @param l An initializer list of doubles (must contain exactly 3 elements).
     * @throws std::length_error if the list does not contain exactly 3 elements.
     */
    Vec3(std::initializer_list<double> l);

    /**
     * @brief Copy constructor.
     * @details Performs a shallow copy of another Vec3 object.
     *
     * @param u The Vec3 object to copy.
     */
    Vec3(const Vec3 &u);

    // Acces to its components x, y, z
    double x() const { return (*this)[0]; }
    double y() const { return (*this)[1]; }
    double z() const { return (*this)[2]; }

    /**
     * @brief Overload of the stream output operator.
     * @details Allows printing the Vec3 object using std::ostream.
     *
     * @param os The output stream (e.g., std::cout).
     * @param u The Vec3 object to print.
     * @return std::ostream& The modified output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Vec3 &u);

    /**
     * @brief Overload of the assignment operator.
     * @details Assigns the values of vector 'u' to vector 'v'.
     *
     * @param u The Vec3 object to assign.
     * @return Vec3& The modified current instance ('v').
     */
    Vec3 &operator=(const Vec3 &u);

    /**
     * @brief Element-wise addition 'v = v + u'.
     * @param u The Vec3 object to add.
     * @return Vec3& The modified current instance ('v').
     */
    Vec3 &operator+=(const Vec3 &u);

    /**
     * @brief Element-wise subtraction 'v = v - u'.
     * @param u The Vec3 object to subtract.
     * @return Vec3& The modified current instance ('v').
     */
    Vec3 &operator-=(const Vec3 &u);

    /**
     * @brief Element-wise multiplication 'v = a * v'.
     * @param a Scalar value to multiply by.
     * @return Vec3& The modified current instance ('v').
     */
    Vec3 &operator*=(const double &a);

    /**
     * @brief Element-wise division 'v = (1/a) * v'.
     * @param a Scalar value to divide by.
     * @throws std::runtime_error if 'a' is zero (division by zero).
     * @return Vec3& The modified current instance ('v').
     */
    Vec3 &operator/=(const double &a);

    /**
     * @brief Element-wise addition 'v + u' (non-modifying).
     * @param u The Vec3 object to add.
     * @return Vec3 A new vector that is the sum of 'v' and 'u'.
     */
    Vec3 operator+(const Vec3 &u) const;

    /**
     * @brief Element-wise subtraction 'v - u' (non-modifying).
     * @param u The Vec3 object to subtract.
     * @return Vec3 A new vector that is the difference of 'v' and 'u'.
     */
    Vec3 operator-(const Vec3 &u) const;

    /**
     * @brief Scalar multiplication 'v * a' (non-modifying).
     * @param a Scalar value to multiply by.
     * @return Vec3 A new vector that is the product of 'v' and 'a'.
     */
    Vec3 operator*(const double &a) const;

    /**
     * @brief Scalar division 'v / a' (non-modifying).
     * @param a Scalar value to divide by.
     * @throws std::runtime_error if 'a' is zero (division by zero).
     * @return Vec3 A new vector that is the result of dividing 'v' by 'a'.
     */
    Vec3 operator/(const double &a) const;

    /**
     * @brief Computes the Euclidean norm of the Vec3 vector.
     * @return double The Euclidean norm.
     */
    double norm() const;

    /**
     * @brief Computes the dot product of the current Vec3 with another Vec3.
     * @param other The second Vec3 vector.
     * @return double The dot product of the two vectors.
     */
    double dot(const Vec3 &other) const;

    /**
     * @brief Normalize the Vec3 vector.
     *
     * @return The normalized vector.
     */
    Vec3 normalize() const;
};

/**
 * @brief Scalar multiplication 'a * v' (non-modifying).
 * @param a Scalar value to multiply by.
 * @param u Vec3 vector to be multiplied.
 * @return Vec3 A new vector that is the product of 'a' and 'u'.
 */
Vec3 operator*(const double &a, const Vec3 &u);

/**
 * @brief Computes the cross product of two Vec3 vectors.
 * @param u The first Vec3 vector.
 * @param v The second Vec3 vector.
 * @return Vec3 The cross product of the two vectors.
 */
Vec3 cross(const Vec3 &u, const Vec3 &v);

/**
 * @brief Computes the Hadamard product of two Vec3 vectors.
 * @param u The first Vec3 vector.
 * @param v The second Vec3 vector.
 * @return Vec3 The Hadamard product of the two vectors.
 */
Vec3 Hadamard(const Vec3 &u, const Vec3 &v);

using Point3 = Vec3;

#endif // VEC3_HPP_