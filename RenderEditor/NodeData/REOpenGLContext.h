#pragma once

#include <map>
#include <string>

#include <QtGui/qopengl.h>

#include <QOpenGLShaderProgram>

class REOpenGLContext
{
public:
	REOpenGLContext();
	~REOpenGLContext();

	// VBO
	void addVBO(const std::string& name, GLuint id);
	bool removeVBO(const std::string& name);
	bool updateVBO(const std::string& name, GLuint newId);
	GLuint getVBO(const std::string& name) const;
	bool hasVBO(const std::string& name) const;

	// VAO
	void addVAO(const std::string& name, GLuint id);
	bool removeVAO(const std::string& name);
	bool updateVAO(const std::string& name, GLuint newId);
	GLuint getVAO(const std::string& name) const;
	bool hasVAO(const std::string& name) const;

	// EBO
	void addEBO(const std::string& name, GLuint id);
	bool removeEBO(const std::string& name);
	bool updateEBO(const std::string& name, GLuint newId);
	GLuint getEBO(const std::string& name) const;
	bool hasEBO(const std::string& name) const;

	// Texture
	void addTexture(const std::string& name, GLuint id);
	bool removeTexture(const std::string& name);
	bool updateTexture(const std::string& name, GLuint newId);
	GLuint getTexture(const std::string& name) const;
	bool hasTexture(const std::string& name) const;

	// ---- Shader ----
	void addShader(const std::string& name, std::shared_ptr<QOpenGLShaderProgram> program);
	bool removeShader(const std::string& name);
	bool updateShader(const std::string& name, std::shared_ptr<QOpenGLShaderProgram> program);
	std::shared_ptr<QOpenGLShaderProgram> getShader(const std::string& name) const;
	bool hasShader(const std::string& name) const;

	std::map<std::string, GLuint> getVBOs() { return _VBOs; }
	std::map<std::string, GLuint> getVAOs() { return _VAOs; }
	std::map<std::string, GLuint> getEBOs() { return _EBOs; }
	std::map<std::string, GLuint> getTextures() { return _textures; }
	std::map<std::string, std::shared_ptr<QOpenGLShaderProgram>> getShaders() { return _shaders; }

	void clear();

protected:
	std::map<std::string, GLuint> _VBOs;
	std::map<std::string, GLuint> _VAOs;
	std::map<std::string, GLuint> _EBOs;
	std::map<std::string, GLuint> _textures;
	std::map<std::string, std::shared_ptr<QOpenGLShaderProgram>> _shaders;
};
