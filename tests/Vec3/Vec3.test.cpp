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

#include "Vec3.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cmath>

namespace rt {
TEST_CASE("Vectors are constructed", "[Vec3]")
{
  SECTION("Zeroed out by default")
  {
    constexpr auto vec = vec3::Vec3();

    REQUIRE(vec[0] == 0);
    REQUIRE(vec[1] == 0);
    REQUIRE(vec[2] == 0);
  }

  SECTION("Given user-defined values")
  {
    constexpr auto vec = vec3::Vec3(1, 2, 3);

    REQUIRE(vec[0] == 1);
    REQUIRE(vec[1] == 2);
    REQUIRE(vec[2] == 3);
  }
}

TEST_CASE("Accessors work as intended", "[Vec3]")
{
  constexpr auto vec = vec3::Vec3(1, 2, 3);

  SECTION("x() gets the x-coordinate only")
  {
    REQUIRE(vec.x() == vec[0]);
    REQUIRE(vec.x() != vec[1]);
    REQUIRE(vec.x() != vec[2]);
  }

  SECTION("y() gets the y-coordinate only")
  {
    REQUIRE(vec.y() == vec[1]);
    REQUIRE(vec.y() != vec[0]);
    REQUIRE(vec.y() != vec[2]);
  }

  SECTION("z() gets the z-coordinate only")
  {
    REQUIRE(vec.z() == vec[2]);
    REQUIRE(vec.z() != vec[0]);
    REQUIRE(vec.z() != vec[1]);
  }
}

TEST_CASE("Negation is applied component-wise", "[Vec3]")
{
  constexpr auto vec = vec3::Vec3(1, 2, 3);
  constexpr auto negVec = -vec;

  REQUIRE(vec[0] == -negVec[0]);
  REQUIRE(vec[1] == -negVec[1]);
  REQUIRE(vec[2] == -negVec[2]);
}

TEST_CASE("Addition is performed component-wise", "[Vec3]")
{
  constexpr auto first = vec3::Vec3(1, 2, 3);
  auto second = vec3::Vec3(4, 5, 6);

  SECTION("values before addition")
  {
    REQUIRE(second[0] == 4);
    REQUIRE(second[1] == 5);
    REQUIRE(second[2] == 6);
  }

  SECTION("values after addition")
  {
    second += first;

    REQUIRE(second[0] == (4 + 1));
    REQUIRE(second[1] == (5 + 2));
    REQUIRE(second[2] == (6 + 3));
  }
}

TEST_CASE("Scalar operations are performed component-wise", "[Vec3]")
{
  auto vec = vec3::Vec3(1, 2, 3);

  SECTION("Scalar multiplication")
  {
    vec *= 4;

    REQUIRE(vec[0] == (1 * 4));
    REQUIRE(vec[1] == (2 * 4));
    REQUIRE(vec[2] == (3 * 4));
  }

  SECTION("Scalar division")
  {
    vec /= 2;

    REQUIRE(vec[0] == (1.0 / 2.0));
    REQUIRE(vec[1] == (2.0 / 2.0));
    REQUIRE(vec[2] == (3.0 / 2.0));
  }
}

TEST_CASE("The length is computed", "[Vec3]")
{
  constexpr auto vec = vec3::Vec3(1, 2, 3);

  REQUIRE(vec.length() == std::sqrt(14));
}

TEST_CASE("Method lengthSquared gets the sum of the squares of the vector's components", "[Vec3]")
{
  constexpr auto vec = vec3::Vec3(1, 2, 3);
  REQUIRE(vec.lengthSquared() == vec3::getDotProduct(vec, vec));
}
}   // namespace rt
