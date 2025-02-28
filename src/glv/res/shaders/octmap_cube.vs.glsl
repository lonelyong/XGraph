#version 460 core

precision highp float;

layout(location = 0) in vec3 position;
layout(location = 3) in vec4 color;
layout(location = 15) in float size;

uniform mat4 osg_ModelViewMatrix;
uniform mat4 osg_ProjectionMatrix;
uniform mat4 osg_ModelViewProjectionMatrix;

out float box_size;
out vec4 box_color;

void main(){

    //gl_Position = osg_ModelViewProjectionMatrix * vec4(position, 1.0);
    gl_Position = vec4(position, 1.0);;
    box_size = size;
    box_color = color;
}