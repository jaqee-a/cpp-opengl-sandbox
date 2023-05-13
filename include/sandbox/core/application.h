#pragma once

#include "sandbox/decl.h"
#include <GLFW/glfw3.h>
#include <cstddef>

namespace Sandbox {
    
    namespace Application {

        inline void (*updateFunction)();
        inline void (*initFunction)();

        inline void framebuffer_size_callback(GLFWwindow *window, int32_t width, int32_t height);
        inline void mouse_callback(GLFWwindow *window, double xpos, double ypos);

        inline void (*MouseCallback)(double, double) = [](double xpos, double ypos){};

        inline size_t WIDTH=1000;
        inline size_t HEIGHT=800;

        inline GLFWwindow *m_Window = nullptr;

        void Init(void (*init)(), void (*update)());
        void Run();
        void ProcessInput();
    };
};


