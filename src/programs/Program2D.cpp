//
// Created by root on 7/21/15.
//

#include "Program2D.h"
#include "Engine.h"
#include <iostream>

Program2D::Program2D(){

    shaders[0] = Program::loadShader("../shaders/shader.vs", GL_VERTEX_SHADER);
    shaders[1] = Program::loadShader("../shaders/shader.fs", GL_FRAGMENT_SHADER);

    program = glCreateProgram();
    glAttachShader(program, shaders[0]);
    glAttachShader(program, shaders[1]);

    glLinkProgram(program);

    GLint shader_status;
    glGetProgramiv(program, GL_LINK_STATUS, &shader_status);
    if(!shader_status) {
        std::cerr << "Unable to create shader program!" << std::endl;

        char buffer[512];
        glGetProgramInfoLog(program, 512, NULL, buffer); // inserts the error into the buffer
        std::cerr << buffer << std::endl;

        exit(1);
    }

    locations["vs_pos"] = glGetAttribLocation(program, "vs_pos");
    locations["vs_norm"] = glGetAttribLocation(program, "vs_norm");
    locations["vs_uv"] = glGetAttribLocation(program, "vs_uv");

    locations["mvp"] = glGetUniformLocation(program, "mvp");
    locations["modelMatrix"] = glGetUniformLocation(program, "modelMatrix");
    locations["light_dir"] = glGetUniformLocation(program, "light_dir");
    locations["cameraPos"] = glGetUniformLocation(program, "cameraPos");
    locations["specularIntensity"] = glGetUniformLocation(program, "specularIntensity");
    locations["specularPower"] = glGetUniformLocation(program, "specularPower");
    locations["ambientIntensity"] = glGetUniformLocation(program, "ambientIntensity");
    locations["diffuseIntensity"] = glGetUniformLocation(program, "diffuseIntensity");
    locations["pointLightPos"] = glGetUniformLocation(program, "pointLightPos");
    locations["spotLightDir"] = glGetUniformLocation(program, "spotLightDir");
    locations["tex"] = glGetUniformLocation(program, "tex");

}

Program2D::~Program2D(){

}