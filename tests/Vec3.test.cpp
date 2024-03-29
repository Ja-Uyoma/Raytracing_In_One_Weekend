#include "Vec3.hpp"

#include <cmath>
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

TEST_CASE("Addition is performed component-wise", "[Vec3]")
{
    constexpr auto first = Vec3(1, 2, 3);
    auto second = Vec3(4, 5, 6);
    
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
    auto vec = Vec3(1, 2, 3);

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
    constexpr auto vec = Vec3(1, 2, 3);

    REQUIRE(vec.length() == std::sqrt(14));
}
