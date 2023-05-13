#version 330 core
layout (location = 0) in vec2 aPos;
uniform mat4 model;

void main()
{
    gl_PointSize = 4.0f;
    gl_Position = model * vec4(aPos, 1.0, 1.0);
}
