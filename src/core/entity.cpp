


#include <cstdint>

#include "sandbox/utils/uuid.h"
#include <sandbox/core/entity.h>





Sandbox::Entity::Entity() {
    // Generate new UUID;
    //
    this->UUID = GenUUID(); 
}

Sandbox::Entity::~Entity() {}



uuid_t Sandbox::Entity::getUUID() {
    return this->UUID;
}
