#include <iostream>
#include "window/window.h"
#include "engine/engine.h"
#include "render/render.h"

void Engine::run(){
    try{
        Window window(1920,1080);

        Render render;

        render.setClearColor(0.0f,0.0f,0.0f);

        while(!window.shouldClose()) {
        window.pollEvents();
        render.clear();
        window.swapBuffers();
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
