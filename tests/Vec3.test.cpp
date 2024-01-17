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

TEST_CASE("Accessors work as intended", "[Vec3]")
{
    constexpr auto vec = Vec3(1, 2, 3);

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
    constexpr auto vec = Vec3(1, 2, 3);
    constexpr auto negVec = -vec;

    REQUIRE(vec[0] == -negVec[0]);
    REQUIRE(vec[1] == -negVec[1]);
    REQUIRE(vec[2] == -negVec[2]);
}
