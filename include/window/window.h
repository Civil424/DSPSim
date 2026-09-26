#include <glad/glad.h>
#include <GLFW/glfw3.h>
#pragma once

class Window {
public:
    Window(int width, int height);
    bool shouldClose();
    void pollEvents();
    void swapBuffers();
    ~Window();
private:
    GLFWwindow* m_window;
};