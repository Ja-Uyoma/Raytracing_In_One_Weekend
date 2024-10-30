add_executable(tests)

find_package(Catch2 REQUIRED)

target_link_libraries(tests
    PRIVATE
        Catch2::Catch2WithMain
)

target_include_directories(tests
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/Ray"
        "${PROJECT_SOURCE_DIR}/src/Vec3"
        "${PROJECT_SOURCE_DIR}/src/Colour"
        "${PROJECT_SOURCE_DIR}/src/Main"
)

target_sources(tests
    PRIVATE
        Vec3.test.cpp
        Ray.test.cpp
        Colour.test.cpp
        "${PROJECT_SOURCE_DIR}/src/Colour/Colour.cpp"
        Main.test.cpp
        "${PROJECT_SOURCE_DIR}/src/Main/Main.cpp"
)

target_compile_features(tests
    PRIVATE
        cxx_std_20
)

target_compile_options(tests
    PRIVATE
        -Wall -Wextra -Werror -pedantic
)