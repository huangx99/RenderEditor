#version 330 core
#extension GL_ARB_separate_shader_objects : enable
out vec4 FragColor;
in vec2 TexCoord;
in vec3 objectColor;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 lightColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() 
{ 
	float ambientStrength = 0.05;
    vec3 ambient = ambientStrength * lightColor;
	
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

    vec3 result = (diffuse + ambient) * objectColor;
    FragColor = vec4(result, 1.0);
}