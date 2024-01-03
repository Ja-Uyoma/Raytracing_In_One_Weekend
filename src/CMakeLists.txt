add_executable(app)

target_sources(app
    PRIVATE main.cpp
)

target_compile_features(app 
    PRIVATE cxx_std_20
)

target_compile_options(app
    PRIVATE -Wall -Wextra -Werror -pedantic
)