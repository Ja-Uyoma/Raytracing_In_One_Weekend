add_executable(tests)

find_package(Catch2 REQUIRED)

target_link_libraries(tests
    PUBLIC
        Catch2::Catch2WithMain
)

target_include_directories(tests
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/Ray"
        "${PROJECT_SOURCE_DIR}/src/Vec3"
)

target_sources(tests
    PUBLIC 
        Vec3.test.cpp
        Ray.test.cpp
)

target_compile_features(tests
    PRIVATE
        cxx_std_20
)

target_compile_options(tests
    PRIVATE
        -Wall -Wextra -Werror -pedantic
)