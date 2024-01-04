#ifndef VEC3_HPP
#define VEC3_HPP

#include <array>
#include <cassert>
#include <cmath>
#include <iostream>

namespace rt
{
    class Vec3
    {
    public:
        std::array<double, 3> e { 0, 0, 0 };

        /// @brief Default constructor
        constexpr Vec3() noexcept = default;

        /// @brief Constructor
        /// @param e0 The x-coordinate of the 3d vector
        /// @param e1 The y-coordinate of the 3d vector
        /// @param e2 The z-coordinate of the 3d vector
        constexpr Vec3(double e0, double e1, double e2) noexcept
        :   e { e0, e1, e2 }
        {
        }

        /// @brief Get the x-coordinate of the vector
        /// @return The x-coordinate of the vector
        constexpr double x() const noexcept
        {
            return e[0];
        }

        /// @brief Get the y-coordinate of the vector
        /// @return The y-coordinate of the vector
        constexpr double y() const noexcept
        {
            return e[1];
        }

        /// @brief Get the z-coordinate of the vector
        /// @return The z-coordinate of the vector
        constexpr double z() const noexcept
        {
            return e[2];
        }

        /// @brief Get the negation of this vector
        /// @return The negation of this vector
        constexpr Vec3 operator-() const noexcept
        {
            return Vec3(-e[0], -e[1], -e[2]);
        }

        /// @brief Access the element at the given index
        /// @param i The index of the element in the vector
        /// @pre The index must be within the valid range
        /// @return The element at the given index
        constexpr double operator[](int i) const noexcept
        {
            assert(i >= 0 and i <= 2);      
            return e[i];
        }

        /// @brief Access the element at the given index
        /// @param i The index of the element in the vector
        /// @pre The index must be within the valid range
        /// @return The element at the given index
        double& operator[](int i) noexcept
        {
            assert(i >= 0 and i <= 2);
            return e[i];
        }

        /// @brief Perform component-wise sum of the given vector and this vector
        /// @param v The vector to be added to this one
        /// @return This vector after the addition has been performed
        Vec3& operator+=(Vec3 const& v) noexcept
        {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];

            return *this;
        }

        /// @brief Multiply this vector by the given constant
        /// @param t The scalar constant to be multiplied with the vector
        /// @return This vector after it has been scaled by the given constant
        Vec3& operator*=(double t) noexcept
        {
            for (auto const& elem : e) {
                e *= t;
            }

            return *this;
        }

        /// @brief Divide this vector by the given constant
        /// @param t The scalar constant to divide the vector with
        /// @return This vector after it has been down-scaled by the given constant
        Vec3& operator/=(double t) noexcept
        {
            return *this *= (1 / t);
        }

        /// @brief Get the length of this vector
        /// @return The length of the vector
        constexpr double length() const noexcept
        {
            return std::sqrt(lengthSquared());
        }

        /// @brief Get the sum of the squares of the components of this vector
        /// @return The sum of the squares of the components of this vector
        constexpr double lengthSquared() const noexcept
        {
            return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
        }
    };

    /// @brief Write the given vector to an output stream
    /// @param out The output stream to which the vector is to be written
    /// @param v The vector to be written to the output stream
    /// @return The output stream containing a string representation of the vector
    inline std::ostream& operator<<(std::ostream& out, Vec3 const& v) noexcept
    {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    /// @brief Perform component-wise addition of 2 vectors
    /// @param u The first vector in the sum
    /// @param v The second vector in the sum
    /// @return A new vector equal to the sum of the 2 vectors
    constexpr Vec3 operator+(Vec3 const& u, Vec3 const& v) noexcept
    {
        return Vec3(
            u.e[0] + v.e[0],
            u.e[1] + v.e[1],
            u.e[2] + v.e[2]
        );
    }

    /// @brief Perform component-wise subtraction of 2 vectors
    /// @param u The first vector in the difference
    /// @param v The second vector in the difference
    /// @return A new vector equal to the difference of the 2 vectors
    constexpr Vec3 operator-(Vec3 const& u, Vec3 const& v) noexcept
    {
        return Vec3(
            u.e[0] - v.e[0],
            u.e[1] - v.e[1],
            u.e[2] - v.e[2]
        );
    }

    /// @brief Perform component-wise multiplication of 2 vectors
    /// @param u The first vector in the product
    /// @param v The second vector in the product
    /// @return A new vector equal to the product of the 2 vectors
    constexpr Vec3 operator*(Vec3 const& u, Vec3 const& v) noexcept
    {
        return Vec3(
            u.e[0] * v.e[0],
            u.e[1] * v.e[1],
            u.e[2] * v.e[2]
        );
    }

    /// @brief Get a new vector equal to the given vector scaled by the given constant
    /// @param t The scaling factor
    /// @param v The vector to be scaled
    /// @return A new vector equal to the given vector scaled by the given scaling factor
    constexpr Vec3 operator*(double t, Vec3 const& v) noexcept
    {
        return Vec3(
            t * v.e[0],
            t * v.e[1],
            t * v.e[2]
        );
    }

    /// @brief Get a new vector equal to the given vector scaled by the given constant
    /// @param t The scaling factor
    /// @param v The vector to be scaled
    /// @return A new vector equal to the given vector scaled by the given scaling factor
    constexpr Vec3 operator*(Vec3 const& v, double t) noexcept
    {
        return t * v;
    }

    /// @brief Get a new vector equal to the given vector scaled by the given constant
    /// @param t The scaling factor
    /// @param v The vector to be scaled
    /// @return A new vector equal to the given vector scaled by the given scaling factor
    constexpr Vec3 operator/(Vec3 const& v, double t) noexcept
    {
        return (1 / t) * v;
    }

    /// @brief Get the dot product of 2 given vectors
    /// @param u The first vector in the operation
    /// @param v The second vector in the operation
    /// @return The dot product of the 2 vectors
    constexpr double dot(Vec3 const& u, Vec3 const& v) noexcept
    {
        return (
            u.e[0] * v.e[0] + 
            u.e[1] * v.e[1] +
            u.e[2] + v.e[2]
        );
    }
}

#endif