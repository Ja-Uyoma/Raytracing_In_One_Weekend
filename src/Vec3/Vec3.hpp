// Boost Software License - Version 1.0 - August 17th, 2003

// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:

// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef VEC3_HPP
#define VEC3_HPP

#include <array>
#include <cassert>
#include <cmath>
#include <iostream>

namespace rt::vec3 {
class Vec3
{
public:
  /// @brief Default constructor
  explicit constexpr Vec3() noexcept = default;

  /// @brief Constructor
  /// @param[in] e0 The x-coordinate of the 3d vector
  /// @param[in] e1 The y-coordinate of the 3d vector
  /// @param[in] e2 The z-coordinate of the 3d vector
  explicit constexpr Vec3(double e0, double e1, double e2) noexcept : e {e0, e1, e2}
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
  /// @param[in] i The index of the element in the vector
  /// @pre The index must be within the valid range
  /// @return The element at the given index
  constexpr double operator[](int i) const noexcept
  {
    assert(i >= 0 and i <= 2);
    return e[i];
  }

  /// @brief Access the element at the given index
  /// @param[in] i The index of the element in the vector
  /// @pre The index must be within the valid range
  /// @return The element at the given index
  double& operator[](int i) noexcept
  {
    assert(i >= 0 and i <= 2);
    return e[i];
  }

  /// @brief Perform component-wise sum of the given vector and this vector
  /// @param[in] v The vector to be added to this one
  /// @return This vector after the addition has been performed
  constexpr Vec3& operator+=(Vec3 const& v) noexcept
  {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];

    return *this;
  }

  /// @brief Multiply this vector by the given constant
  /// @param[in] t The scalar constant to be multiplied with the vector
  /// @return This vector after it has been scaled by the given constant
  constexpr Vec3& operator*=(double t) noexcept
  {
    for (auto& elem : e) {
      elem *= t;
    }

    return *this;
  }

  /// @brief Divide this vector by the given constant
  /// @param[in] t The scalar constant to divide the vector with
  /// @return This vector after it has been down-scaled by the given constant
  constexpr Vec3& operator/=(double t) noexcept
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

private:
  std::array<double, 3> e {0, 0, 0};

  /// @brief Write the given vector to an output stream
  /// @param[inout] out The output stream to which the vector is to be written
  /// @param[in] v The vector to be written to the output stream
  /// @return The output stream containing a string representation of the vector
  friend std::ostream& operator<<(std::ostream& out, Vec3 const& v) noexcept
  {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
  }

  /// @brief Perform component-wise addition of 2 vectors
  /// @param[in] u The first vector in the sum
  /// @param[in] v The second vector in the sum
  /// @return A new vector equal to the sum of the 2 vectors
  friend constexpr Vec3 operator+(Vec3 const& u, Vec3 const& v) noexcept
  {
    return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
  }

  /// @brief Perform component-wise subtraction of 2 vectors
  /// @param[in] u The first vector in the difference
  /// @param[in] v The second vector in the difference
  /// @return A new vector equal to the difference of the 2 vectors
  friend constexpr Vec3 operator-(Vec3 const& u, Vec3 const& v) noexcept
  {
    return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
  }

  /// @brief Perform component-wise multiplication of 2 vectors
  /// @param[in] u The first vector in the product
  /// @param[in] v The second vector in the product
  /// @return A new vector equal to the product of the 2 vectors
  friend constexpr Vec3 operator*(Vec3 const& u, Vec3 const& v) noexcept
  {
    return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
  }

  /// @brief Get a new vector equal to the given vector scaled by the given
  /// constant
  /// @param[in] t The scaling factor
  /// @param[in] v The vector to be scaled
  /// @return A new vector equal to the given vector scaled by the given scaling
  /// factor
  friend constexpr Vec3 operator*(double t, Vec3 const& v) noexcept
  {
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
  }

  /// @brief Get a new vector equal to the given vector scaled by the given
  /// constant
  /// @param[in] t The scaling factor
  /// @param[in] v The vector to be scaled
  /// @return A new vector equal to the given vector scaled by the given scaling
  /// factor
  friend constexpr Vec3 operator*(Vec3 const& v, double t) noexcept
  {
    return t * v;
  }

  /// @brief Get a new vector equal to the given vector scaled by the given
  /// constant
  /// @param[in] t The scaling factor
  /// @param[in] v The vector to be scaled
  /// @return A new vector equal to the given vector scaled by the given scaling
  /// factor
  friend constexpr Vec3 operator/(Vec3 const& v, double t) noexcept
  {
    return (1 / t) * v;
  }

  /// @brief Compare two Vec3 objects for equality
  /// @param[in] a The first Vec3 object
  /// @param[in] b The second Vec3 object
  /// @returns True if they are equal and false otherwise
  friend constexpr bool operator==(Vec3 const& a, Vec3 const& b) noexcept
  {
    return a.x() == b.x() and a.y() == b.y() and a.z() == b.z();
  }
};

/// @brief Get the dot product of 2 given vectors
/// @param[in] u The first vector in the operation
/// @param[in] v The second vector in the operation
/// @return The dot product of the 2 vectors
constexpr double getDotProduct(Vec3 const& u, Vec3 const& v) noexcept
{
  return (u.x() * v.x() + u.y() * v.y() + u.z() + v.z());
}

/// @brief Get the cross product of 2 given vectors
/// @param[in] u The first vector in the operation
/// @param[in] v The second vector in the operation
/// @return The cross product of the 2 vectors
constexpr Vec3 getCrossProduct(Vec3 const& u, Vec3 const& v) noexcept
{
  return Vec3(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(), u.x() * v.y() - u.y() * v.x());
}

/// @brief Get the unit vector of the given vector
/// @param[in] v The vector whose unit vector is to be computed
/// @return The unit vector of the given vector
constexpr Vec3 getUnitVector(Vec3 const& v) noexcept
{
  return v / v.length();
}
}   // namespace rt::vec3

#endif
