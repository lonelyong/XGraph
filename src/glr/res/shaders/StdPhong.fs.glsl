#version 460 core

#define MAX_LIGHT 8

// #extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_shader_image_load_store : enable

layout(early_fragment_tests) in;

in vec4 frag_color;
in vec2 frag_tex_coord2;
in vec3 frag_tex_coord3;
in vec3 frag_world_posi;
in vec3 frag_world_norm;

struct PhongMaterial{
    vec4 emission; // Ecm
    vec4 ambient; // Acm
    vec4 diffuse; // Dcm
    vec4 specular; // Scm
    float shininess; // Srm
};

struct PhongLight{
    vec4 ambient; // Acli
    vec4 diffuse; // Dcli
    vec4 specular; // Scli
    vec4 position; // Ppli
    vec4 halfVector; // Derived: Hi
    vec3 spotDirection; // Sdli
    float spotExponent; // Srli
    float spotCutoff;   // Crli
    // (range: [0.0,90.0], 180.0)
    float spotCosCutoff; // Derived: cos(Crli)
    // (range: [1.0,0.0],-1.0)
    float constantAttenuation; // K0
    float linearAttenuation;   // K1
    float quadraticAttenuation;// K2
};

uniform sampler2D tex_2d;
uniform samplerCube tex_cube;
uniform sampler3D tex_3d;
uniform PhongMaterial mate;
uniform PhongLight lights[MAX_LIGHT];
uniform int lights_count = 0;
uniform vec3 xg_view_dir;
uniform bool xg_is_lighting_enabled;


subroutine vec4 FetchColor();
subroutine uniform FetchColor fetchColor;

subroutine(FetchColor)
vec4 fetchTexture2D() {
    return texture(tex_2d, frag_tex_coord2);
}

subroutine(FetchColor)
vec4 fetchTextureCube() {
    return texture(tex_cube, frag_tex_coord3);
}

subroutine(FetchColor)
vec4 fetchTexture3D() {
    return texture(tex_3d, frag_tex_coord3);
}

subroutine(FetchColor)
vec4 fetchVertexColor() {
    return frag_color;
}

subroutine(FetchColor)
vec4 fetchMaterialColor() {
    return mate.diffuse;
}

out vec4 FragColor;

vec4 get_directional_light_contribution(PhongLight l){
    vec3 l_dir = l.position.xyz;
    vec3 reflect_dir = reflect(l_dir, frag_world_norm);
    vec4 a = l.ambient * mate.ambient;
    vec4 d = l.diffuse * max(dot(-l_dir, frag_world_norm), 0) * fetchColor();
    // Phong
    // vec3 s = l.s.rgb * pow(max(dot(xg_view_dir, reflect_dir), 0.0), mate.sh) * mate.s.rgb;
    // Blinn_Phong
    vec4 s = l.specular * pow(max(dot(normalize(-l_dir + xg_view_dir), frag_world_norm), 0.0), mate.shininess) * mate.specular;
    return a + d + s;
}

vec4 get_spot_light_contribution(PhongLight l){
    vec3 l_dir = normalize(frag_world_posi - l.position.xyz);
    vec3 reflect_dir = reflect(l_dir, frag_world_norm);
    vec4 a = l.ambient * mate.ambient;
    vec4 d = l.diffuse * max(dot(-l_dir, frag_world_norm), 0) * fetchColor();
    vec4 s = l.specular * pow(max(dot(xg_view_dir, reflect_dir), 0.0), mate.shininess) * mate.specular;
    return a + d + s;
}

void main(){
    vec4 color = fetchColor();
    if(xg_is_lighting_enabled && lights_count > 0){
        vec4 c = vec4(0, 0, 0, 0);
        for(int i = 0; i < lights_count; i++){
            if(i >= MAX_LIGHT)
                break;
            PhongLight l = lights[i];
            if(l.position.w == 1.0){
                c += get_directional_light_contribution(l);
            }
            else{
                c += get_spot_light_contribution(l);
            }
        }
        color = c;
    }
    FragColor = color;
}