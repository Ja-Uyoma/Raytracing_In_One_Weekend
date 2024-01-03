#include <iostream>

namespace rt
{
    struct Image
    {
        int width;
        int height;
    };

    /// @brief Render a 256 px by 256 px PPM image
    void renderImage() 
    {
        Image img { .width = 256, .height = 256 };

        std::cout << "P3\n" << img.width << ' ' << img.height << "\n255\n";

        for (int j = 0; j < img.height; ++j) 
        {
            std::clog << "\rScanlines remaining: " << (img.height - j) << '\n' << std::flush;

            for (int i = 0; i < img.width; ++i) 
            {
                auto r = static_cast<double>(i) / (img.width - 1);
                auto g = static_cast<double>(j) / (img.height - 1);
                auto b = 0;

                auto ir = static_cast<int>(255.999 * r);
                auto ig = static_cast<int>(255.999 * g);
                auto ib = static_cast<int>(255.999 * b);

                std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }

        std::clog << "\rDone.            \n";
    }
}