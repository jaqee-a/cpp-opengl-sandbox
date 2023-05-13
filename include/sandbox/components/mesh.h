#pragma once

#include <memory>

#include "sandbox/core/entity.h"
#include "sandbox/core/component.h"

namespace Sandbox {

    class Mesh : public Sandbox::Component {
    private:
        int32_t m_VBO;
        int32_t m_VAO;
        int32_t m_EBO;
        
    public:
        const static _CLASS_ID CLASS = MESH;

        Mesh(std::shared_ptr<Sandbox::Entity> entt) : Sandbox::Component(entt) {};
        ~Mesh();
    };
};

inline const _CLASS_ID Sandbox::Mesh::CLASS;
