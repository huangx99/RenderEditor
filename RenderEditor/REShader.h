#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <QOpenGLFunctions_3_3_Core>
#include "REBaseType.h"
#include "REObjectStruct.h"

class REShader : protected QOpenGLFunctions_3_3_Core
{
public:
	unsigned int ID;
	RESShader shader;
	REShader(const char* vertexPath, const char* fragmentPath);
	void use();
	void distory();

	void setBool(const std::string &name, bool value);
	void setInt(const std::string &name, int value);
	void setFloat(const std::string &name, float value);

	void setVec3f(const std::string &name, float value1, float value2, float value3);
	void setVec3f(const std::string &name, const glm::vec3& value);

	void setMat4f(const std::string &name, const glm::mat4& mat);

private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(unsigned int shader, std::string type);
};

using REShaderPtr = std::shared_ptr<REShader>;