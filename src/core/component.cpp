#include "sandbox/core/entity.h"
#include <sandbox/core/component.h>





Sandbox::Component::~Component() {}


std::shared_ptr<Sandbox::Entity> Sandbox::Component::GetEntity() {
    return this->m_Entity;
}
