//
// Created by root on 7/21/15.
//

#define GLM_FORCE_RADIANS

#include "Graphics.h"
#include "Engine.h"
#include "Box.h"
#include <ostream>
#include <iostream>

Graphics::Graphics(){
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // create SDL window
    window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);

    if(!window){
        std::cerr << "Failed to create SDL window" << std::endl;
        exit(1);
    }

    gl_context = SDL_GL_CreateContext(window);

    // set window to update with vertical retrace
    SDL_GL_SetSwapInterval(1);

    //initialize glew
    glewExperimental = GL_TRUE;
    GLenum status = glewInit();
    if(status != GLEW_OK) {
        std::cerr << "Unable to initialize glew" << std::endl;
        exit(1);
    }

    glClearColor(0.0, 0.0, 0.0, 1);

    box = new Box(1, 1);
}

Graphics::~Graphics(){

}

void Graphics::tick(float dt){
    render();
}

void Graphics::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    box->render();

    SDL_GL_SwapWindow(window);
}

void Graphics::stop(){
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
}

void Graphics::windowResized(){
    // reset window and projection matrix
    SDL_GetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);
    projection = glm::perspective(45.0f, float(width) / float(height), 0.01f, 100000.0f);
}