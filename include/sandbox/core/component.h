#pragma once

#include <iostream>
#include <memory>

#include "sandbox/core/entity.h"

typedef size_t _CLASS_ID;

namespace Sandbox {
    
    class Component {
    private:
        bool m_Enabled;
        std::shared_ptr<Sandbox::Entity> m_Entity;
    public:
        static _CLASS_ID __ID;

        Component(std::shared_ptr<Sandbox::Entity> entity) : m_Entity(entity), m_Enabled(true) { }

        virtual ~Component();


        std::shared_ptr<Sandbox::Entity> GetEntity(); 
    };
    
    inline size_t Component::__ID = 0;
};

