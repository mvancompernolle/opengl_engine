//
// Created by root on 7/21/15.
//

#define GLM_FORCE_RADIANS

#include "Entity.h"


Entity::Entity(){

    // generate vao and vbo
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

Entity::~Entity(){

}

void Entity::scale(float scaleValue){
    model = glm::scale(model, glm::vec3(scaleValue,scaleValue,scaleValue));
}

void Entity::rotate(float angle, const glm::vec3& axis){
    model = glm::rotate(model, angle, axis);
}

void Entity::translate(const glm::vec3& amount){
    model = glm::translate(model, amount);
}


const glm::mat4& Entity::getModel() const{
    return model;
}


int Entity::getWidth() const{
    return width;
}

int Entity::getHeight() const{
    return height;
}

void Entity::unbindVAO() const{
    glBindVertexArray(0);
}
