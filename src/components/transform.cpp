#include "glm/fwd.hpp"
#include "sandbox/core/component.h"
#include "sandbox/core/entity.h"
#include <glm/glm.hpp>

#include <sandbox/components/transform.h>





Sandbox::Transform::~Transform() { }



void Sandbox::Transform::SetPosition(float x, float y) {
    this->m_Position.x = x;
    this->m_Position.y = y;
}

void Sandbox::Transform::AddPosition(float_t x, float_t y) {
    this->m_Position.x += x;
    this->m_Position.y += y;
}

glm::vec2& Sandbox::Transform::GetPosition() {
    return this->m_Position;
}

