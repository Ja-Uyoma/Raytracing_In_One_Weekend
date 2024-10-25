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

} // namespace rt::colour