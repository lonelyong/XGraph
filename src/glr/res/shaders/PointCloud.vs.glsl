#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 color;

uniform mat4 xg_matrix_mvp;

out vec4 frag_color;
// flat in, flat out，'flat'关键字不能一个有一个没有，不然某些驱动会报错
flat out int point_id;

void main(){
    gl_Position = xg_matrix_mvp * vec4(position.x, position.y, position.z, 1.0);
    gl_PointSize = clamp(position.z * 10, 5, 20);
    frag_color = vec4(color.x, color.y, color.z, 1.0);
    point_id = gl_VertexID;
}