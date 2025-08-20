#include "REGLClearColorModel.h"

#include "REGLClearColorNode.hpp"
#include "REVec3Data.hpp"

REGLClearColorModel::REGLClearColorModel()
{
	_node = std::make_shared<REGLClearColorNode>();
	_result = _node;
}

unsigned int REGLClearColorModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType REGLClearColorModel::dataType(PortType type, PortIndex index) const
{
	if(index == 0)
		return REOpenGLModel::dataType(type, index);

	return REVec3Data().type();
}

void REGLClearColorModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);
		return;
	}

	if (portIndex == 1)
	{
		auto vec3Data = std::dynamic_pointer_cast<REVec3Data>(data);
		glm::vec3 color = vec3Data->value();
		auto node = std::dynamic_pointer_cast<REGLClearColorNode>(_node);
		node->setColor(glm::vec4(color.r, color.g, color.b, 1.0));
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> REGLClearColorModel::outData(PortIndex)
{
	return std::static_pointer_cast<NodeData>(_result);
}


