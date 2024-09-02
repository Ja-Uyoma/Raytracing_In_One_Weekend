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

#ifndef COLOUR_HPP
#define COLOUR_HPP

#include "Vec3.hpp"

#include <array>
#include <iostream>

namespace rt::colour {

class Colour {
public:
  /**
   * @brief Create a default Colour instance
   *
   */
  explicit constexpr Colour() noexcept = default;

  /**
   * @brief Create a Colour instance with the specified r, g, and b values
   *
   * @param[in] r The red colour value
   * @param[in] b The blue colour value
   * @param[in] g The green colour value
   */
  explicit constexpr Colour(double r, double g, double b) noexcept
      : m_data{r, g, b} {}

  /**
   * @brief Get the red Colour value
   *
   * @return The red Colour value
   */
  constexpr double const &r() const noexcept { return m_data[0]; }

  /**
   * @brief Get the green Colour value
   *
   * @return The green Colour value
   */
  constexpr double const &g() const noexcept { return m_data[1]; }

  /**
   * @brief Get the blue Colour value
   *
   * @return The blue Colour value
   */
  constexpr double const &b() const noexcept { return m_data[2]; }

private:
  std::array<double, 3> m_data{0, 0, 0};
};

/// @brief Write the value of each colour component to the given output stream
/// @param out The output stream to write to
/// @param pixelColour The colour of a single pixel in RGB format
void writeColour(std::ostream &out, Colour const &pixelColour) noexcept;

} // namespace rt::colour

#endif