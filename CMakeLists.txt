cmake_minimum_required(VERSION 3.20)

# Only set the C++ standard if it has not already been set by someone else
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()

# Enabled globally to avoid conflicts between -Wpedantic being enabled and
# -std=c++20 and -std=gnu++20 for example when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name and language
project(RaytracingInOneWeekend
    VERSION 0.1.1
    DESCRIPTION "Raytracing in one weekend"
    HOMEPAGE_URL ""
    LANGUAGES CXX
)

include(cmake/EnforceOutOfSourceBuilds.cmake)

add_executable(app)

target_sources(app
    PRIVATE main.cpp
)

target_compile_features(app 
    PRIVATE cxx_std_20
)

target_compile_options(app
    PRIVATE -Wall -Wextra -Werror -pedantic
)