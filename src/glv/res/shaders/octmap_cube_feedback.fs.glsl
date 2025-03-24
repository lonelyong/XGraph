#version 410 core

precision highp float;

flat in vec4 frag_color;
flat in vec3 frag_normal_cam;
flat in vec3 frag_posi_cam;
//in vec4 box_color;
layout(location = 0) out vec4 FragColor;

void main(){
    const vec3 v_dir = vec3(0.0, 0.0, -1.0);
    const vec3 l_dir = vec3(0.0, 0.0, -1.0);
    const vec4 l_ambient = vec4(0.1, 0.1, 0.1, 1.0);
    const vec4 l_diffuse = vec4(0.8, 0.8, 0.8, 1.0);
    const vec4 l_specular = vec4(0.1, 0.1, 0.1, 1.0);
    const vec4 m_specular = vec4(0.2, 0.2, 0.2, 1.0);

    vec3 reflect_dir = reflect(-l_dir, frag_normal_cam);
    vec4 a = l_ambient * frag_color;
    vec4 d = l_diffuse * max(dot(-l_dir, frag_normal_cam), 0.0) * frag_color;
    // Phong
    // vec3 s = l.s.rgb * pow(max(dot(xg_view_dir, reflect_dir), 0.0), mate.sh) * mate.s.rgb;
    // Blinn_Phong
    // vec4 s = l_specular * pow(max(dot(normalize(l_dir + v_dir), frag_normal_cam), 0.0), 64.0) * m_specular;
    //FragColor = a + d + s;

    FragColor = a + d;
}