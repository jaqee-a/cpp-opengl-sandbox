#include "glm/fwd.hpp"
#include <glm/glm.hpp>

#include <sandbox/components/transform.h>





Sandbox::Transform::Transform() { }

Sandbox::Transform::~Transform() { }



void Sandbox::Transform::SetPosition(float x, float y) {
    this->m_Position.x = x;
    this->m_Position.y = y;
}


const glm::vec2& Sandbox::Transform::GetPosition() {
    return this->m_Position;
}

