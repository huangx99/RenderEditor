#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class REFloatData : public NodeData
{
public:
	REFloatData()
	{}

	REFloatData(float data)
		: _data(data)
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("float"), QString::fromUtf8("float") }; }

	float value() const { return _data; }

	void setValue(float value) { _data = value; }

private:
	float _data = 0;
};
