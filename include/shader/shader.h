#include <string>
#pragma once

class Shader{
private:
    GLuint m_programId;
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;
};