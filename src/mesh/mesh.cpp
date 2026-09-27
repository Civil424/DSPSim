#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "mesh/mesh.h"

Mesh::Mesh(const float *verticles, size_t count){
    m_vertexCount = count / 3;
    glGenVertexArrays(1,&m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1,&m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,m_vbo);
    glBufferData(GL_ARRAY_BUFFER,count * sizeof(float), verticles, GL_STATIC_DRAW);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        (void*)0
    );
    glEnableVertexAttribArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1,&m_vao);
    glDeleteBuffers(1,&m_vbo);
}