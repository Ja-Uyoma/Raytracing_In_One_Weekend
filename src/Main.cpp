#include "Colour.hpp"
#include "Ray.hpp"

#include <iostream>
#include <functional>

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
        constexpr auto aspectRatio = 16.0 / 9.0;
        
        Image img;
        img.width = 400;
        img.height = std::invoke([&img] {
            auto height = static_cast<int>(img.width / aspectRatio);

            if (height < 1) {
                height = 1;
            }

            return height;
        });


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