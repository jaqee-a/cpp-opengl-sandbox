#pragma once


#include "sandbox/decl.h"
#include <bits/stdint-intn.h>
namespace Sandbox {
    class Entity {
    private:
        uuid_t UUID;

    public:
        Entity();
        ~Entity();


        uuid_t getUUID();
    };
};
