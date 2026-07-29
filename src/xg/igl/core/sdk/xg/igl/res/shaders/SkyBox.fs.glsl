#version 330 core
#extension GL_ARB_shader_image_load_store : enable
layout(early_fragment_tests) in;
uniform samplerCube tex_cube;
in vec3 frag_tex_coord;
out vec4 FragColor;
void main(){
    vec4 color = texture(tex_cube, frag_tex_coord);
    FragColor = color;
}