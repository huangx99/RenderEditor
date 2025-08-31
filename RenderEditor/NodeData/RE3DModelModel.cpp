#include "RE3DModelModel.h"

#include "RE3DModelNode.hpp"
#include "REStringData.hpp"

RE3DModelModel::RE3DModelModel()
{
	_node = std::make_shared<RE3DModelNode>();

	_3DModelNode = std::dynamic_pointer_cast<RE3DModelNode>(_node);

	_result = _node;
}


unsigned int RE3DModelModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 3;
	else
		result = 1;

	return result;
}

NodeDataType RE3DModelModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("modelPath") };
		else if(index == 2)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("shader") };
	}

	return RE3DModelNode().type();
}

void RE3DModelModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (portIndex == 1)
	{
		RE3DModelParam param;
		auto str = std::dynamic_pointer_cast<REStringData>(data);
		param.modelPath = str->value();
		_3DModelNode->setParam(param);
	}
	else if (portIndex == 2)
	{
		auto str = std::dynamic_pointer_cast<REStringData>(data);
		_3DModelNode->setShader(str->value());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RE3DModelModel::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}