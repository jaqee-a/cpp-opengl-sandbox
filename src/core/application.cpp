#include <cmath>
#include <cstdint>
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "sandbox/components/cmesh.h"
#include "sandbox/components/transform.h"
#include "sandbox/core/registry.h"
#include "sandbox/core/shader.h"
#include "sandbox/core/time.h"
#include "sandbox/core/renderer.h"
#include "sandbox/decl.h"

#include <cstdlib>
#include <iostream>

#include <sandbox/core/application.h>

void Sandbox::Application::framebuffer_size_callback(GLFWwindow *window, int32_t width, int32_t height) {
    Sandbox::Application::WIDTH  = width;
    Sandbox::Application::HEIGHT = height;
    glViewport(0, 0, width, height);
}

void Sandbox::Application::mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    MouseCallback(xpos, ypos);
}

void Sandbox::Application::mouse_button_callback(GLFWwindow *window, int32_t button, int32_t action, int32_t mods) { 
    MouseButtonCallback(button, action, mods);
}

void Sandbox::Application::Init(void (*init)(), void (*update)()) {
    if(!glfwInit()) {
        std::cerr << "Could not initialize GLFW!";
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    m_Window = glfwCreateWindow(WIDTH, HEIGHT, "Sandbox", NULL, NULL);
    if(m_Window == NULL) {
        std::cerr << "Failed to create GLFW window";
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
    glfwSetCursorPosCallback(m_Window, mouse_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);


    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD";
        exit(-1);
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

    initFunction = init;
    updateFunction = update;
}
 
void Sandbox::Application::Run() {
    Sandbox::Shader *shades = new Sandbox::Shader("/home/jae/Projects/cpp/sandbox/res/pixel_shader.glsl", 
                                                  "/home/jae/Projects/cpp/sandbox/res/fragment.glsl");

    initFunction();

    float_t lastFrame = 0.0f;
    float_t currentFrame = 0.0f;

    while(!glfwWindowShouldClose(m_Window)) {

        currentFrame = glfwGetTime();
        Sandbox::Time::DELTA_TIME = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Sandbox::Application::ProcessInput();

        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        updateFunction();
        Sandbox::Renderer::render(shades);

        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }

    glfwTerminate();
}

void Sandbox::Application::ProcessInput() {
    if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_Window, true);
    }
}
