#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "sandbox/components/transform.h"
#include "sandbox/components/mesh.h"
#include "sandbox/core/application.h"
#include "sandbox/core/entity.h"
#include "sandbox/core/registry.h"
#include "sandbox/utils/uuid.h"

int main(void) {
    Sandbox::Application::Init();
    Sandbox::Application::Run();

    return 0;
}


void test() {

    auto entt1 = Sandbox::Registry::RegisterNewEntity();
    auto entt2 = Sandbox::Registry::RegisterNewEntity();
    auto entt3 = Sandbox::Registry::RegisterNewEntity();

    std::cout << entt1->getUUID() << std::endl;
    std::cout << entt2->getUUID() << std::endl;
    std::cout << entt3->getUUID() << std::endl;

    Sandbox::Registry::RegisterComponent<Sandbox::Mesh>(entt1->getUUID());
    Sandbox::Registry::RegisterComponent<Sandbox::Mesh>(entt2->getUUID());

    Sandbox::Registry::RegisterComponent<Sandbox::Transform>(entt3->getUUID());

    auto ents = Sandbox::Registry::GetAllOfType<Sandbox::Mesh>();

    std::cout << std::endl;
    for(auto c : ents) {
        std::cout << c->getUUID() << std::endl;
    }


}
