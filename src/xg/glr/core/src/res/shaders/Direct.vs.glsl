#version 420 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec4 color;

uniform mat4 xg_matrix_m;
uniform mat4 xg_matrix_v;
uniform mat4 xg_matrix_mv;
uniform mat4 xg_matrix_mvp;

out vec4 frag_color;

void main(){
    gl_Position = xg_matrix_mvp * vec4(position.x, position.y, position.z, 1.0);
    frag_color = color;
}