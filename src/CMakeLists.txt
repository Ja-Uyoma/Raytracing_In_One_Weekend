add_executable(app)

target_sources(app
    PRIVATE main.cpp Main.cpp
    PUBLIC Vec3.hpp Colour.hpp
)

target_compile_features(app 
    PRIVATE cxx_std_20
)

target_compile_options(app
    PRIVATE -Wall -Wextra -Werror -pedantic
)