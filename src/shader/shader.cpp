#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "glad/glad.h"
#include "shader/shader.h"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::ifstream vertexes(vertexPath);
    if(!vertexes) {
        throw std::runtime_error("File Open Failed");
    }
    std::stringstream vertexStream;
    vertexStream << vertexes.rdbuf();
    std::string vertexCode = vertexStream.str();
    const char* vertexCStr = vertexCode.c_str();

    std::ifstream fragments(fragmentPath);
    if(!fragments) {
        throw std::runtime_error("File Open Failed");
    }
    std::stringstream fragmentStream;
    fragmentStream << fragments.rdbuf();
    std::string fragmentCode = fragmentStream.str();
    const char* fragmentCStr = fragmentCode.c_str();

    GLuint vertexShaderId =  glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderId =  glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShaderId, 1, &vertexCStr, nullptr);
    glShaderSource(fragmentShaderId, 1 ,&fragmentCStr, nullptr);

    glCompileShader(vertexShaderId);
    glCompileShader(fragmentShaderId);

    int vertexSuccess;
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &vertexSuccess);
    if(!vertexSuccess) {
        char vertexInfoLog[512];
        glGetShaderInfoLog(vertexShaderId, 512, nullptr, vertexInfoLog);
        std::cerr << "Vertex Shader Error\n" << vertexInfoLog << std::endl;
        throw std::runtime_error("Vertex Shader Compile Failed");
    }
    int fragmenSuccess;
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &fragmenSuccess);
    if(!fragmenSuccess) {
        char fragmentInfoLog[512];
        glGetShaderInfoLog(fragmentShaderId, 512, nullptr, fragmentInfoLog);
        std::cerr << "Fragment Shader Error\n" << fragmentInfoLog << std::endl;
        throw std::runtime_error("Fragment Shader Compile Failed");
    }

    m_programId = glCreateProgram();
    glAttachShader(m_programId,vertexShaderId);
    glAttachShader(m_programId,fragmentShaderId);
    glLinkProgram(m_programId);

    int linkSuccess;
    glGetProgramiv(m_programId, GL_LINK_STATUS, &linkSuccess);
    if(!linkSuccess) {
        throw std::runtime_error("Shader Linking Failed");
    }

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
}

Shader::~Shader() {
    glDeleteProgram(m_programId);
}

void Shader::use() const{
    glUseProgram(m_programId);
}