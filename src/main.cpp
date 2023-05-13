#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "glm/fwd.hpp"
#include "sandbox/components/transform.h"
#include "sandbox/components/mesh.h"
#include "sandbox/core/application.h"
#include "sandbox/core/component.h"
#include "sandbox/core/entity.h"
#include "sandbox/core/registry.h"
#include "sandbox/utils/uuid.h"
#include "sandbox/components/cmesh.h"

float vertices[] = {
     (float) 0 / Sandbox::Application::WIDTH, (float) 0 / Sandbox::Application::HEIGHT,  // top right
     (float) 4 / Sandbox::Application::WIDTH, (float) 0 / Sandbox::Application::HEIGHT// bottom right
};

Sandbox::Entity *entt;
Sandbox::CMesh *cmesh;

void init() {
    entt  = Sandbox::Registry::RegisterNewEntity().get();

    cmesh = Sandbox::Registry::RegisterComponent<Sandbox::CMesh>(entt->getUUID()).get();
    // Sandbox::Registry::RegisterComponent<Sandbox::Mesh>(entt->getUUID()).get();

    cmesh->SetVerticies(vertices, 4);
    cmesh->BuildMesh();

}

void update() {

}

void onMouseMove(double xpos, double ypos) {
    auto tran = Sandbox::Registry::GetComponent<Sandbox::Transform>(entt->getUUID());
    tran->SetPosition(xpos / Sandbox::Application::WIDTH * 2 - 1, (-ypos / Sandbox::Application::HEIGHT) * 2 + 1);
}


int main(void) {

    Sandbox::Application::MouseCallback = onMouseMove;

    Sandbox::Application::Init(&init, &update);
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
