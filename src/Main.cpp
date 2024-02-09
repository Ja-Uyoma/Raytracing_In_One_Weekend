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

        // Camera
        constexpr auto focalLength { 1.0 };
        constexpr auto viewportHeight { 2.0 };
        auto viewportWidth = viewportHeight * (static_cast<double>(img.width) / img.height);
        constexpr auto cameraCenter = Point3(0, 0, 0);

        // Calculate the vectors across the horizontal and down the vertical viewport edges
        auto viewportU = Vec3(viewportWidth, 0, 0);
        auto viewportV = Vec3(0, -viewportHeight, 0);

        // Calculate the horizontal and vertical delta vectors from pixel to pixel
        auto pixelDeltaU = viewportU / img.width;
        auto pixelDeltaV = viewportV / img.height;

        // Calculate the location of the upper-left pixel
        auto viewportUpperLeft = cameraCenter - Vec3(0, 0, focalLength) - (viewportU / 2) - (viewportV / 2);
        auto pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

        std::cout << "P3\n" << img.width << ' ' << img.height << "\n255\n";

        for (int j = 0; j < img.height; ++j) 
        {
            std::clog << "\rScanlines remaining: " << (img.height - j) << '\n' << std::flush;

            for (int i = 0; i < img.width; ++i) 
            {
                auto pixelCenter = pixel00Loc + (i * pixelDeltaU) + (j * pixelDeltaV);
                auto rayDirection = pixelCenter - cameraCenter;
                auto ray = Ray(cameraCenter, rayDirection);

                auto pixelColour = Colour(getRayColour(ray));
                writeColour(std::cout, pixelColour);
            }
        }

        std::clog << "\rDone.            \n";
    }
}