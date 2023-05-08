#pragma once

#include <GLFW/glfw3.h>
#include <cstddef>

namespace Sandbox {
    
    namespace Application {

        inline void framebuffer_size_callback(GLFWwindow *window, size_t width, size_t height);

        inline const size_t WIDTH=1000;
        inline const size_t HEIGHT=800;

        inline GLFWwindow *m_Window = nullptr;

        void Init();
        void Run();
        void ProcessInput();
    };
};


