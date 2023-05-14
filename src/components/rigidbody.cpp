
#include "sandbox/components/rigidbody.h"
#include "glm/fwd.hpp"
#include "glm/glm.hpp"
#include "sandbox/components/transform.h"
#include "sandbox/core/registry.h"
#include <cmath>


Sandbox::Rigidbody::~Rigidbody() {};

float_t Sandbox::Rigidbody::GetMass() {
    return this->m_Mass;
}

void Sandbox::Rigidbody::SetMass(float_t mass) {
    this->m_Mass = mass;
}

float_t Sandbox::Rigidbody::GetGravity() {
    return this->m_Gravity;
}

void Sandbox::Rigidbody::SetGravity(float_t gravity) {
    this->m_Gravity = gravity;
}

glm::vec2 Sandbox::Rigidbody::GetVelocity() {
    return this->m_Velocity;
}

void Sandbox::Rigidbody::SetVelocity(float_t vx, float_t vy) {
    this->m_Velocity.x = vx;
    this->m_Velocity.y = vy;
}


void Sandbox::Rigidbody::update() {
    auto tran = Registry::GetComponent<Sandbox::Transform>(this->GetEntity()->getUUID());
    
    // glm::vec2 bigF = {0, 0};

    // f = ma
    // F = sum_i0-j(f_i)
    // a = f / a
    // v_i = v_i-1 + a_i
    // p_i = p_i-1 + v_i

    
    this->m_Velocity.y += this->m_Gravity * this->m_Mass;

    tran->AddPosition(this->m_Velocity.x, this->m_Velocity.y); 
}

