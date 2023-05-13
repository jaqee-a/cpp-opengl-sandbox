#include "sandbox/core/renderer.h"
#include "sandbox/components/cmesh.h"
#include "sandbox/components/transform.h"
#include "sandbox/core/component.h"
#include "sandbox/core/registry.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "sandbox/core/shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>


void Sandbox::Renderer::render(Sandbox::Shader *shader) {
    std::map   <_CLASS_ID, std::shared_ptr<Sandbox::Component>> components;
    std::vector<std::shared_ptr<Sandbox::Entity>> entts = Registry::GetAllOfType<CMesh>();

    Sandbox::Transform *transform;
    Sandbox::CMesh *cmesh;

    shader->Use();
    glm::mat4 model;

    for(auto entt : entts) {
        if(!entt->IsActive()) continue;
        
        components = Registry::componentsTable[entt->getUUID()];

        transform = (Sandbox::Transform*)components[Sandbox::Transform::CLASS].get();
        cmesh     = (Sandbox::CMesh*)components[Sandbox::CMesh::CLASS].get();

        model = glm::mat4(1.0);
        model = glm::translate(model, glm::vec3(transform->GetPosition().x, transform->GetPosition().y, 0));
        shader->setMat4("model", glm::value_ptr(model));

        glBindVertexArray(cmesh->GetVAO());
        glDrawArrays(GL_POINTS, 0, cmesh->GetVertices().size() / 2);
        glBindVertexArray(0);
    }
}
