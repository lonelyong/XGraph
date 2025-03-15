#version 410 core

precision highp float;

layout(points, invocations = 1) in;
layout(triangle_strip, max_vertices = 24) out;

in float box_size[];

flat out vec3 norm;

void main(){
    vec3 posi = gl_in[0].gl_Position.xyz;

    float half_size = box_size[0] * 0.5;

    vec4 vertices[8] = vec4[](
        vec4(-half_size + posi.x, -half_size + posi.y, -half_size + posi.z, 1.0), // b1
        vec4( half_size + posi.x, -half_size + posi.y, -half_size + posi.z, 1.0), // b2
        vec4( half_size + posi.x,  half_size + posi.y, -half_size + posi.z, 1.0), // b3
        vec4(-half_size + posi.x,  half_size + posi.y, -half_size + posi.z, 1.0), // b4
        vec4(-half_size + posi.x, -half_size + posi.y,  half_size + posi.z, 1.0), // t1
        vec4( half_size + posi.x, -half_size + posi.y,  half_size + posi.z, 1.0), // t2
        vec4( half_size + posi.x,  half_size + posi.y,  half_size + posi.z, 1.0), // t3
        vec4(-half_size + posi.x,  half_size + posi.y,  half_size + posi.z, 1.0)  // t4
    );

    vec3 norms[6] = vec3[](
        vec3( 0,  0, -1 ), // down
        vec3( 0,  0,  1 ), // top
        vec3( 0, -1,  0 ), // front
        vec3( 0,  1,  0 ), // back
        vec3(-1,  0,  0 ), // left
        vec3( 1,  0,  0 ) // right
    );

    // Bottom
    
    norm = norms[0];
    gl_Position = vertices[0];
    EmitVertex();
    
    gl_Position = vertices[1];
    EmitVertex();
    
    gl_Position = vertices[3];
    EmitVertex();
    
    gl_Position = vertices[2];
    EmitVertex();
    EndPrimitive(); 

    // Top
    
    norm = norms[1];
    gl_Position = vertices[4];
    EmitVertex();
    
    gl_Position = vertices[5];
    EmitVertex();
    
    gl_Position = vertices[7];
    EmitVertex();
    
    gl_Position = vertices[6];
    EmitVertex();
    EndPrimitive(); 

    // Front
    norm = norms[2];
    gl_Position = vertices[0];
    EmitVertex();
    
    gl_Position = vertices[1];
    EmitVertex();
    
    gl_Position = vertices[4];
    EmitVertex();
    
    gl_Position = vertices[5];
    EmitVertex();
    EndPrimitive(); 

    // Back
    norm = norms[3];
    gl_Position = vertices[2];
    EmitVertex();
    
    gl_Position = vertices[3];
    EmitVertex();
    
    gl_Position = vertices[6];
    EmitVertex();
    
    gl_Position = vertices[7];
    EmitVertex();
    EndPrimitive(); 

    // Left
    norm = norms[4];
    gl_Position = vertices[3];
    EmitVertex();
    
    gl_Position = vertices[0];
    EmitVertex();
    
    gl_Position = vertices[7];
    EmitVertex();
    
    gl_Position = vertices[4];
    EmitVertex();
    EndPrimitive();

    
    // Right
    norm = norms[5];
    gl_Position = vertices[1];
    EmitVertex();
    
    gl_Position = vertices[2];
    EmitVertex();
    
    gl_Position = vertices[5];
    EmitVertex();
    
    gl_Position = vertices[6];
    EmitVertex();
    EndPrimitive(); 

}