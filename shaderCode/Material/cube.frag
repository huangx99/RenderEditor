#version 330 core
#extension GL_ARB_separate_shader_objects : enable
out vec4 FragColor;
in vec2 TexCoord;
in vec3 objectColor;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

uniform sampler2D texture1;
uniform sampler2D texture2;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

uniform Material material;

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

void main() 
{ 
    vec3 ambient = material.specular * light.ambient;
	
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = (material.diffuse * diff) * light.diffuse;


	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = material.specular * spec * light.specular;

    vec3 result = (diffuse + ambient + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}