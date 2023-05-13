#pragma once

#include <cstdint>
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <vector>
#include <memory>
#include <map>


#include "sandbox/core/component.h"
#include "sandbox/core/entity.h"
#include "sandbox/decl.h"

namespace Sandbox {
    
    namespace Registry
    {

        inline std::map<uuid_t, std::shared_ptr<Sandbox::Entity>> enttTable;

        inline  std::map<uuid_t, 
                    std::map<_CLASS_ID,
                        std::shared_ptr<Sandbox::Component>>> componentsTable;

        std::shared_ptr<Sandbox::Entity> RegisterNewEntity();
        std::shared_ptr<Sandbox::Entity> getEntityByUUID(uuid_t uuid); 
        
        template <typename T>
        std::vector<std::shared_ptr<Sandbox::Entity>> GetAllOfType() {
            std::vector<std::shared_ptr<Sandbox::Entity>> out;

            for(auto iter=componentsTable.begin(); iter!=componentsTable.end(); ++iter) {
                if(iter->second.find(T::CLASS) != iter->second.end())
                    out.push_back(enttTable[iter->first]);
            }

            return out;
        }

        template <typename T>
        std::shared_ptr<T> GetComponent(uuid_t uuid) {
            auto __comp = componentsTable[uuid];

            if(__comp.find(T::CLASS) != __comp.end()) {
                std::shared_ptr<T> derived_ptr = std::dynamic_pointer_cast<T>(__comp[T::CLASS]);
                if(derived_ptr != nullptr)
                    return derived_ptr;
            }

            return nullptr;
        }

        template <typename T>
        std::shared_ptr<T> RegisterComponent(uuid_t uuid) {
            std::shared_ptr<T> component (new T(enttTable[uuid]));
            componentsTable[uuid][component->CLASS] = component;
            return component;
        }

    };
};
