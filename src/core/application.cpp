#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "sandbox/core/shader.h"

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

    glPointSize(4);
}

float vertices[] = {
     (float) 0 / Sandbox::Application::WIDTH, (float) 0 / Sandbox::Application::HEIGHT,  // top right
     (float) 4 / Sandbox::Application::WIDTH, (float) 0 / Sandbox::Application::HEIGHT// bottom right
};


 
unsigned int VBO;
unsigned int VAO;

#define LEN(x) (sizeof(x)/sizeof(x[0]))

void Sandbox::Application::Run() {
    Sandbox::Shader *shades = new Sandbox::Shader("/home/jae/Projects/cpp/sandbox/res/vertex.glsl", "/home/jae/Projects/cpp/sandbox/res/fragment.glsl");


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    while(!glfwWindowShouldClose(m_Window)) {

        Sandbox::Application::ProcessInput();

        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shades->Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, LEN(vertices)/2);
        glBindVertexArray(0);

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
