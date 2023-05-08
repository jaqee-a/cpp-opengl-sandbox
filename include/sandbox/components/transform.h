#pragma once

#include <sandbox/core/component.h>

#include <glm/glm.hpp>

namespace Sandbox {

    class Transform: public Component {
    private:
        glm::vec2 m_Position;

    public:
        Transform();
        ~Transform();


        void SetPosition(float x, float y); 
        const glm::vec2& GetPosition();
    };
    
};
