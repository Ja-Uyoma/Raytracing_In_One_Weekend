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

#ifndef POINT3_HPP
#define POINT3_HPP

#include <array>

namespace rt::ray {

class Point3 {
public:
  /**
   * @brief Create a default Point3 instance
   *
   */
  explicit constexpr Point3() noexcept = default;

  /**
   * @brief Create a Point3 instance with the specified x, y, and z values
   *
   * @param[in] x The value in the x-plane
   * @param[in] y The value in the y-plane
   * @param[in] z The value in the z-plane
   */
  explicit constexpr Point3(double x, double y, double z) noexcept
      : m_data{x, y, z} {}

  /**
   * @brief Get the x value
   *
   * @return The x value
   */
  constexpr double x() const noexcept { return m_data[0]; }

  /**
   * @brief Get the y value
   *
   * @return The y value
   */
  constexpr double y() const noexcept { return m_data[1]; }

  /**
   * @brief Get the z value
   *
   * @return The z value
   */
  constexpr double z() const noexcept { return m_data[2]; }

private:
  std::array<double, 3> m_data{0, 0, 0};
};

} // namespace rt::ray

#endif
