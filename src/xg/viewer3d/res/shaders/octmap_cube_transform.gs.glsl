#version 410 core

precision highp float;

// supports points, lines, line_strip, triangles, triangle_strip, triangle_fan
layout(points, invocations = 1) in;
// supports points, line_strip, triangle_strip
layout(triangle_strip, max_vertices = 36) out;

in float box_size[];

out vec3 out_vert;
out vec3 out_norm;

void main(){
    vec3 posi = gl_in[0].gl_Position.xyz;

    float half_size = box_size[0] * 0.5;

    vec3 vertices[8] = vec3[](
        vec3(-half_size + posi.x, -half_size + posi.y, -half_size + posi.z), // b1
        vec3( half_size + posi.x, -half_size + posi.y, -half_size + posi.z), // b2
        vec3( half_size + posi.x,  half_size + posi.y, -half_size + posi.z), // b3
        vec3(-half_size + posi.x,  half_size + posi.y, -half_size + posi.z), // b4
        vec3(-half_size + posi.x, -half_size + posi.y,  half_size + posi.z), // t1
        vec3( half_size + posi.x, -half_size + posi.y,  half_size + posi.z), // t2
        vec3( half_size + posi.x,  half_size + posi.y,  half_size + posi.z), // t3
        vec3(-half_size + posi.x,  half_size + posi.y,  half_size + posi.z)  // t4
    );

    vec3 norms[6] = vec3[](
        vec3( 0,  0, -1 ), // down
        vec3( 0,  0,  1 ), // top
        vec3( 0, -1,  0 ), // front
        vec3( 0,  1,  0 ), // back
        vec3(-1,  0,  0 ), // left
        vec3( 1,  0,  0 )  // right
    );

    // 

    // Bottom
    out_norm = norms[0];
    out_vert = vertices[0];
    EmitVertex(); 
    
    out_vert = vertices[1];
    EmitVertex();

    out_vert = vertices[3];
    EmitVertex();
    EndPrimitive(); 
    
    out_vert = vertices[1];
    EmitVertex();

    out_vert = vertices[3];
    EmitVertex();

    out_vert = vertices[2];
    EmitVertex();
    EndPrimitive(); 

    // Top
    
    out_norm = norms[1];
    out_vert = vertices[4];
    EmitVertex();
    
    out_vert = vertices[5];
    EmitVertex();
    
    out_vert = vertices[7];
    EmitVertex();
    EndPrimitive(); 
        
    out_vert = vertices[5];
    EmitVertex();

    out_vert = vertices[7];
    EmitVertex();

    out_vert = vertices[6];
    EmitVertex();
    EndPrimitive(); 

    // Front
    out_norm = norms[2];
    out_vert = vertices[0];
    EmitVertex();
    
    out_vert = vertices[1];
    EmitVertex();
    
    out_vert = vertices[4];
    EmitVertex();
    EndPrimitive(); 
    
    out_vert = vertices[1];
    EmitVertex();

    out_vert = vertices[4];
    EmitVertex();

    out_vert = vertices[5];
    EmitVertex();
    EndPrimitive(); 

    // Back
    out_norm = norms[3];
    out_vert = vertices[2];
    EmitVertex();
    
    out_vert = vertices[3];
    EmitVertex();
    
    out_vert = vertices[6];
    EmitVertex();
    EndPrimitive(); 

    out_vert = vertices[3];
    EmitVertex();

    out_vert = vertices[6];
    EmitVertex();

    out_vert = vertices[7];
    EmitVertex();
    EndPrimitive(); 

    // Left
    out_norm = norms[4];
    out_vert = vertices[3];
    EmitVertex();
    
    out_vert = vertices[0];
    EmitVertex();
    
    out_vert = vertices[7];
    EmitVertex();
    EndPrimitive();

    out_vert = vertices[0];
    EmitVertex();

    out_vert = vertices[7];
    EmitVertex();

    out_vert = vertices[4];
    EmitVertex();
    EndPrimitive();

    
    // Right
    out_norm = norms[5];
    out_vert = vertices[1];
    EmitVertex();
    
    out_vert = vertices[2];
    EmitVertex();
    
    out_vert = vertices[5];
    EmitVertex();
    EndPrimitive();

    out_vert = vertices[2];
    EmitVertex();

    out_vert = vertices[5];
    EmitVertex();

    out_vert = vertices[6];
    EmitVertex();
    EndPrimitive(); 

}