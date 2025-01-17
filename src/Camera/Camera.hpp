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

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Ray.hpp"
#include "Vec3.hpp"

namespace rt::camera {

class Camera
{
public:
  /// Default constructor
  constexpr explicit Camera() noexcept
  {
    constexpr auto aspectRatio = 16.0 / 9.0;
    constexpr auto viewportHeight = 2.0;
    constexpr auto viewportWidth = aspectRatio * viewportHeight;
    constexpr auto focalLength = 1.0;

    m_horizontal = vec3::Vec3(viewportWidth, 0, 0);
    m_vertical = vec3::Vec3(0, viewportHeight, 0);
    m_lowerLeftCorner = m_origin - (m_horizontal / 2) - (m_vertical / 2) - vec3::Vec3(0, 0, focalLength);
  }

  ///
  /// \param[in] u
  /// \param[in] v
  /// \returns
  constexpr ray::Ray getRay(double u, double v) const noexcept
  {
    return ray::Ray(m_origin, m_lowerLeftCorner + (u * m_horizontal) + (v * m_vertical) - m_origin);
  }

private:
  ray::Point3 m_origin {0, 0, 0};
  ray::Point3 m_lowerLeftCorner {};
  vec3::Vec3 m_horizontal {};
  vec3::Vec3 m_vertical {};
};

}   // namespace rt::camera

#endif
