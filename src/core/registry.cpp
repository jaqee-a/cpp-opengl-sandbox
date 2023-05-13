#include <cstddef>
#include <iostream>
#include <vector>
#include <memory>

#include "sandbox/core/registry.h"
#include "sandbox/core/component.h"
#include "sandbox/core/entity.h"

// O(1)

std::shared_ptr<Sandbox::Entity> Sandbox::Registry::RegisterNewEntity() {
    std::shared_ptr<Sandbox::Entity> entt (new Sandbox::Entity);

    uuid_t uuid = entt->getUUID();

    enttTable[uuid] = entt;

    return entt;
}

std::shared_ptr<Sandbox::Entity> Sandbox::Registry::getEntityByUUID(uuid_t uuid) {
    if(enttTable.find(uuid) != enttTable.end()) {
        return enttTable[uuid];
    }
    return nullptr;
}

