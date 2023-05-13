#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "sandbox/components/cmesh.h"
#include "sandbox/components/transform.h"
#include "sandbox/core/registry.h"
#include "sandbox/core/shader.h"
#include "sandbox/core/renderer.h"

#include <cstdlib>
#include <iostream>

#include <sandbox/core/application.h>

void Sandbox::Application::framebuffer_size_callback(GLFWwindow *window, size_t width, size_t height) {
    glViewport(0, 0, width, height);
}

void Sandbox::Application::Init() {
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


    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD";
        exit(-1);
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
}

float vertices[] = {
     (float) 0 / Sandbox::Application::WIDTH, (float) 0 / Sandbox::Application::HEIGHT,  // top right
     (float) 4 / Sandbox::Application::WIDTH, (float) 0 / Sandbox::Application::HEIGHT// bottom right
};


 
unsigned int VBO;
unsigned int VAO;

#define LEN(x) (sizeof(x)/sizeof(x[0]))

void Sandbox::Application::Run() {
    Sandbox::Shader *shades = new Sandbox::Shader("/home/jae/Projects/cpp/sandbox/res/pixel_shader.glsl", 
                                                  "/home/jae/Projects/cpp/sandbox/res/fragment.glsl");


    auto entt = Registry::RegisterNewEntity();
    auto tran = Registry::RegisterComponent<Transform>(entt->getUUID());
    auto cmesh = Registry::RegisterComponent<CMesh>(entt->getUUID());
    cmesh->SetVerticies(vertices, 4);
    cmesh->BuildMesh();

    std::cout << entt->IsActive();

    while(!glfwWindowShouldClose(m_Window)) {

        Sandbox::Application::ProcessInput();

        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

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
