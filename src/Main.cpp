#include "Colour.hpp"
#include "Ray.hpp"

#include <iostream>

namespace rt
{
    struct Image
    {
        int width;
        int height;
    };

    /// \brief Get the colour for a given scene ray
    /// \param[in] ray A ray for a scene
    /// \returns The colour for a given scene ray
    constexpr Colour getRayColour([[maybe_unused]] Ray const& ray) noexcept
    {
        return Colour(0, 0, 0);
    }

    /// @brief Render a 256 px by 256 px PPM image
    void renderImage() 
    {
        constexpr Image img { .width = 256, .height = 256 };

        std::cout << "P3\n" << img.width << ' ' << img.height << "\n255\n";

        for (int j = 0; j < img.height; ++j) 
        {
            std::clog << "\rScanlines remaining: " << (img.height - j) << '\n' << std::flush;

            for (int i = 0; i < img.width; ++i) 
            {
                auto pixelColour = Colour(
                    static_cast<double>(i) / (img.width - 1),
                    static_cast<double>(j) / (img.height - 1),
                    0
                );

                writeColour(std::cout, pixelColour);
            }
        }

        std::clog << "\rDone.            \n";
    }
}