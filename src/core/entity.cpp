


#include <cstdint>

#include "sandbox/components/transform.h"
#include "sandbox/core/registry.h"
#include "sandbox/utils/uuid.h"
#include <sandbox/core/entity.h>





Sandbox::Entity::Entity() {
    // Generate new UUID;
    //
    this->UUID = GenUUID(); 

    Registry::RegisterComponent<Sandbox::Transform>(this->UUID);
}

Sandbox::Entity::~Entity() {}



uuid_t Sandbox::Entity::getUUID() {
    return this->UUID;
}

bool Sandbox::Entity::IsActive() {
    return this->m_Active;
}
