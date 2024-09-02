add_executable(tests)

set(includeDir "${CMAKE_SOURCE_DIR}/include")

find_package(Catch2 REQUIRED)

target_link_libraries(tests
    PUBLIC
        Catch2::Catch2WithMain
)

target_include_directories(tests
    PUBLIC
        "${includeDir}"
        "${PROJECT_SOURCE_DIR}/src/Ray"
        "${PROJECT_SOURCE_DIR}/src/Vec3"
)

target_sources(tests
    PUBLIC 
        Vec3.test.cpp
        Ray.test.cpp
        "${PROJECT_SOURCE_DIR}/src/Ray/Ray.hpp"
        "${PROJECT_SOURCE_DIR}/src/Vec3/Vec3.hpp"
)

target_compile_features(tests
    PRIVATE
        cxx_std_20
)

target_compile_options(tests
    PRIVATE
        -Wall -Wextra -Werror -pedantic
)