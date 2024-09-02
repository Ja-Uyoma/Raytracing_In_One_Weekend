#include "Ray.hpp"
#include "Vec3.hpp"

#include <catch2/catch_test_macros.hpp>

namespace rt {
[[nodiscard]]
constexpr bool operator==(Vec3 const &a, Vec3 const &b) noexcept {
  return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}

TEST_CASE("at gets the point a given distance from the ray origin", "[Ray]") {
  SECTION("All points lie on the origin regardless of distance for a "
          "default-constructed Ray") {
    constexpr auto ray = Ray();
    REQUIRE(ray.at(2) == Vec3(0, 0, 0));
  }

  SECTION(
      "Point at a given distance is dependent on ray origin and direction") {
    constexpr auto origin = Point3(1, 2, 3);
    constexpr auto direction = Point3(4, 5, 6);
    constexpr auto ray = Ray(origin, direction);

    REQUIRE(ray.at(2) == Vec3(9, 12, 15));
  }
}
} // namespace rt