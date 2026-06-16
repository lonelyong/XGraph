#version 410 core

precision highp float;

layout(location = 0) in vec3 position;
layout(location = 2) in vec3 norm;
layout(location = 3) in vec4 color;

uniform mat3 osg_NormalMatrix;
uniform mat4 osg_ModelViewMatrix;
uniform mat4 osg_ProjectionMatrix;
uniform mat4 osg_ModelViewProjectionMatrix;


flat out vec4 frag_color;
flat out vec3 frag_normal_cam;
flat out vec3 frag_posi_cam;

void main(){
    gl_Position     = osg_ModelViewProjectionMatrix * vec4(position, 1.0);
    frag_color      = color;
    frag_normal_cam = osg_NormalMatrix * norm;
    frag_posi_cam   = (osg_ModelViewMatrix * vec4(position, 1.0)).xyz;
    
}