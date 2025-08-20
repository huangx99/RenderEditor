#version 330 core
#extension GL_ARB_separate_shader_objects : enable
out vec4 FragColor;
in vec2 TexCoord;

in vec3 cubeColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() 
{ 
	FragColor = vec4(cubeColor,1.0); 
}