//
// Created by root on 7/21/15.
//

#ifndef OPENGL_ENGINE_BOX_H
#define OPENGL_ENGINE_BOX_H

#include "Entity.h"
#include "Program2D.h"
#include <Vertex.h>
#include <vector>

class Box: public Entity{
public:
    Box(float w = 1.0, float h = 1.0);
    virtual ~Box();

    virtual void tick(float dt);
    virtual void render();

private:
    std::vector<Vertex> geometry;
    Program2D program;
};


#endif //OPENGL_ENGINE_BOX_H
