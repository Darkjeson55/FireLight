#version 330 core

layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;

uniform mat4 model;
uniform mat4 projection;

out vec3 vColor;

void main()
{
    gl_Position = projection * model * vec4(aPos, 1.0f);
    vColor = vec3(1.0f,0.0f,0.0f);
}