#version 330 core
layout(location=0) in vec3 position;
// the pos of camera is (0,0,0)
uniform mat4 matrix_mvp_;
out vec3 frag_tex_coord;
void main(){
    vec4 posi = matrix_mvp_ * vec4(position, 1.0);
    posi.z = posi.w;
    gl_Position = posi;
    frag_tex_coord = position;
}