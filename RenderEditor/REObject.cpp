#include "REObject.h"

REObject::REObject()
{
}

REObject::~REObject()
{
}

void REObject::setPosition(const glm::vec3 & position)
{
	m_object.position = position;
}

glm::vec3 REObject::getPosition() const
{
	return m_object.position;
}

void REObject::setRotation(float angle, const glm::vec3 & axis)
{

}

glm::mat4 REObject::getRotateMat() const
{
	return m_object.rotateMat;
}

void REObject::setScalar(const glm::vec3 & scalar)
{
}

glm::vec3 REObject::getScalar() const
{
	return m_object.scalar;
}

void REObject::setModelMat(const glm::mat4 & model)
{

}

glm::mat4 REObject::getModelMat() const
{
	return m_object.model;
}

void REObject::setShader(REShaderPtr shader)
{
	m_shader = shader;
}

void REObject::setMesh(const REMesh & mesh)
{
	m_mesh = mesh;
}

void REObject::draw()
{
	m_shader->use();
	glm::mat4 translate;
	translate = glm::translate(translate, m_object.position);
	m_shader->setMat4f("model", translate);
}
