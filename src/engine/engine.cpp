#include <iostream>
#include "window/window.h"
#include "engine/engine.h"
#include "render/render.h"
#include "mesh/mesh.h"
#include "shader/shader.h"

void Engine::run(){
    try{
        Window window(1920,1080);

        Render render;

        render.setClearColor(0.0f,0.0f,0.0f);

        float triange[] = {
            1.0f, 1.0f, 0.0f,
            1.0f, 0.5f, 0.0f,
            0.0f, 0.5f, 1.0f
        };

        Mesh mesh(triange, sizeof(triange)/sizeof(triange[0]));

        Shader shader("shaders/basic.vert","shaders/basic.frag");

        while(!window.shouldClose()) {
        window.pollEvents();
        render.clear();
        shader.use();
        glBindVertexArray(mesh.getVao());
        glDrawArrays(GL_TRIANGLES, 0, mesh.getCount());
        window.swapBuffers();
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
