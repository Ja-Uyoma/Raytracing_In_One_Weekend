add_executable(app)

set(includeDir "${CMAKE_SOURCE_DIR}/include")

target_include_directories(app
    PUBLIC 
        "${includeDir}"
)

target_sources(app
    PRIVATE 
        main.cpp 
        Main.cpp
        "${PROJECT_SOURCE_DIR}/src/Colour/Colour.hpp"
    PUBLIC 
        "${includeDir}/Vec3.hpp" 
        "${includeDir}/Ray.hpp"
)

target_compile_features(app 
    PRIVATE 
        cxx_std_20
)

target_compile_options(app
    PRIVATE 
        -Wall -Wextra -Werror -pedantic
)