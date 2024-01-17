#include "Vec3.hpp"

#include <catch2/catch_test_macros.hpp>

using rt::Vec3;

TEST_CASE("Vectors are constructed", "[Vec3]")
{
    SECTION("Zeroed out by default")
    {
        constexpr auto vec = Vec3();

        REQUIRE(vec[0] == 0);
        REQUIRE(vec[1] == 0);
        REQUIRE(vec[2] == 0);
    }

    SECTION("Given user-defined values")
    {
        constexpr auto vec = Vec3(1, 2, 3);

        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec[2] == 3);
    }
}
