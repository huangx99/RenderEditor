#include "REShader.h"
#include <QDebug>
REShader::REShader(const char * vertexPath, const char * fragmentPath)
{
	initializeOpenGLFunctions();

	shader.fsPath = fragmentPath;
	shader.vsPath = vertexPath;

	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		qDebug() << "ERROR::REShader::FILE_NOT_SUCCESSFULLY_READ: " << e.what();
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();
	// 2. compile shaders
	unsigned int vertex, fragment;
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");
	// fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");
	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	shader.ID = ID;
}

void REShader::use()
{
	glUseProgram(ID);
}

void REShader::distory()
{
	glDeleteProgram(ID);
}

void REShader::setBool(const std::string & name, bool value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void REShader::setInt(const std::string & name, int value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void REShader::setFloat(const std::string & name, float value)
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void REShader::setVec3f(const std::string & name, float value1, float value2, float value3)
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), value1, value2, value3);
}

void REShader::setVec3f(const std::string & name, const glm::vec3& value)
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
}

void REShader::setMat4f(const std::string & name, const glm::mat4 & mat)
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}


void REShader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			qDebug() << QString("ERROR::SHADER_COMPILATION_ERROR of type: %1\n%2\n -- --------------------------------------------------- --")
				.arg(QString::fromStdString(type))
				.arg(QString(infoLog));
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			qDebug() << QString("ERROR::PROGRAM_LINKING_ERROR of type: %1\n%2\n -- --------------------------------------------------- --")
				.arg(QString::fromStdString(type))
				.arg(QString(infoLog));
		}
	}
}
