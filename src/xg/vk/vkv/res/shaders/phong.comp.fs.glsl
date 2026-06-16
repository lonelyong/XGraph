#version 460 compatibility

/*
in gl_PerFragment {
    in float gl_FogFragCoord;  // 雾坐标
    in vec4 gl_TexCoord[];     // 纹理坐标
    in vec4 gl_Color;          // 片段颜色
    in vec4 gl_SecondaryColor; // 次要颜色
};

out vec4 gl_FragColor;
out vec4 gl_FragData[gl_MaxDrawBuffers];
*/

in vec4 frag_color;
in vec3 frag_norm;
in vec3 frag_posi;

out vec4 FragColor;

struct MaterialParameters {
 vec4 emission; // Ecm
 vec4 ambient; // Acm
 vec4 diffuse; // Dcm
 vec4 specular; // Scm
 float shininess; // Srm
};
//uniform gl_MaterialParameters gl_FrontMaterial;
//uniform gl_MaterialParameters gl_BackMaterial;

struct LightSourceParameters {
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
//uniform gl_LightSourceParameters gl_LightSource[gl_MaxLights];


vec4 get_directional_light_contribution(gl_LightSourceParameters l, gl_MaterialParameters m){
    vec3 v_dir =  (gl_ModelViewMatrixInverse * vec4(0, 0, -1, 0)).xyz;
    vec3 l_dir = l.position.xyz;
    vec3 reflect_dir = reflect(l_dir, frag_norm);
    vec4 a = l.ambient * m.ambient;
    vec4 d = l.diffuse * max(dot(l_dir, frag_norm), 0) * m.diffuse;
    // Phong
    // vec3 s = l.s.rgb * pow(max(dot(view_dir, reflect_dir), 0.0), mate.sh) * mate.s.rgb;
    // Blinn_Phong
    vec4 s = l.specular * pow(max(dot(normalize(l_dir + v_dir), frag_norm), 0.0), m.shininess) * m.specular;
    return a + d + s;
}

vec4 get_spot_light_contribution(gl_LightSourceParameters l, gl_MaterialParameters m){
    vec3 v_dir =  (gl_ModelViewMatrixInverse * vec4(0, 0, -1, 0)).xyz;
    vec3 l_dir = normalize(frag_posi - l.position.xyz);
    vec3 reflect_dir = reflect(l_dir, frag_norm);
    vec4 a = l.ambient * m.ambient;
    vec4 d = l.diffuse * max(dot(-l_dir, frag_norm), 0);
    vec4 s = l.specular * pow(max(dot(v_dir, reflect_dir), 0.0), m.shininess) * m.specular;
    return a + d + s;
}

void main(){
// 固定管线模式下,Light默认为平行光
if(gl_LightSource[0].position.w == 0){
    FragColor = get_directional_light_contribution(gl_LightSource[1], gl_FrontMaterial);
    
    vec4 ldir = gl_LightSource[1].position;
    vec4 vdir = gl_ModelViewMatrixInverse * vec4(0, 0, -1, 0);

//  FragColor = gl_ModelViewMatrixInverse * vec4(0, 0, -1, 0);
//  FragColor = gl_LightSource[1].diffuse;
    FragColor = vec4(abs(ldir.x), abs(ldir.y), abs(ldir.z), 1.0);
//    FragColor = vec4(abs(vdir.x), abs(vdir.y), abs(vdir.z), 1.0);
    
}
else{
    FragColor = get_spot_light_contribution(gl_LightSource[0], gl_FrontMaterial);
}

// vec4 color = gl_FrontMaterial.ambient;
   
//    FragColor = gl_FrontMaterial.diffuse;
//    FragColor = vec4(gl_LightSource[0].position.xyz, 1.0);
//    FragColor = gl_LightSource[0].position;
}

/*
//
// Depth range in window coordinates, 
//
struct gl_DepthRangeParameters {
 float near; // n
 float far; // f
 float diff; // f - n
};
uniform gl_DepthRangeParameters gl_DepthRange;
*/

/*
// These variables are present only in the compatibility profile.
//
// compatibility profile only
//
uniform mat4 gl_ModelViewMatrix;
uniform mat4 gl_ProjectionMatrix;
uniform mat4 gl_ModelViewProjectionMatrix;
uniform mat4 gl_TextureMatrix[gl_MaxTextureCoords];
//
// compatibility profile only
//
uniform mat3 gl_NormalMatrix; // transpose of the inverse of the 
// upper leftmost 3x3 of gl_ModelViewMatrix
uniform mat4 gl_ModelViewMatrixInverse;
uniform mat4 gl_ProjectionMatrixInverse;
uniform mat4 gl_ModelViewProjectionMatrixInverse;
uniform mat4 gl_TextureMatrixInverse[gl_MaxTextureCoords];
uniform mat4 gl_ModelViewMatrixTranspose;
uniform mat4 gl_ProjectionMatrixTranspose;
uniform mat4 gl_ModelViewProjectionMatrixTranspose;
uniform mat4 gl_TextureMatrixTranspose[gl_MaxTextureCoords];
uniform mat4 gl_ModelViewMatrixInverseTranspose;
uniform mat4 gl_ProjectionMatrixInverseTranspose;
uniform mat4 gl_ModelViewProjectionMatrixInverseTranspose;
uniform mat4 gl_TextureMatrixInverseTranspose[gl_MaxTextureCoords];
//
// compatibility profile only
//
uniform float gl_NormalScale;
//
// compatibility profile only
//
uniform vec4 gl_ClipPlane[gl_MaxClipPlanes];
//
// compatibility profile only
//
struct gl_PointParameters {
 float size;
 float sizeMin;
 float sizeMax;
 float fadeThresholdSize;
 float distanceConstantAttenuation;
 float distanceLinearAttenuation;
 float distanceQuadraticAttenuation;
};
uniform gl_PointParameters gl_Point;
//
// compatibility profile only
//
struct gl_MaterialParameters {
 vec4 emission; // Ecm
 vec4 ambient; // Acm
 vec4 diffuse; // Dcm
 vec4 specular; // Scm
 float shininess; // Srm
};
uniform gl_MaterialParameters gl_FrontMaterial;
uniform gl_MaterialParameters gl_BackMaterial;
75
7 Built-in Variables
//
// compatibility profile only
//
struct gl_LightSourceParameters {
 vec4 ambient; // Acli
 vec4 diffuse; // Dcli
 vec4 specular; // Scli
 vec4 position; // Ppli
 vec4 halfVector; // Derived: Hi
 vec3 spotDirection; // Sdli
 float spotExponent; // Srli
 float spotCutoff; // Crli
 // (range: [0.0,90.0], 180.0)
 float spotCosCutoff; // Derived: cos(Crli)
 // (range: [1.0,0.0],-1.0)
 float constantAttenuation; // K0
 float linearAttenuation; // K1
 float quadraticAttenuation;// K2
};
uniform gl_LightSourceParameters gl_LightSource[gl_MaxLights];
struct gl_LightModelParameters {
 vec4 ambient; // Acs
};
uniform gl_LightModelParameters gl_LightModel;
//
// compatibility profile only
//
// Derived state from products of light and material.
//
struct gl_LightModelProducts {
 vec4 sceneColor; // Derived. Ecm + Acm * Acs
};
uniform gl_LightModelProducts gl_FrontLightModelProduct;
uniform gl_LightModelProducts gl_BackLightModelProduct; 
struct gl_LightProducts {
 vec4 ambient; // Acm * Acli
 vec4 diffuse; // Dcm * Dcli
 vec4 specular; // Scm * Scli
};
uniform gl_LightProducts gl_FrontLightProduct[gl_MaxLights];
uniform gl_LightProducts gl_BackLightProduct[gl_MaxLights];
//
// compatibility profile only
//
uniform vec4 gl_TextureEnvColor[gl_MaxTextureUnits];
uniform vec4 gl_EyePlaneS[gl_MaxTextureCoords];
uniform vec4 gl_EyePlaneT[gl_MaxTextureCoords];
uniform vec4 gl_EyePlaneR[gl_MaxTextureCoords];
uniform vec4 gl_EyePlaneQ[gl_MaxTextureCoords];
uniform vec4 gl_ObjectPlaneS[gl_MaxTextureCoords];
uniform vec4 gl_ObjectPlaneT[gl_MaxTextureCoords];
uniform vec4 gl_ObjectPlaneR[gl_MaxTextureCoords];
uniform vec4 gl_ObjectPlaneQ[gl_MaxTextureCoords];
//
// compatibility profile only
//
struct gl_FogParameters {
 vec4 color;
 float density;
 float start;
 float end;
 float scale; // Derived: 1.0 / (end - start)
};
uniform gl_FogParameters gl_Fog;
*/
