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
        // GLFW initialization
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return -1;
        }

        // Create a GLFW window
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        GLFWwindow* window = glfwCreateWindow(800, 600, "ImGui GLFW OpenGL3 Example", nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }

        // Make the OpenGL context current
        glfwMakeContextCurrent(window);

        // Initialize GLEW (OpenGL Extension Wrangler)
        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize GLEW" << std::endl;
            glfwTerminate();
            return -1;
        }

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();

        // Initialize ImGui for GLFW and OpenGL3
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");

        // Main loop
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            // Start the ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Create your ImGui GUI here
            ImGui::Begin("Hello, ImGui!");
            ImGui::Text("This is a basic ImGui window.");
            if (ImGui::Button("Exit")) {
                glfwSetWindowShouldClose(window, true);
            }
            ImGui::End();

            // Rendering
            glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }

        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwTerminate();

        
	return 0;

}

Projectile tick(Environment& env, Projectile& proj) {
	proj.setPosition(proj.getPosition() + proj.getVelocity());
	proj.setVelocity(proj.getVelocity() + env.getGravity() + env.getWind());
	cout << "in the tick funciton" << proj << endl;
	return proj;
}

