//
// Created by root on 7/21/15.
//

#include "Input.h"
#include "Engine.h"
#include "Graphics.h"
#include <SDL.h>

Input::Input(){
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

Input::~Input(){

}

void Input::tick(float dt){
    SDL_Event event;
    float x,y;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                if(event.key.keysym.mod == KMOD_LSHIFT || event.key.keysym.mod == KMOD_RSHIFT)
                    keyPresses[KMOD_LSHIFT] = true;

                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        Engine::getEngine()->stop();
                        break;

                    case SDLK_1:
                        break;

                    case SDLK_2:
                        break;

                    case SDLK_w:
                        keyPresses[SDLK_w] = true;
                        break;

                    case SDLK_s:
                        keyPresses[SDLK_s] = true;
                        break;

                    case SDLK_d:
                        keyPresses[SDLK_d] = true;
                        break;

                    case SDLK_a:
                        keyPresses[SDLK_a] = true;
                        break;

                    case SDLK_r:
                        keyPresses[SDLK_r] = true;
                        break;

                    case SDLK_f:
                        keyPresses[SDLK_f] = true;
                        break;

                    case SDLK_LEFT:
                        keyPresses[SDLK_LEFT] = true;

                        break;

                    case SDLK_RIGHT:
                        keyPresses[SDLK_RIGHT] = true;

                        break;

                    case SDLK_b:
                        break;
                }

                break;

            case SDL_KEYUP:
                if(!(event.key.keysym.mod == KMOD_LSHIFT || event.key.keysym.mod == KMOD_RSHIFT))
                    keyPresses[KMOD_LSHIFT] = false;

                switch(event.key.keysym.sym) {
                    case SDLK_w:
                        keyPresses[SDLK_w] = false;
                        break;

                    case SDLK_s:
                        keyPresses[SDLK_s] = false;
                        break;

                    case SDLK_d:
                        keyPresses[SDLK_d] = false;
                        break;

                    case SDLK_a:
                        keyPresses[SDLK_a] = false;
                        break;

                    case SDLK_r:
                        keyPresses[SDLK_r] = false;
                        break;

                    case SDLK_f:
                        keyPresses[SDLK_f] = false;
                        break;

                    case SDLK_LEFT:
                        keyPresses[SDLK_LEFT] = false;
                        break;

                    case SDLK_RIGHT:
                        keyPresses[SDLK_RIGHT] = false;
                        break;
                }
                break;

            case SDL_QUIT:
                Engine::getEngine()->stop();
                break;

            case SDL_MOUSEMOTION:
                break;

            case SDL_WINDOWEVENT:
                if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    Engine::getEngine()->graphics->windowResized();
                }
                break;
        }
    }

    handleMovementKeys();
}

void Input::stop(){

}

const std::map<int, bool>& Input::getKeyMap(){

}

void Input::handleMovementKeys(){

}
