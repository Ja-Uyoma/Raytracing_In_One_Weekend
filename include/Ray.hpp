#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"

namespace rt
{
    using Point3 = Vec3;

    class Ray
    {
    public:
        /// @brief Default constructor
        constexpr Ray() noexcept = default;

        /// @brief Constructor. Create a new Ray with the given origin and direction
        /// @param origin The origin of the ray
        /// @param direction The direction the ray is travelling towards
        constexpr Ray(Point3 const& origin, Vec3 const& direction) noexcept
        :   m_origin(origin), m_direction(direction)
        {
        }

        /// @brief Get the origin of this ray
        /// @return The origin of the ray
        constexpr Point3 const& getOrigin() const noexcept
        {
            return m_origin;
        }

        /// @brief Get the direction this ray is travelling towards
        /// @return The direction the ray is travelling towards
        constexpr Vec3 const& getDirection() const noexcept
        {
            return m_direction;
        }

    private:
        Point3 m_origin;
        Vec3 m_direction;
    };
} // namespace rt


#endif