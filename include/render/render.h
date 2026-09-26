#include <glad/glad.h>
#pragma once

class Render{
private:
    float m_colorR = 0.0f;
    float m_colorG = 0.0f;
    float m_colorB = 0.0f;
public:
    void setClearColor(float r,float g,float b);
    void clear();
};