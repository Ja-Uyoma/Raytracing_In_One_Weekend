#include "Colour.hpp"

#include <catch2/catch_test_macros.hpp>

namespace rt::colour {

TEST_CASE("getters get the corresponding colour component value", "[Colour]") {
  constexpr auto colour = colour::Colour(100.0, 50.0, 25.0);

  SECTION("method r() gets the red colour value") {
    REQUIRE(colour.r() == 100.0);
  }

  SECTION("method g() gets the green colour value") {
    REQUIRE(colour.g() == 50.0);
  }

  SECTION("method b() gets the blue colour value") {
    REQUIRE(colour.b() == 25.0);
  }
}

TEST_CASE("operator+", "[Colour]") {
  SECTION("creates a new colour from the sum of two initial colours") {
    constexpr auto first = Colour(100.0, 50.0, 25.0);
    constexpr auto second = Colour(15, 80, 49);
    constexpr auto result = first + second;

    REQUIRE(result.r() == first.r() + second.r());
    REQUIRE(result.g() == first.g() + second.g());
    REQUIRE(result.b() == first.b() + second.b());
  }
}

TEST_CASE("operator*", "[Colour]") {
  SECTION("creates a new colour that is a scalar multiple of the initial one") {
    constexpr auto initial = Colour(10, 20, 30);
    constexpr auto scalar = 8;
    constexpr auto result = scalar * initial;

    REQUIRE(result.r() == initial.r() * scalar);
    REQUIRE(result.g() == initial.g() * scalar);
    REQUIRE(result.b() == initial.b() * scalar);
  }
}

} // namespace rt::colour