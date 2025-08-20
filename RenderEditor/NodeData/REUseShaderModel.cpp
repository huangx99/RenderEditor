#include "REUseShaderModel.h"

#include "REUseShaderNode.hpp"
#include "REStringData.hpp"

REUseShaderModel::REUseShaderModel()
{
	_node = std::make_shared<REUseShaderNode>();
	_result = _node;

	_useShaderNode = std::dynamic_pointer_cast<REUseShaderNode>(_node);
}

unsigned int REUseShaderModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType REUseShaderModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		 if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("Shader") };
	}

	return REUseShaderNode().type();
}

void REUseShaderModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (portIndex == 1)
	{
		auto shader = std::dynamic_pointer_cast<REStringData>(data);
		_useShaderNode->setShader(shader->value());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> REUseShaderModel::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


