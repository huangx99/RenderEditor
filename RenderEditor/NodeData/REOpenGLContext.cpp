#include "REOpenGLContext.h"
#include <stdexcept>

// 构造函数
REOpenGLContext::REOpenGLContext() {}

// 析构函数
REOpenGLContext::~REOpenGLContext() 
{
}

// ---- VBO ----
void REOpenGLContext::addVBO(const std::string& name, GLuint id) {
	_VBOs[name] = id;
}

bool REOpenGLContext::removeVBO(const std::string& name) {
	return _VBOs.erase(name) > 0;
}

bool REOpenGLContext::updateVBO(const std::string& name, GLuint newId) {
	if (_VBOs.find(name) != _VBOs.end()) {
		_VBOs[name] = newId;
		return true;
	}
	return false;
}

GLuint REOpenGLContext::getVBO(const std::string& name) const {
	auto it = _VBOs.find(name);
	if (it != _VBOs.end()) {
		return it->second;
	}
	return 0;
}

bool REOpenGLContext::hasVBO(const std::string& name) const {
	return _VBOs.find(name) != _VBOs.end();
}

// ---- VAO ----
void REOpenGLContext::addVAO(const std::string& name, GLuint id) {
	_VAOs[name] = id;
}

bool REOpenGLContext::removeVAO(const std::string& name) {
	return _VAOs.erase(name) > 0;
}

bool REOpenGLContext::updateVAO(const std::string& name, GLuint newId) {
	if (_VAOs.find(name) != _VAOs.end()) {
		_VAOs[name] = newId;
		return true;
	}
	return false;
}

GLuint REOpenGLContext::getVAO(const std::string& name) const {
	auto it = _VAOs.find(name);
	if (it != _VAOs.end()) {
		return it->second;
	}
	return 0;
}

bool REOpenGLContext::hasVAO(const std::string& name) const {
	return _VAOs.find(name) != _VAOs.end();
}

// ---- EBO ----
void REOpenGLContext::addEBO(const std::string& name, GLuint id) {
	_EBOs[name] = id;
}

bool REOpenGLContext::removeEBO(const std::string& name) {
	return _EBOs.erase(name) > 0;
}

bool REOpenGLContext::updateEBO(const std::string& name, GLuint newId) {
	if (_EBOs.find(name) != _EBOs.end()) {
		_EBOs[name] = newId;
		return true;
	}
	return false;
}

GLuint REOpenGLContext::getEBO(const std::string& name) const {
	auto it = _EBOs.find(name);
	if (it != _EBOs.end()) {
		return it->second;
	}
	return 0;
}

bool REOpenGLContext::hasEBO(const std::string& name) const {
	return _EBOs.find(name) != _EBOs.end();
}

// ---- Texture ----
void REOpenGLContext::addTexture(const std::string& name, GLuint id) {
	_textures[name] = id;
}

bool REOpenGLContext::removeTexture(const std::string& name) {
	return _textures.erase(name) > 0;
}

bool REOpenGLContext::updateTexture(const std::string& name, GLuint newId) {
	if (_textures.find(name) != _textures.end()) {
		_textures[name] = newId;
		return true;
	}
	return false;
}

GLuint REOpenGLContext::getTexture(const std::string& name) const {
	auto it = _textures.find(name);
	if (it != _textures.end()) {
		return it->second;
	}
	return 0;
}

bool REOpenGLContext::hasTexture(const std::string& name) const {
	return _textures.find(name) != _textures.end();
}

void REOpenGLContext::addShader(const std::string& name, std::shared_ptr<QOpenGLShaderProgram> program)
{
	_shaders[name] = program;
}

bool REOpenGLContext::removeShader(const std::string& name)
{
	auto it = _shaders.find(name);
	if (it != _shaders.end())
	{
		_shaders.erase(it); // 自动释放
		return true;
	}
	return false;
}

bool REOpenGLContext::updateShader(const std::string& name, std::shared_ptr<QOpenGLShaderProgram> program)
{
	auto it = _shaders.find(name);
	if (it != _shaders.end())
	{
		it->second = program; // 自动释放旧对象
		return true;
	}
	return false;
}

std::shared_ptr<QOpenGLShaderProgram> REOpenGLContext::getShader(const std::string& name) const
{
	auto it = _shaders.find(name);
	if (it != _shaders.end())
		return it->second;
	return nullptr;
}

bool REOpenGLContext::hasShader(const std::string& name) const
{
	return _shaders.find(name) != _shaders.end();
}

void REOpenGLContext::clear()
{
	_VBOs.clear();
	_VAOs.clear();
	_EBOs.clear();
	_textures.clear();
	_shaders.clear();
}
