//
// Created by root on 7/21/15.
//

#ifndef OPENGL_ENGINE_INPUT_H
#define OPENGL_ENGINE_INPUT_H


#include <map>

class Input {
public:
    Input();
    ~Input();

    void tick(float dt);
    void stop();
    const std::map<int, bool>& getKeyMap();

private:
    void handleMovementKeys();
    float sensitivity;

    std::map<int, bool> keyPresses;
};


#endif //OPENGL_ENGINE_INPUT_H
