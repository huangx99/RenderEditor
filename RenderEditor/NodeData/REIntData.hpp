#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class REIntData : public NodeData
{
public:
	REIntData()
	{}

	REIntData(int data)
		: _data(data)
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("int"), QString::fromUtf8("int") }; }

	int value() const { return _data; }

	void setValue(int data) { _data = data; }

private:
	int _data;
};
