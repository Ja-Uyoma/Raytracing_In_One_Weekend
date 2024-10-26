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

#ifndef MAIN_HPP
#define MAIN_HPP

#include "Colour.hpp"
#include "Ray.hpp"

namespace rt {

/// \brief Determine if a ray has hit the sphere in the viewport
/// \param[in] centre The centre of the sphere
/// \param[in] radius The radius of the sphere
/// \param[in] ray The ray under test
/// \returns True if the ray has hit the sphere, and false otherwise
constexpr bool rayHasHitSphere(ray::Point3 const &centre, double const radius,
                               ray::Ray const &ray) noexcept {
  // Get the vector from the ray origin to the sphere centre
  auto const oc = ray.getOrigin() - centre;

  // The equation of a ray is P(t) = A + tb, where P is a 3D position along a
  // line, A is the ray origin, b is the ray direction, and t is a scalar
  // value.
  // We want to know if our ray ever hits the sphere anywhere. If it
  // does, there is some t for which P(t) satisfies the sphere equation:
  // (P - C) * (P - C) = r^2
  // So we are looking for any t where (P(t)) - C * (P(t) - C) = r^2, or
  // (A + tb - C) * (A + tb - C) = r^2
  // If we expand this equation and move all the terms to the left-hand side,
  // we get the following equation:
  // (t^2b * b) + 2tb * (A - C) + (A - C) * (A - C) - r^2 = 0
  // The vectors and r in this equation are all constant and known. The unknown
  // is t, thus making this quadratic
  // Recall the quadratic formula, x = (-b ± sqrt(b^2 - 4ac) / 2a).
  // We now proceed to calculate our a, b, and c values.

  auto const a = vec3::getDotProduct(ray.getDirection(), ray.getDirection());
  auto const b = 2.0 * vec3::getDotProduct(oc, ray.getDirection());
  auto const c = vec3::getDotProduct(oc, oc) - (radius * radius);

  auto const discriminant = (b * b) - (4 * a * c);
  return discriminant > 0;
}

/// \brief Produce a linear blend of white and blue colours
/// \param[in] ray The ray whose colour is to be computed
/// \returns A linear blend of white and blue colours
colour::Colour rayColour(ray::Ray const &ray) noexcept;

/// \brief Render a 256 px by 256 px PPM image
void renderImage();

} // namespace rt

#endif
