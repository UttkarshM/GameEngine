#version 330 core
layout(location = 0) out vec4 FragColor;
uniform vec4 u_color;
void main()
{
  FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);
};