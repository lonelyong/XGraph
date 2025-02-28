#version 460 core

precision highp float;

layout(points, invocations = 1) in;
layout(triangle_strip, max_vertices = 24) out;

in float box_size[];
in vec4 box_color[];

uniform mat3 osg_NormalMatrix;
uniform mat4 osg_ModelViewMatrix;
uniform mat4 osg_ModelViewProjectionMatrix;

flat out vec4 frag_color;
flat out vec3 frag_normal_cam;
flat out vec3 frag_posi_cam;

void main(){
    vec3 posi = gl_in[0].gl_Position.xyz;

    float half_size = box_size[0] * 0.5;

    vec4 vertices_clip[8] = vec4[](
        osg_ModelViewProjectionMatrix * vec4(-half_size + posi.x, -half_size + posi.y, -half_size + posi.z, 1.0), // b1
        osg_ModelViewProjectionMatrix * vec4( half_size + posi.x, -half_size + posi.y, -half_size + posi.z, 1.0), // b2
        osg_ModelViewProjectionMatrix * vec4( half_size + posi.x,  half_size + posi.y, -half_size + posi.z, 1.0), // b3
        osg_ModelViewProjectionMatrix * vec4(-half_size + posi.x,  half_size + posi.y, -half_size + posi.z, 1.0), // b4
        osg_ModelViewProjectionMatrix * vec4(-half_size + posi.x, -half_size + posi.y,  half_size + posi.z, 1.0), // t1
        osg_ModelViewProjectionMatrix * vec4( half_size + posi.x, -half_size + posi.y,  half_size + posi.z, 1.0), // t2
        osg_ModelViewProjectionMatrix * vec4( half_size + posi.x,  half_size + posi.y,  half_size + posi.z, 1.0), // t3
        osg_ModelViewProjectionMatrix * vec4(-half_size + posi.x,  half_size + posi.y,  half_size + posi.z, 1.0)  // t4
    );

    vec4 vertices_cam[8] = vec4[](
        osg_ModelViewMatrix * vec4(-half_size + posi.x, -half_size + posi.y, -half_size + posi.z, 1.0), // b1
        osg_ModelViewMatrix * vec4( half_size + posi.x, -half_size + posi.y, -half_size + posi.z, 1.0), // b2
        osg_ModelViewMatrix * vec4( half_size + posi.x,  half_size + posi.y, -half_size + posi.z, 1.0), // b3
        osg_ModelViewMatrix * vec4(-half_size + posi.x,  half_size + posi.y, -half_size + posi.z, 1.0), // b4
        osg_ModelViewMatrix * vec4(-half_size + posi.x, -half_size + posi.y,  half_size + posi.z, 1.0), // t1
        osg_ModelViewMatrix * vec4( half_size + posi.x, -half_size + posi.y,  half_size + posi.z, 1.0), // t2
        osg_ModelViewMatrix * vec4( half_size + posi.x,  half_size + posi.y,  half_size + posi.z, 1.0), // t3
        osg_ModelViewMatrix * vec4(-half_size + posi.x,  half_size + posi.y,  half_size + posi.z, 1.0)  // t4
    );
    
    vec3 norms_cam[6] = vec3[](
        osg_NormalMatrix * vec3( 0,  0, -1 ), // down
        osg_NormalMatrix * vec3( 0,  0,  1 ), // top
        osg_NormalMatrix * vec3( 0, -1,  0 ), // front
        osg_NormalMatrix * vec3( 0,  1,  0 ), // back
        osg_NormalMatrix * vec3(-1,  0,  0 ), // left
        osg_NormalMatrix * vec3( 1,  0,  0 ) // right
    );

    frag_color = box_color[0];

    // Bottom
    
    frag_normal_cam = norms_cam[0];
    frag_posi_cam = vertices_cam[0].xyz;
    gl_Position = vertices_clip[0];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[1].xyz;
    gl_Position = vertices_clip[1];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[3].xyz;
    gl_Position = vertices_clip[3];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[2].xyz;
    gl_Position = vertices_clip[2];
    EmitVertex();
    EndPrimitive(); 

    // Top
    
    frag_normal_cam = norms_cam[1];
    frag_posi_cam = vertices_cam[4].xyz;
    gl_Position = vertices_clip[4];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[5].xyz;
    gl_Position = vertices_clip[5];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[7].xyz;
    gl_Position = vertices_clip[7];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[6].xyz;
    gl_Position = vertices_clip[6];
    EmitVertex();
    EndPrimitive(); 

    // Front
    frag_normal_cam = norms_cam[2];
    frag_posi_cam = vertices_cam[0].xyz;
    gl_Position = vertices_clip[0];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[1].xyz;
    gl_Position = vertices_clip[1];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[4].xyz;
    gl_Position = vertices_clip[4];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[5].xyz;
    gl_Position = vertices_clip[5];
    EmitVertex();
    EndPrimitive(); 

    // Back
    frag_normal_cam = norms_cam[3];
    frag_posi_cam = vertices_cam[2].xyz;
    gl_Position = vertices_clip[2];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[3].xyz;
    gl_Position = vertices_clip[3];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[6].xyz;
    gl_Position = vertices_clip[6];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[7].xyz;
    gl_Position = vertices_clip[7];
    EmitVertex();
    EndPrimitive(); 

    // Left
    frag_normal_cam = norms_cam[4];
    frag_posi_cam = vertices_cam[3].xyz;
    gl_Position = vertices_clip[3];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[0].xyz;
    gl_Position = vertices_clip[0];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[7].xyz;
    gl_Position = vertices_clip[7];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[4].xyz;
    gl_Position = vertices_clip[4];
    EmitVertex();
    EndPrimitive();

    
    // Right
    frag_normal_cam = norms_cam[5];
    frag_posi_cam = vertices_cam[1].xyz;
    gl_Position = vertices_clip[1];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[2].xyz;
    gl_Position = vertices_clip[2];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[5].xyz;
    gl_Position = vertices_clip[5];
    EmitVertex();
    
    frag_posi_cam = vertices_cam[6].xyz;
    gl_Position = vertices_clip[6];
    EmitVertex();
    EndPrimitive(); 

}