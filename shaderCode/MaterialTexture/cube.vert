#version 330
#extension GL_ARB_separate_shader_objects : enable
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
uniform vec3 color;

out vec3 objectColor;
out vec3 Normal;
out vec3 FragPos;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
	objectColor = color;
	//解决非等比缩放后法线偏移问题
	Normal = mat3(transpose(inverse(model))) * aNormal;
	FragPos = vec3(model * vec4(aPos, 1.0));

	TexCoords = aTexCoords;
}