









#include "glm/glm.hpp"
#include "sandbox/core/component.h"
#include <cmath>

namespace Sandbox {

    class Rigidbody : public Sandbox::Component {
    private:
        float_t m_Mass = 1.0f;
        float_t m_Gravity = 1.0f;
        glm::vec2 m_Velocity = {0, 0};

    public:
        const static _CLASS_ID CLASS;

        Rigidbody(std::shared_ptr<Sandbox::Entity> entt) : Component(entt) {};
        ~Rigidbody();

        float_t GetMass();
        void SetMass(float_t mass);

        float_t GetGravity();
        void SetGravity(float_t gravity);

        glm::vec2 GetVelocity();
        void SetVelocity(float_t vx, float_t vy);

        void update();

    };

    inline const _CLASS_ID Rigidbody::CLASS = ++Component::__ID;
};
