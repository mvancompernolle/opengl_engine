//
// Created by root on 7/21/15.
//

#ifndef OPENGL_ENGINE_GRAPHICS_H
#define OPENGL_ENGINE_GRAPHICS_H

#include <SDL.h>
#include <glm/glm.hpp>

class Engine;
class Box;

class Graphics {
public:
    Graphics();
    ~Graphics();

    void tick(float dt);
    void render();
    void stop();
    void windowResized();

    glm::mat4 view, projection;
    int width, height;
private:

    SDL_Window *window;
    SDL_GLContext gl_context;
    Box* box;
};


#endif //OPENGL_ENGINE_GRAPHICS_H
