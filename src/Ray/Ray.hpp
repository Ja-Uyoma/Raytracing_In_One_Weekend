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

#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"

namespace rt::ray {
using Point3 = vec3::Vec3;

class Ray
{
public:
  /// @brief Default constructor
  constexpr explicit Ray() noexcept = default;

  /// @brief Constructor. Create a new Ray with the given origin and direction
  /// @param[in] origin The origin of the ray
  /// @param[in] direction The direction the ray is travelling towards
  constexpr explicit Ray(Point3 const& origin, vec3::Vec3 const& direction) noexcept
    : m_origin(origin), m_direction(direction)
  {
  }

  /// @brief Get the origin of this ray
  /// @return The origin of the ray
  constexpr Point3 const& getOrigin() const noexcept
  {
    return m_origin;
  }

  /// @brief Get the direction this ray is travelling towards
  /// @return The direction the ray is travelling towards
  constexpr vec3::Vec3 const& getDirection() const noexcept
  {
    return m_direction;
  }

  /// @brief Get the point a given distance from the ray's origin
  /// @param[in] t The distance from the ray's origin
  /// @return The point at the given distance from the ray's origin
  constexpr Point3 at(double t) const noexcept
  {
    return m_origin + (t * m_direction);
  }

private:
  Point3 m_origin;
  vec3::Vec3 m_direction;
};
}   // namespace rt::ray

#endif
