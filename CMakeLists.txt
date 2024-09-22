cmake_minimum_required(VERSION 3.10)

# Project name and version
project(simple_window VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for your project
add_executable(simple_window src/main.cpp src/glad.c)

# Set the path to your dependencies folder
set(DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/dependencies")

# Include directories for GLFW, glad, and other dependencies
target_include_directories(simple_window PUBLIC
    ${DEPENDENCIES_DIR}/include    # Base include directory
    ${DEPENDENCIES_DIR}/include/GLFW   # Ensure it looks directly into GLFW folder
)

# Link the GLFW library (glfw3.a) from the dependencies/libs folder
target_link_libraries(simple_window PUBLIC
    ${DEPENDENCIES_DIR}/libs/libglfw3.a
)

# Additional compiler flags
target_compile_options(simple_window PRIVATE
    -Wall
    -Wno-deprecated
    -fdiagnostics-color=always
    -g
)

# macOS frameworks
if(APPLE)
    target_link_libraries(simple_window PRIVATE
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
        "-framework Metal"
        "-framework QuartzCore"
        "-ldl"
    )
endif()

# On Windows, you might need to add GLEW and OpenGL libraries like this
if(WIN32)
    target_link_libraries(simple_window PRIVATE
        opengl32
    )
endif()
