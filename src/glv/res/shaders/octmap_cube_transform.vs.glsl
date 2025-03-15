#version 410 core

precision highp float;

layout(location = 0) in vec3 position;
layout(location = 15) in float size;

out float box_size;

void main(){
    gl_Position = vec4(position, 1.0);
    box_size    = box_size;
}