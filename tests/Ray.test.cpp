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

#include "Ray.hpp"
#include "Vec3.hpp"

#include <catch2/catch_test_macros.hpp>

namespace rt::ray {

TEST_CASE("at gets the point a given distance from the ray origin", "[Ray]") {
  SECTION("All points lie on the origin regardless of distance for a "
          "default-constructed Ray") {
    constexpr auto ray = Ray();
    REQUIRE((ray.at(2) == vec3::Vec3(0, 0, 0)) == true);
  }

  SECTION(
      "Point at a given distance is dependent on ray origin and direction") {
    constexpr auto origin = Point3(1, 2, 3);
    constexpr auto direction = vec3::Vec3(4, 5, 6);
    constexpr auto ray = Ray(origin, direction);

    REQUIRE((ray.at(2) == vec3::Vec3(9, 12, 15)) == true);
  }
}
} // namespace rt::ray