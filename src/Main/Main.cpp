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

#include "Camera.hpp"
#include "Colour.hpp"
#include "Dielectric.hpp"
#include "Hittable.hpp"
#include "HittableList.hpp"
#include "Lambertian.hpp"
#include "Material.hpp"
#include "Metal.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Utilities.hpp"
#include "Vec3.hpp"
#include <cstddef>
#include <iostream>

namespace rt {

using colour::Colour;
using sphere::Sphere;
using namespace hittable;
using namespace ray;
using namespace material;

/// \brief Produce a linear blend of white and blue colours
/// \param[in] ray The ray whose colour is to be computed
/// \returns A linear blend of white and blue colours
Colour rayColour(Ray const& ray, Hittable const& world, int depthOfRecursion) noexcept
{
  HitRecord record;

  if (depthOfRecursion <= 0) {
    return Colour(0, 0, 0);
  }

  if (world.hit(ray, 0.001, rt::infinity, record)) {
    auto scattered = Ray();
    auto attenuation = Colour();

    if (record.materialPtr->scatter(ray, record, attenuation, scattered)) {
      return attenuation * rayColour(scattered, world, depthOfRecursion - 1);
    }

    return Colour(0, 0, 0);
  }

  auto const unitDirection = vec3::getUnitVector(ray.getDirection());
  auto const t = 0.5 * (unitDirection.y() + 1.0);

  // When t = 1.0, we'll have the colour blue
  // When t = 0.0, we'll have the colour white
  // In between, we'll have a blend of colours
  // This produces a linear interpolation of the start and end colours
  static constexpr auto start = Colour(1.0, 1.0, 1.0);
  static constexpr auto end = Colour(0.5, 0.7, 1.0);

  return (1.0 - t) * start + t * end;
}

/// Create a random scene
/// \returns A HittableList instance containing random scene data
hittable::HittableList randomScene()
{
  HittableList world;

  world.add(new Sphere(Point3(0, -1000, 0), 1000, new Lambertian(Colour(0.5, 0.5, 0.5))));

  for (int a = -11; a < 11; ++a) {
    for (int b = -11; b < 11; ++b) {
      auto const chooseMaterial = getRandomDouble();
      auto const centre = Point3(a + 0.9 * getRandomDouble(), 0.2, b + 0.9 * getRandomDouble());

      if ((centre - Point3(4, 0.2, 0)).length() > 0.9) {
        // Diffuse
        if (chooseMaterial < 0.8) {
          auto const albedo = Colour::getRandomColour() * Colour::getRandomColour();
          world.add(new Sphere(centre, 0.2, new Lambertian(albedo)));
        }
        // Metal
        else if (chooseMaterial < 0.95) {
          auto const albedo = Colour::getRandomColour(0.5, 1);
          auto const fuzz = getRandomDoubleInRange(0, 0.5);
          world.add(new Sphere(centre, 0.2, new Metal(albedo, fuzz)));
        }
        // Glass
        else {
          world.add(new Sphere(centre, 0.2, new Dielectric(1.5)));
        }
      }
    }
  }

  world.add(new Sphere(Point3(0, 1, 0), 1.0, new Dielectric(1.5)));
  world.add(new Sphere(Point3(-4, 1, 0), 1.0, new Lambertian(Colour(0.4, 0.2, 0.1))));
  world.add(new Sphere(Point3(4, 1, 0), 1.0, new Metal(Colour(0.7, 0.6, 0.5), 0.0)));

  return world;
}

/// @brief Render a 256 px by 256 px PPM image
void renderImage()
{
  // Image

  static constexpr auto aspectRatio {16.0 / 9.0};
  static constexpr std::size_t imgWidth {400};
  static constexpr std::size_t imgHeight {static_cast<size_t>(imgWidth / aspectRatio)};
  static constexpr std::size_t samplesPerPixel = 100;
  static constexpr int maxDepth = 50;

  // World

  HittableList world = randomScene();

  // Camera

  static constexpr auto lookFrom = Point3(13, 2, 3);
  static constexpr auto lookAt = Point3(0, 0, 0);
  static constexpr auto viewUp = vec3::Vec3(0, 1, 0);
  auto const distanceToFocus = 10.0;
  static constexpr auto aperture = 0.1;

  camera::Camera camera(lookFrom, lookAt, viewUp, 20, aspectRatio, aperture, distanceToFocus);

  // Render

  std::cout << "P3\n" << imgWidth << ' ' << imgHeight << "\n255\n";

  for (std::size_t j = imgHeight - 1; j < imgHeight; --j) {
    std::clog << "\rScanlines remaining: " << j << '\n' << std::flush;

    for (std::size_t i = 0; i < imgWidth; ++i) {
      Colour pixelColour(0, 0, 0);

      for (std::size_t s = 0; s < samplesPerPixel; ++s) {
        auto u = (static_cast<double>(i) + getRandomDouble()) / (imgWidth - 1);
        auto v = (static_cast<double>(j) + getRandomDouble()) / (imgHeight - 1);
        Ray ray = camera.getRay(u, v);
        pixelColour += rayColour(ray, world, maxDepth);
      }

      auto const colour = colour::mapToByteRange(pixelColour, samplesPerPixel);
      colour::writeColour(std::cout, colour);
    }
  }

  std::clog << "\rDone.            \n";
}
}   // namespace rt
