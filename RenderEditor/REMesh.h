#pragma once
#include <QOpenGLFunctions_3_3_Core>
#include "REBaseType.h"
#include "REShader.h"
#include "REObjectStruct.h"
class REMesh : protected QOpenGLFunctions_3_3_Core
{
public:
	RESMesh mesh;
	REMesh();
	REMesh(std::vector<RESVertex> vertices, std::vector<unsigned int> indices, std::vector<RESTexture> textures);
	
	void initMesh(std::vector<RESVertex> vertices, std::vector<unsigned int> indices, std::vector<RESTexture> textures);

	void draw(REShader& shader);

private:
	unsigned int VBO, EBO;

	void setupMesh();
};

