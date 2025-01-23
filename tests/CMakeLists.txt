add_executable(tests)

find_package(Catch2 REQUIRED)

target_link_libraries(tests
    PRIVATE
        Catch2::Catch2WithMain
)

include(Catch)

target_include_directories(tests
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/Ray"
        "${PROJECT_SOURCE_DIR}/src/Vec3"
        "${PROJECT_SOURCE_DIR}/src/Colour"
        "${PROJECT_SOURCE_DIR}/src/Main"
        "${PROJECT_SOURCE_DIR}/src/Hittable"
        "${PROJECT_SOURCE_DIR}/src/Sphere"
        "${PROJECT_SOURCE_DIR}/src/Utilities"
        "${PROJECT_SOURCE_DIR}/src/Camera"
        "${PROJECT_SOURCE_DIR}/src/Material"
)

target_sources(tests
    PRIVATE
        Vec3/Vec3.test.cpp
        Ray/Ray.test.cpp
        Colour/Colour.test.cpp
        "${PROJECT_SOURCE_DIR}/src/Colour/Colour.cpp"
        Main/Main.test.cpp
        "${PROJECT_SOURCE_DIR}/src/Main/Main.cpp"
        "${PROJECT_SOURCE_DIR}/src/Sphere/Sphere.cpp"
        "${PROJECT_SOURCE_DIR}/src/Hittable/HittableList.cpp"
        "${PROJECT_SOURCE_DIR}/src/Utilities/Utilities.cpp"
        "${PROJECT_SOURCE_DIR}/src/Vec3/Vec3.cpp"
        "${PROJECT_SOURCE_DIR}/src/Material/Lambertian.cpp"
        "${PROJECT_SOURCE_DIR}/src/Material/Metal.cpp"
)

target_compile_features(tests
    PRIVATE
        cxx_std_20
)

target_compile_options(tests
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Werror -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall>
)

catch_discover_tests(tests)
