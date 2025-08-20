#pragma once
#include "REBaseType.h"

#define MAX_BONE_INFLUENCE 4
struct RESVertex {
	// position
	glm::vec3 Position;
	// normal
	glm::vec3 Normal;
	// texCoords
	glm::vec2 TexCoords;
	// tangent
	glm::vec3 Tangent;
	// bitangent
	glm::vec3 Bitangent;
	//bone indexes which will influence this vertex
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	//weights from each bone
	float m_Weights[MAX_BONE_INFLUENCE];
};

struct RESTexture{
	unsigned int id;
	std::string type;
	std::string path;
};

struct RESShader
{
	unsigned int ID;
	//顶点着色器
	std::string vsPath;
	//片段着色器
	std::string fsPath;

	//名称
	std::string name;
};


struct RESMesh
{
	std::vector<RESVertex>       vertices;
	std::vector<unsigned int> indices;
	std::vector<RESTexture>      textures;
	unsigned int VAO;
};

enum REEObjectType
{
	OT_NULL = -1,
	//普通物体
	OT_OBJECT,
	//灯光
	OT_LIGHT
};

struct RESObject
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scalar;

	glm::mat4 rotateMat;
	glm::mat4 model;

	int id;
	std::string name;

};