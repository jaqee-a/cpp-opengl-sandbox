#pragma once

#include <cmath>
#include <cstddef>
#include <memory>
#include <vector>

#include "sandbox/core/entity.h"
#include "sandbox/core/component.h"

namespace Sandbox {

    class CMesh : public Sandbox::Component {
    private:
        uint32_t *m_VBO = nullptr;
        uint32_t *m_VAO = nullptr;

        std::vector<float_t> m_Vertices;
        std::vector<float_t> m_Colors;
        
    public:
        const static _CLASS_ID CLASS = CMESH;

        CMesh(std::shared_ptr<Sandbox::Entity> entt) : Sandbox::Component(entt) {};
        ~CMesh();

        void BuildMesh();
        void SetVerticies(float_t* vertices, size_t len);
        std::vector<float_t> GetVertices();
        uint32_t GetVAO();
    };
};

inline const _CLASS_ID Sandbox::CMesh::CLASS;
