# Raytracing In One Weekend

A simple raytracer, adapted from the Raytracing In One Weekend series.

## Description

### Background

## Getting Started

### Prerequisites

1. [CMake](https://cmake.org/), at least version 3.20
2. [Conan](https://conan.io/), at least version 2.6.0

### Installation

1. Clone the repository

```sh
git clone https://github.com/Ja-Uyoma/Raytracing_In_One_Weekend.git
```

2. Change into the project's directory

```sh
cd ./Raytracing_In_One_Weekend
```

3. Install the dependencies and set up the project

```sh
conan build conanfile.py --build=missing
```

4. Build the application

```sh
cmake --build build
```

5. Run the application and produce an image file as output

```sh
build/src/Debug/app > build/image.ppm
```

## License

This project is licensed under the MIT license. See LICENSE.md for more information

## References

1. [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

