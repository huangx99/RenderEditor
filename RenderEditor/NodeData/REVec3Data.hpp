#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class REVec3Data : public NodeData
{
public:
	REVec3Data()
	{}

	REVec3Data(const glm::vec3& vec3)
		: _vec3(vec3)
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("vec3"), QString::fromUtf8("vec3") }; }

	glm::vec3 value() const { return _vec3; }

	void setValue(const glm::vec3& value) { _vec3 = value; }

private:
	glm::vec3 _vec3 = glm::vec3(0.);
};
