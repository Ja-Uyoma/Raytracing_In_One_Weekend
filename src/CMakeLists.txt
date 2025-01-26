add_executable(app)

target_include_directories(app
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

target_sources(app
    PRIVATE
        main.cpp 
        "${PROJECT_SOURCE_DIR}/src/Main/Main.cpp"
        "${PROJECT_SOURCE_DIR}/src/Colour/Colour.cpp"
        "${PROJECT_SOURCE_DIR}/src/Sphere/Sphere.cpp"
        "${PROJECT_SOURCE_DIR}/src/Hittable/HittableList.cpp"
        "${PROJECT_SOURCE_DIR}/src/Utilities/Utilities.cpp"
        "${PROJECT_SOURCE_DIR}/src/Vec3/Vec3.cpp"
        "${PROJECT_SOURCE_DIR}/src/Material/Lambertian.cpp"
        "${PROJECT_SOURCE_DIR}/src/Material/Metal.cpp"
        "${PROJECT_SOURCE_DIR}/src/Material/Dielectric.cpp"
        "${PROJECT_SOURCE_DIR}/src/Camera/Camera.cpp"
)

target_compile_features(app 
    PRIVATE 
        cxx_std_20
)

target_compile_options(app
    PRIVATE 
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Werror -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/Wall>
)
