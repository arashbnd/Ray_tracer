#include <iostream>
#include "tuple.h"
#include "environment.h"
#include "Projectile.h"
#include "color.h"
#include <gl/glew.h>
#include <glfw/glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
using namespace std;

Projectile tick(Environment& env, Projectile& proj);

    void display() {
        glClearColor(0.0f, 0.0f, 0.7f, 1.0f); // Set the clear color
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

        glBegin(GL_LINES);
        // line one
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
        // line two
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        // added thrid line to form triangle
        glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glEnd();

        glFlush(); // Flush the drawing commands
    }

    int main() {

        glfwInit(); // Initialize GLFW

        // Create a window and OpenGL context
        GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Example", nullptr, nullptr);
        if (window == nullptr) {
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window); // Set the current OpenGL context

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");

        while (!glfwWindowShouldClose(window)) {
            display(); // Call the display function

            glfwSwapBuffers(window); // Swap buffers
            glfwPollEvents(); // Process events
        }

        glfwTerminate(); // Clean up and terminate GLFW

	return 0;

}

Projectile tick(Environment& env, Projectile& proj) {
	proj.setPosition(proj.getPosition() + proj.getVelocity());
	proj.setVelocity(proj.getVelocity() + env.getGravity() + env.getWind());
	cout << "in the tick funciton" << proj << endl;
	return proj;
}

