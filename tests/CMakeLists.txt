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
)

target_sources(tests
    PRIVATE 
        Vec3.test.cpp
    PUBLIC
        "${includeDir}/Vec3.hpp"
)

target_compile_features(tests
    PRIVATE
        cxx_std_20
)

target_compile_options(tests
    PRIVATE
        -Wall -Wextra -Werror -pedantic
)