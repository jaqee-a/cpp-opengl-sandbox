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
    ssize_t index = componentsList.size();
    componentsList.push_back({});

    uuid_t uuid = entt->getUUID();

    uuidTable[index] = uuid;
    enttTable[uuid] = entt;
    indexTable[uuid] = index;

    return entt;
}

void Sandbox::Registry::LinkComponent(std::shared_ptr<Sandbox::Entity> entt, std::shared_ptr<Sandbox::Component> component) {

}

std::shared_ptr<Sandbox::Entity> Sandbox::Registry::getEntityByUUID(uuid_t uuid) {
    if(enttTable.find(uuid) != enttTable.end()) {
        return enttTable[uuid];
    }
    return nullptr;
}

ssize_t Sandbox::Registry::getEntityComponentsIndex(uuid_t uuid) {
    if(indexTable.find(uuid) != indexTable.end()) {
        return indexTable[uuid];
    }
    return -1;
}
