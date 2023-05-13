#include <cmath>
#include <cstdint>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "sandbox/components/cmesh.h"






Sandbox::CMesh::~CMesh() {}


void Sandbox::CMesh::BuildMesh() {
    if (this->m_VBO == nullptr) {
        this->m_VBO = new uint32_t;
        glGenBuffers(1, this->m_VBO);
    }

    if (this->m_VAO == nullptr) {
        this->m_VAO = new uint32_t;
        glGenVertexArrays(1, this->m_VAO);
    }

    glBindVertexArray(*this->m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, *this->m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float_t) * this->m_Vertices.size(),  
                 this->m_Vertices.data(), GL_STATIC_DRAW);
        
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float_t), (void*) 0);
    glEnableVertexAttribArray(0);
}

std::vector<float_t> Sandbox::CMesh::GetVertices() {
    return this->m_Vertices;
}

void Sandbox::CMesh::SetVerticies(const float_t *vertices, const size_t len) {
    this->m_Vertices.insert(this->m_Vertices.end(), vertices, vertices + len);
}

uint32_t Sandbox::CMesh::GetVAO() {
    return *this->m_VAO;
}
