#include <stdexcept>
#include "window/window.h"

Window::Window(int width, int height) {
    if(!glfwInit()){
        throw std::runtime_error("GLFW Init Failed");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GLFW_TRUE);

    m_window = glfwCreateWindow(
        width,
        height,
        "DSPSim",
        nullptr,
        nullptr
    );
    if(m_window == nullptr){
        throw std::runtime_error("Window Create Failed");
    }
    
    glfwMakeContextCurrent(m_window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Initialize GLAD Failed");
    }
}

bool Window::shouldClose() {
        return glfwWindowShouldClose(m_window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(m_window);
}

Window::~Window() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}