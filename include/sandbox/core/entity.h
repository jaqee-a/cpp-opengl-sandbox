#pragma once


#include "sandbox/decl.h"
#include <memory>



namespace Sandbox {
    class Entity {
    private:
        uuid_t UUID;
        bool m_Active = true;

    public:
        Entity();
        ~Entity();


        uuid_t getUUID();
        bool IsActive();
    };
};
