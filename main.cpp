#include <iostream>
#include "tuple.h"
#include "environment.h"
#include "Projectile.h"
#include "color.h"
#include <gl/glew.h>
#include <glfw/glfw3.h>

using namespace std;

Projectile tick(Environment& env, Projectile& proj);

int main() {

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window with OpenGL 3.3 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the viewport size
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    const GLubyte* glVersion = glGetString(GL_VERSION);
    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::cout << "OpenGL Version: " << glVersion << std::endl;
    std::cout << "GLSL Version: " << glslVersion << std::endl;


    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Poll events and swap buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Clean up and exit
    glfwTerminate();
	return 0;

}

Projectile tick(Environment& env, Projectile& proj) {
	proj.setPosition(proj.getPosition() + proj.getVelocity());
	proj.setVelocity(proj.getVelocity() + env.getGravity() + env.getWind());
	cout << "in the tick funciton" << proj << endl;
	return proj;
}

