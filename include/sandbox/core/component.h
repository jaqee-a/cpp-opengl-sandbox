#pragma once

#include <memory>

#include "sandbox/core/entity.h"

enum _CLASS_ID {
    TRANSFORM,
    CMESH,
    MESH
};

namespace Sandbox {

    class Component {
    private:
        bool m_Enabled;
        std::shared_ptr<Sandbox::Entity> m_Entity;
    public:
        Component(std::shared_ptr<Sandbox::Entity> entity) : m_Entity(entity), m_Enabled(true) {};
        virtual ~Component();


        std::shared_ptr<Sandbox::Entity> GetEntity(); 
    };
};
