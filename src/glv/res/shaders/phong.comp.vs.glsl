#version 460 compatibility

// layout(location = 0) in vec3 position;
// layout(location = 3) in vec4 color;

/*
in int gl_VertexID;   // only present when not targeting Vulkan
in int gl_InstanceID; // only present when not targeting Vulkan
in int gl_DrawID;
in int gl_BaseVertex;
in int gl_BaseInstance;

out gl_PerVertex {
    vec4 gl_Position;
    float gl_PointSize;
    vec4 gl_ClipVertex;          // 用户裁剪平面坐标,与gl_ClipDistance、gl_CullDistance不能同时用
    float gl_ClipDistance[];     // 逐片段裁剪,在光栅化阶段会裁剪所有 gl_ClipDistance[n] < 0 的片元;gl3.0
    float gl_CullDistance[];     // 逐图元裁剪,如果一个图元的所有顶点 gl_CullDistance[n] < 0，则整个图元会被剔除;gl4.5;GL_ARB_cull_distance 
    vec4 gl_FrontColor;          // 主颜色（正面）
    vec4 gl_BackColor;           // 主颜色（背面）
    vec4 gl_FrontSecondaryColor; // 次颜色（正面）
    vec4 gl_BackSecondaryColor;  // 次颜色（背面）
    vec4 gl_TexCoord[];          // 纹理坐标
    float gl_FogFragCoord;       // 雾坐标
};
*/

//// call State::setUseModelViewAndProjectionUniforms(true) to replace gl_ to osg_
//uniform mat4 gl_ModelViewMatrix;
//uniform mat4 gl_ProjectionMatrix;
//uniform mat4 gl_ModelViewProjectionMatrix;
//uniform mat3 gl_NormalMatrix;

/* Compatibility Profile Vertex Shader Built-In Inputs
in vec4 gl_Color;
in vec4 gl_SecondaryColor;
in vec3 gl_Normal;
in vec4 gl_Vertex;
in vec4 gl_MultiTexCoord0;
in vec4 gl_MultiTexCoord1;
in vec4 gl_MultiTexCoord2;
in vec4 gl_MultiTexCoord3;
in vec4 gl_MultiTexCoord4;
in vec4 gl_MultiTexCoord5;
in vec4 gl_MultiTexCoord6;
in vec4 gl_MultiTexCoord7;
in float gl_FogCoord;
*/
out vec4 frag_color;
out vec3 frag_norm;
out vec3 frag_posi;

void main(){
  int a1 = gl_VertexID;
  int a2 = gl_InstanceID;
  int a3 = gl_DrawID;
  int a4 = gl_BaseVertex;
  int a5 = gl_BaseInstance;

  // 
  gl_Position = gl_ModelViewProjectionMatrix * vec4(gl_Vertex.x, gl_Vertex.y, gl_Vertex.z, 1.0);
  frag_color = gl_Color;
  frag_norm = gl_Normal;
  frag_posi = gl_Position.xyz;
}

/************************************************************************
 ************************************************************************
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