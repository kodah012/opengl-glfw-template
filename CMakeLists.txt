cmake_minimum_required(VERSION 3.26)
project(renderer VERSION 1.0.0)

# generate compilation database file for code completion, syntax highlighting, etc.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# add source files
set(SOURCES
    src/main.cpp
)

# create executable target
set(TARGET_NAME ${PROJECT_NAME})
add_executable(${TARGET_NAME} ${SOURCES})

# include header files in the "include" directory
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# find OpenGL, GLEW, and GLFW
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# link libraries
target_link_libraries(${TARGET_NAME} PRIVATE
    OpenGL::GL
    GLEW::GLEW
    glfw
)
