add_executable(app)

target_include_directories(app
    PRIVATE 
        "${PROJECT_SOURCE_DIR}/src/Ray"
        "${PROJECT_SOURCE_DIR}/src/Vec3"
        "${PROJECT_SOURCE_DIR}/src/Colour"
        "${PROJECT_SOURCE_DIR}/src/Main"
)

target_sources(app
    PRIVATE
        main.cpp 
        Main.cpp
        "${PROJECT_SOURCE_DIR}/src/Colour/Colour.cpp"
)

target_compile_features(app 
    PRIVATE 
        cxx_std_20
)

target_compile_options(app
    PRIVATE 
        -Wall -Wextra -Werror -pedantic
)