# This function ensures out-of-source builds
function(EnsureOutOfSourceBuilds)
    # Make sure the user doesn't play dirty with symlinks
    get_filename_component(srcDir "${CMAKE_SOURCE_DIR}" REALPATH)
    get_filename_component(binaryDir "${CMAKE_BINARY_DIR}" REALPATH)

    # Prevent in-source builds
    if("${srcDir}" STREQUAL "${binaryDir}")
        message("#################################################################")
        message("Warning: in-source builds are disabled")
        message("Please create a separate build directory and run cmake from there")
        message("#################################################################")
        message(FATAL_ERROR "Quitting configuration")
    endif()    
endfunction()

EnsureOutOfSourceBuilds()