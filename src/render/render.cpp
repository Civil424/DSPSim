#include "render/render.h"

void Render::setClearColor(float r,float g,float b) {
    m_colorR = r;
    m_colorG = g;
    m_colorB = b;
}

void Render::clear() {
    glClearColor(m_colorR, m_colorG, m_colorB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}