#version 420 core

#define MAX_LIGHT 8

// #extension GL_ARB_explicit_uniform_location : enable
// #extension GL_ARB_shader_image_load_store : enable

// layout(early_fragment_tests) in;

in vec4 frag_color;
in vec2 frag_tex_coord2;
in vec3 frag_tex_coord3;
in vec3 frag_world_posi;
in vec3 frag_world_norm;

struct PhongMaterial {
    vec4  emission;  // Ecm
    vec4  ambient;   // Acm
    vec4  diffuse;   // Dcm
    vec4  specular;  // Scm
    float shininess; // Srm
};

struct PhongLight {
    vec4  ambient;       // Acli
    vec4  diffuse;       // Dcli
    vec4  specular;      // Scli
    vec4  position;      // Ppli
    vec4  halfVector;    // Derived: Hi
    vec3  spotDirection; // Sdli
    float spotExponent;  // Srli
    // (range: [0.0,90.0], 180.0)
    float spotCutoff; // Crli
    // (range: [1.0,0.0],-1.0)
    float spotCosCutoff;        // Derived: cos(Crli)
    float constantAttenuation;  // K0
    float linearAttenuation;    // K1
    float quadraticAttenuation; // K2
};

// 如果sampler不赋值的话，不去使用是没问题的（NV\AMD\INTEL）
// 在subroutine中引用了，实际没有执行该subroutine的话(NV警告)(MESA无法渲染)
uniform sampler2D     tex_2d;
uniform samplerCube   tex_cube;
uniform sampler3D     tex_3d;

uniform PhongMaterial mate;
uniform PhongLight    lights[MAX_LIGHT];
uniform int           lights_count = 0;
uniform vec3          xg_view_dir;
uniform bool          xg_is_lighting_enabled;


subroutine vec4               FetchColor();
subroutine uniform FetchColor fetchColor;

subroutine(FetchColor) vec4 fetchTexture2D() {
    return texture(tex_2d, frag_tex_coord2);
}

subroutine(FetchColor) vec4 fetchTextureCube() {
    return texture(tex_cube, frag_tex_coord3);
}

subroutine(FetchColor) vec4 fetchTexture3D() {
    return texture(tex_3d, frag_tex_coord3);
}

subroutine(FetchColor) vec4 fetchVertexColor() {
    return frag_color;
}

subroutine(FetchColor) vec4 fetchMaterialColor() {
    return mate.diffuse;
}

out vec4 FragColor;

vec4 get_directional_light_contribution(PhongLight l) {
    vec3 l_dir    = l.position.xyz;
    vec4 a        = l.ambient * mate.ambient;
    vec4 d        = l.diffuse * max(dot(-l_dir, frag_world_norm), 0) * fetchColor();
    // Phong
    // vec3 reflect_dir = reflect(l_dir, frag_world_norm);
    // vec3 s = l.s.rgb * pow(max(dot(xg_view_dir, reflect_dir), 0.0), mate.sh) * mate.s.rgb;
    // Blinn_Phong
    vec3 half_vec = normalize(-l_dir + xg_view_dir);
    vec4 s        = l.specular * pow(max(dot(frag_world_norm, half_vec), 0.0), mate.shininess) * mate.specular;

    return a + d + s;
}

vec4 get_point_light_contribution(PhongLight l) {
    vec3 l_dir    = normalize(frag_world_posi - l.position.xyz);
    vec3 half_vec = normalize(-l_dir + xg_view_dir);
    vec4 a        = l.ambient * fetchColor();
    vec4 d        = l.diffuse * max(dot(-l_dir, frag_world_norm), 0) * fetchColor();
    vec4 s        = l.specular * pow(max(dot(frag_world_norm, half_vec), 0.0), mate.shininess) * mate.specular;

    float dist = length(l.position.xyz - frag_world_posi);
    float attenuation =
        1.0 / (l.constantAttenuation + l.linearAttenuation * dist + l.quadraticAttenuation * (dist * dist));

    //a *= attenuation;
    d *= attenuation;
    s *= attenuation;
    return a + d + s;
}

vec4 get_spot_light_contribution(PhongLight l) {
    vec3 l_dir = normalize(frag_world_posi - l.position.xyz);
    vec4 a = vec4(0), d = vec4(0), s = vec4(0);

    float n_dot_l     = max(dot(-l_dir, frag_world_norm), 0.0);
    float attenuation = 1.0;

    if (n_dot_l > 0.0) {
        float ld_dot_sd = dot(l_dir, l.spotDirection);
        if (ld_dot_sd > l.spotCosCutoff) {
            float spot_effect = pow(ld_dot_sd, l.spotExponent);
            vec3  half_vec    = normalize(-l_dir + xg_view_dir);
            d                 = l.diffuse * n_dot_l * fetchColor();
            s = l.specular * pow(max(dot(frag_world_norm, half_vec), 0.0), mate.shininess) * mate.specular;


            float dist  = length(l.position.xyz - frag_world_posi);
            attenuation = spot_effect /
                          (l.constantAttenuation + l.linearAttenuation * dist + l.quadraticAttenuation * (dist * dist));
        }
    }
    a = l.ambient * fetchColor();


    // a *= attenuation;
    d *= attenuation;
    s *= attenuation;
    return a + d + s;
}

void main() {
    vec4 color = fetchColor();
    if (xg_is_lighting_enabled && lights_count > 0) {
        vec4 c = vec4(0, 0, 0, 0);
        for (int i = 0; i < lights_count; i++) {
            if (i >= MAX_LIGHT) break;
            PhongLight l = lights[i];
            if (l.position.w == 1.0) {
                c += get_directional_light_contribution(l);
            }
            else if (l.spotCutoff == 180.) {
                c += get_point_light_contribution(l);
            }
            else {
                c += get_spot_light_contribution(l);
            }
        }
        color = c;
    }
    FragColor = color;
}