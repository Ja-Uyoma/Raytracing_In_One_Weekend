cmake_minimum_required(VERSION 3.20)

# Only set the C++ standard if it has not already been set by someone else
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif()

# Enabled globally to avoid conflicts between -Wpedantic being enabled and
# -std=c++20 and -std=gnu++20 for example when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name and language
project(RaytracingInOneWeekend
    VERSION 0.1.1
    DESCRIPTION "Raytracing in one weekend"
    HOMEPAGE_URL ""
    LANGUAGES CXX
)

include(cmake/EnforceOutOfSourceBuilds.cmake)

add_subdirectory(src)

# We don't want to consider testing if we're not top-level
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()

# Include the CTest module
include(CTest)

if (BUILD_TESTING)
    message("Building tests...")
    add_subdirectory(tests)
endif()
