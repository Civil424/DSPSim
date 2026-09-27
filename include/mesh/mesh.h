#include "glad/glad.h"
#pragma once

class Mesh {
private:
    GLuint m_vbo;
    GLuint m_vao;
    size_t m_vertexCount;
public:
    Mesh(const float *verticles, size_t count); 
    ~Mesh();

    GLuint getVao() const {
        return m_vao;
    }
    size_t getCount() const {
        return m_vertexCount;
    }
};