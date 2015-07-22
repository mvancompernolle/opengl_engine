//
// Created by root on 7/21/15.
//

#include "Engine.h"
#include "Graphics.h"
#include "Input.h"
#include <iostream>

#include <SDL.h>


Engine *Engine::engine = NULL;

Engine::Engine(){

    Engine::engine = this;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Unable to initilize SDL" << std::endl;
        exit(1);
    }

    graphics = new Graphics();
    input = new Input();
}

Engine::~Engine(){
    stop();
}

int Engine::run(){
    float dt;
    t1 = std::chrono::high_resolution_clock::now();

    while(true){
        dt = tick();
        graphics->tick(dt);
        input->tick(dt);
    }

    return 0;
}

void Engine::stop(int exitCode){
    SDL_Quit();

    delete graphics;
    delete input;

    exit(exitCode);
}

Engine* Engine::getEngine(){
    return engine;
}

float Engine::tick(){
    float dt;

    t2 = std::chrono::high_resolution_clock::now();
    dt = std::chrono::duration_cast<std::chrono::duration<float>>(t2 - t1).count();
    t1 = t2;

    return dt;
}