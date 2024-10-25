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

#include "Main.hpp"
#include "Colour/Colour.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"

#include <cstddef>
#include <iostream>

namespace rt {

/// \brief Produce a linear blend of white and blue colours
/// \param[in] ray The ray whose colour is to be computed
/// \returns A linear blend of white and blue colours
colour::Colour rayColour(ray::Ray const &ray) noexcept {
  // Get the ray direction and scale it to unit length (so -1.0 < y < 1.0)
  // Because we're using the y height after normalizing the vector, there'll be
  // a horizontal gradient to the colour in addition to the vertical gradient
  auto const unitDirection = vec3::getUnitVector(ray.getDirection());

  // Take the y height and scale it to the range 0.0 <= t <= 1.0
  auto const t = 0.5 * (unitDirection.y() + 1.0);

  // When t = 1.0, we'll have the colour blue
  // When t = 0.0, we'll have the colour white
  // In between, we'll have a blend of colours
  // This produces a linear interpolation of the start and end colours
  static constexpr auto start = colour::Colour(1.0, 1.0, 1.0);
  static constexpr auto end = colour::Colour(0.5, 0.7, 1.0);

  return (1.0 - t) * start + t * end;
}

/// \brief Determine if a ray has hit the sphere in the viewport
/// \param[in] centre The centre of the sphere
/// \param[in] radius The radius of the sphere
/// \param[in] ray The ray under test
/// \returns True if the ray has hit the sphere, and false otherwise
constexpr bool rayHasHitSphere(ray::Point3 const &centre, double const radius,
                               ray::Ray const &ray) noexcept {
  // Get the vector from the ray origin to the sphere centre
  auto const oc = ray.getOrigin() - centre;

  // Recall the quadratic formula, x = (-b ± sqrt(b^2 - 4ac) / 2a)
  // We now proceed to calculate our a, b, and c values

  auto const a = vec3::getDotProduct(ray.getDirection(), ray.getDirection());
  auto const b = 2.0 * vec3::getDotProduct(oc, ray.getDirection());
  auto const c = vec3::getDotProduct(oc, oc) - (radius * radius);

  auto const discriminant = (b * b) - (4 * a * c);
  return discriminant > 0;
}

/// @brief Render a 256 px by 256 px PPM image
void renderImage() {
  // Image

  static constexpr auto aspectRatio{16.0 / 9.0};
  static constexpr std::size_t imgWidth{400};
  static constexpr std::size_t imgHeight{
      static_cast<size_t>(imgWidth / aspectRatio)};

  // Camera

  static constexpr auto viewportHeight{2.0};
  static constexpr auto viewportWidth{aspectRatio * viewportHeight};
  static constexpr auto focalLength{1.0};

  static constexpr auto origin = ray::Point3(0, 0, 0);
  static constexpr auto horizontal = vec3::Vec3(viewportWidth, 0, 0);
  static constexpr auto vertical = vec3::Vec3(0, viewportHeight, 0);
  static constexpr auto lowerLeftCorner =
      origin - horizontal / 2 - vertical / 2 - vec3::Vec3(0, 0, focalLength);

  // Render

  std::cout << "P3\n" << imgWidth << ' ' << imgHeight << "\n255\n";

  for (std::size_t j = imgHeight - 1; j < imgHeight; --j) {
    std::clog << "\rScanlines remaining: " << j << '\n' << std::flush;

    for (std::size_t i = 0; i < imgWidth; ++i) {
      auto const u = static_cast<double>(i) / (imgWidth - 1);
      auto const v = static_cast<double>(j) / (imgHeight - 1);
      auto const ray = ray::Ray(origin, lowerLeftCorner + u * horizontal +
                                            v * vertical - origin);

      auto pixelColour = rayColour(ray);
      auto const colour = colour::mapToByteRange(pixelColour);
      colour::writeColour(std::cout, colour);
    }
  }

  std::clog << "\rDone.            \n";
}
} // namespace rt