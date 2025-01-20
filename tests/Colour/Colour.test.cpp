#include "Colour.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string_view>

namespace rt::colour {

TEST_CASE("getters get the corresponding colour component value", "[Colour]")
{
  constexpr auto colour = colour::Colour(100.0, 50.0, 25.0);

  SECTION("method r() gets the red colour value")
  {
    REQUIRE(colour.r() == 100.0);
  }

  SECTION("method g() gets the green colour value")
  {
    REQUIRE(colour.g() == 50.0);
  }

  SECTION("method b() gets the blue colour value")
  {
    REQUIRE(colour.b() == 25.0);
  }
}

TEST_CASE("operator+", "[Colour]")
{
  SECTION("creates a new colour from the sum of two initial colours")
  {
    constexpr auto first = Colour(100.0, 50.0, 25.0);
    constexpr auto second = Colour(15, 80, 49);
    constexpr auto result = first + second;

    REQUIRE(result == first + second);
  }
}

TEST_CASE("operator*", "[Colour]")
{
  SECTION("creates a new colour that is a scalar multiple of the initial one")
  {
    constexpr auto initial = Colour(10, 20, 30);
    constexpr auto scalar = 8;
    constexpr auto result = scalar * initial;

    REQUIRE(result == scalar * initial);
  }
}

TEST_CASE("mapToByteRange", "[Colour]")
{
  SECTION("Maps each individual colour component to the range [0, 255]")
  {
    constexpr auto colour = Colour(0.5, 0.7, 1.0);
    auto const result = mapToByteRange(colour, 1);

    REQUIRE((result.r() >= 0 and result.r() <= 255));
    REQUIRE((result.g() >= 0 and result.g() <= 255));
    REQUIRE((result.b() >= 0 and result.b() <= 255));
  }
}

TEST_CASE("writeColour", "[Colour]")
{
  SECTION("it writes the translated colour values to an output stream")
  {
    auto ss = std::stringstream {};
    constexpr auto colour = Colour(0.1, 0.2, 0.3);

    writeColour(ss, colour);

    REQUIRE(ss.view() == std::string_view("0.1 0.2 0.3\n"));
  }
}

}   // namespace rt::colour
