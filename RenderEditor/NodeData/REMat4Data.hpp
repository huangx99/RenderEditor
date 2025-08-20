#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class REMat4Data : public NodeData
{
public:
	REMat4Data()
	{}

	REMat4Data(const glm::mat4& data)
		: _data(data)
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("Mat4"), QString::fromUtf8("Mat4") }; }

	glm::mat4 value() const { return _data; }
	void setValue(const glm::mat4 & value) { _data = value; }

private:
	glm::mat4 _data;
};
