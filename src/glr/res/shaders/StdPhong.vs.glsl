#version 420 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec4 color;
layout(location=3) in vec2 tex_coord2;
layout(location=4) in vec3 tex_coord3;

layout(binding = 0) uniform mat4 xg_matrix_m;
layout(binding = 1) uniform mat4 xg_matrix_v;
layout(binding = 2) uniform mat4 xg_matrix_mv;
layout(binding = 3) uniform mat4 xg_matrix_mvp;

out vec4 frag_color;
out vec2 frag_tex_coord2;
out vec3 frag_tex_coord3;
out vec3 frag_world_posi;
out vec3 frag_world_norm;

void main(){
    gl_Position = xg_matrix_mvp * vec4(position.x, position.y, position.z, 1.0);
    frag_color = color;
    frag_tex_coord2 = tex_coord2;
    frag_tex_coord3 = tex_coord3;

    frag_world_posi = mat3(xg_matrix_m) * position;
    frag_world_norm = mat3(xg_matrix_m) * normal;
}