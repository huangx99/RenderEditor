#version 330 core
#extension GL_ARB_separate_shader_objects : enable
out vec4 FragColor;
in vec3 color;
in vec2 textureCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() 
{ 
	FragColor = mix(texture(texture1, textureCoord), texture(texture2, textureCoord), 0.2); 
}