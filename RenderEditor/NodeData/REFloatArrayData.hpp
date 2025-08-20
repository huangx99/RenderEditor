#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class REFloatArrayData : public NodeData
{
public:
	REFloatArrayData()
	{}

	REFloatArrayData(const std::vector<float>& floatArray)
		: _floatArray(floatArray)
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("floatArray"), QString::fromUtf8("floatArray") }; }

	std::vector<float> value() const { return _floatArray; }

private:
	std::vector<float> _floatArray;
};
