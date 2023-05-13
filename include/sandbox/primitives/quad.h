#pragma once

#include <memory>

#include "sandbox/components/cmesh.h"
#include "sandbox/core/entity.h"
#include "sandbox/core/registry.h"

namespace Sandbox {

    namespace Primitives {
        
        std::shared_ptr<Sandbox::Entity> quad() {
            auto entt = Sandbox::Registry::RegisterNewEntity();
   
            Sandbox::Registry::RegisterComponent<Sandbox::CMesh>(entt->getUUID());

            return entt;
        }
    
    }
}
