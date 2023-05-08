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
        inline std::map<uuid_t, ssize_t> indexTable;
        inline std::map<ssize_t, uuid_t> uuidTable;
        inline std::vector<std::vector<std::shared_ptr<Sandbox::Component>>> componentsList;

        void LinkComponent(std::shared_ptr<Sandbox::Entity> entt, std::shared_ptr<Sandbox::Component> component); // already existing component

        std::shared_ptr<Sandbox::Entity> RegisterNewEntity();
        std::shared_ptr<Sandbox::Entity> getEntityByUUID(uuid_t uuid); 
        ssize_t getEntityComponentsIndex(uuid_t uuid);
        
        template <typename T>
        std::vector<std::shared_ptr<Sandbox::Entity>> GetAllOfType() {
            std::vector<std::shared_ptr<Sandbox::Entity>> out;
            ssize_t index=0;
            for(auto enttCmps : componentsList) {
                
                for(auto cmp : enttCmps) {
                    std::shared_ptr<T> derived_ptr = std::dynamic_pointer_cast<T>(cmp);
                    if(derived_ptr != nullptr) {
                        out.push_back(enttTable[uuidTable[index]]);
                        break;
                    }
                }
                ++index;
            }
            return out;
        }

        template <typename T>
        std::shared_ptr<T> GetComponent(uuid_t uuid) {
            //TODO: Try to O(1) this
            ssize_t index = getEntityComponentsIndex(uuid);
            if(index == -1) {
                std::cerr << "Entity not found UUID: " << uuid;
                exit(-1);
            }

            std::vector<std::shared_ptr<Sandbox::Component>> *vec = &componentsList[index];

            for(auto cmp_ptr_ : *vec) {
                std::shared_ptr<T> derived_ptr = std::dynamic_pointer_cast<T>(cmp_ptr_);
                if(derived_ptr != nullptr)
                    return derived_ptr;
            }

            return nullptr;
        }

        template <typename T>
        std::shared_ptr<T> RegisterComponent(uuid_t uuid) {
            ssize_t index = getEntityComponentsIndex(uuid);
            if(index == -1) {
                std::cerr << "Entity not found UUID: " << uuid;
                exit(-1);
            }

            std::shared_ptr<T> component (new T);
            componentsList[index].push_back(component);
            return component;
        }

    };
};
