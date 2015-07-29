//
// Created by root on 7/21/15.
//

#define GLM_FORCE_RADIANS

#include "Box.h"

Box::Box(float width, float height){

    // create box geometry
    Vertex vert;
    vert.pos = glm::vec3(-width/2, height/2, 0);
    geometry.push_back(vert);
    vert.pos = glm::vec3(-width/2, -height/2, 0);
    geometry.push_back(vert);
    vert.pos = glm::vec3(width/2, height/2, 0);
    geometry.push_back(vert);
    vert.pos = glm::vec3(-width/2, -height/2, 0);
    geometry.push_back(vert);
    vert.pos = glm::vec3(width/2, height/2, 0);
    geometry.push_back(vert);
    vert.pos = glm::vec3(width/2, -height/2, 0);
    geometry.push_back(vert);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * geometry.size(), geometry.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

    unbindVAO();
}

Box::~Box(){

}


void Box::tick(float dt){

}

void Box::render(){
    program.bind();
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, geometry.size());

    unbindVAO();
    program.unbind();
}
