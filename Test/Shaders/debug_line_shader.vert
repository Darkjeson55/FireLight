#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    ourColor = aColor;
    gl_Position = projection * view * model * vec4(aPos, 0.0f, 1.0);
}