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
#include <iostream>

namespace rt::colour {

class Colour
{
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
  explicit constexpr Colour(double r, double g, double b) noexcept : m_data {r, g, b}
  {
  }

  /**
   * @brief Create a Colour object from a Vec3 object
   * @param[in] v The Vec3 object from which the Colour object is to be created
   */
  constexpr explicit Colour(vec3::Vec3 const& v) noexcept : m_data(v)
  {
  }

  /**
   * @brief Get the red Colour value
   *
   * @return The red Colour value
   */
  constexpr double r() const noexcept
  {
    return m_data.x();
  }

  /**
   * @brief Get the green Colour value
   *
   * @return The green Colour value
   */
  constexpr double g() const noexcept
  {
    return m_data.y();
  }

  /**
   * @brief Get the blue Colour value
   *
   * @return The blue Colour value
   */
  constexpr double b() const noexcept
  {
    return m_data.z();
  }

  /**
   * @brief Add another vector to this vector
   *
   * @param other The vector to be added to this vector
   * @return constexpr Colour& This vector with its fields updated
   */
  constexpr Colour& operator+=(Colour const& other) noexcept
  {
    m_data += other.m_data;

    return *this;
  }

private:
  vec3::Vec3 m_data {};

  /// \brief Get the sum of two colours
  /// \param[in] first The first colour
  /// \param[in] second The second colour
  /// \returns A new colour from the sum of the two original colours
  friend constexpr Colour operator+(Colour const& first, Colour const& second) noexcept
  {
    return Colour(first.r() + second.r(), first.g() + second.g(), first.b() + second.b());
  }

  /// \brief Get the scalar multiple of a given colour
  /// \param[in] scalar The scalar to be multiplied with the original colour
  /// \param[in] colour The initial colour
  /// \returns A new colour from the scalar multiple of the original colour
  friend constexpr Colour operator*(double const scalar, Colour const& colour) noexcept
  {
    return Colour(scalar * colour.r(), scalar * colour.g(), scalar * colour.b());
  }

  /// \brief Determine whether two colours are equal or not
  /// \param[in] first The first colour
  /// \param[in] second The second colour
  /// \returns True if the colours are the same, and false otherwise
  friend constexpr bool operator==(Colour const& first, Colour const& second) noexcept
  {
    return (first.r() == second.r()) and (first.g() == second.g()) and (first.b() == second.b());
  }

  /// Multiply two colours
  /// \param[in] first The first colour
  /// \param[in] second The second colour
  /// \returns A new colour equal from the product of the two colours
  friend constexpr Colour operator*(Colour const& first, Colour const& second) noexcept
  {
    return Colour(first.m_data * second.m_data);
  }
};

/// \brief Map each individual colour component to the range [0, 255]
/// \param[in] colour The colour to be mapped to the specified range
/// \param[in] samplesPerPixel The number of samples of each pixel
/// \returns A new colour whose colour components lie within the [0, 255] range
[[nodiscard]] Colour mapToByteRange(Colour const& colour, int samplesPerPixel) noexcept;

/// @brief Write the value of each colour component to the given output stream
/// @param[inout] out The output stream to write to
/// @param[in] pixelColour The colour of a single pixel in RGB format
void writeColour(std::ostream& out, Colour const& pixelColour) noexcept;

}   // namespace rt::colour

#endif
