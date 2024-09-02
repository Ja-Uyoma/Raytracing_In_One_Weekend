#ifndef COLOUR_HPP
#define COLOUR_HPP

#include "Vec3.hpp"

#include <iostream>

namespace rt {

using Colour = Vec3;

/// @brief Write the value of each colour component to the given output stream
/// @param out The output stream to write to
/// @param pixelColour The colour of a single pixel in RGB format
void writeColour(std::ostream &out, Colour const &pixelColour) noexcept;

} // namespace rt

#endif