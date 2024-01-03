#include <cstdlib>
#include <iostream>

int main()
{
    int imageWidth = 256;
    int imageHeight = 256;

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; ++j) 
    {
        for (int i = 0; i < imageWidth; ++i) 
        {
            auto r = static_cast<double>(i) / (imageWidth - 1);
            auto g = static_cast<double>(j) / (imageHeight - 1);
            auto b = 0;

            auto ir = static_cast<int>(255.999 * r);
            auto ig = static_cast<int>(255.999 * g);
            auto ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return EXIT_SUCCESS;
}