#pragma once

#include <cmath>
#include <memory>

#include "sandbox/core/entity.h"
#include "sandbox/core/component.h"

#include <glm/glm.hpp>

namespace Sandbox {

    class Transform : public Component {
    private:
        glm::vec2 m_Position = {0, 0};

    public:
        const static _CLASS_ID CLASS;

        Transform(std::shared_ptr<Sandbox::Entity> entt) : Component(entt) {};
        ~Transform();


        void SetPosition(float_t x, float_t y); 
        void AddPosition(float_t x, float_t y);
        glm::vec2& GetPosition();
    };
    
    inline const _CLASS_ID Transform::CLASS = ++Component::__ID;
};
