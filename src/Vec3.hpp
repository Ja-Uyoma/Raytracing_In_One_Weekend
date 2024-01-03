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
    };
}

#endif