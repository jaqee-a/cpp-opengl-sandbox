#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "sandbox/components/transform.h"
#include "sandbox/core/application.h"
#include "sandbox/core/entity.h"
#include "sandbox/core/registry.h"
#include "sandbox/utils/uuid.h"

int main(void) {
    // Sandbox::Application::Init();
    // Sandbox::Application::Run();
    //
    //

    auto entt1 = Sandbox::Registry::RegisterNewEntity();
    auto entt2 = Sandbox::Registry::RegisterNewEntity();
    auto entt3 = Sandbox::Registry::RegisterNewEntity();

    std::cout << "entt1 - >" << entt1->getUUID() << std::endl;
    std::cout << "entt2 - >" << entt2->getUUID() << std::endl;
    std::cout << "entt3 - >" << entt3->getUUID() << std::endl;


    Sandbox::Registry::RegisterComponent<Sandbox::Transform>(entt1->getUUID());
    Sandbox::Registry::RegisterComponent<Sandbox::Transform>(entt3->getUUID());

    auto all = Sandbox::Registry::GetAllOfType<Sandbox::Transform>();

    for(int i = 0; i < all.size(); ++i ){
        std::cout << (*all[i]).getUUID() << std::endl;
    }

    return 0;
}
