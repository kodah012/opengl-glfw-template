#include "window/lib.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// handle resizing of GLFW window
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

// handle keyboard input
void process_input(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(int argc, char *argv[]) {
    Window w = Window();
    w.run();
    
    
    // initialize GLFW
    if (!glfwInit()) {
        std::cerr << "failed to initialize GLFW" << std::endl;
        return -1;
    }
    
    // configure GLFW window properties
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create GLFW window
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Test", nullptr, nullptr);
    if (!window) {
        std::cerr << "failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    
    // initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    // set viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
    // register framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // main render loop
    while (!glfwWindowShouldClose(window)) {
        process_input(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}