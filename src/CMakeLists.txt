add_executable(app)

set(includeDir "${CMAKE_SOURCE_DIR}/include")

target_include_directories(app
    PUBLIC 
        "${includeDir}"
        "${PROJECT_SOURCE_DIR}/src/Ray"
        "${PROJECT_SOURCE_DIR}/src/Vec3"
)

target_sources(app
    PRIVATE 
        main.cpp 
        Main.cpp
        "${PROJECT_SOURCE_DIR}/src/Colour/Colour.hpp"
        "${PROJECT_SOURCE_DIR}/src/Ray/Ray.hpp"
    PUBLIC 
        "${includeDir}/Vec3.hpp" 
)

target_compile_features(app 
    PRIVATE 
        cxx_std_20
)

target_compile_options(app
    PRIVATE 
        -Wall -Wextra -Werror -pedantic
)