#include "RELoopEndModel.h"

#include "RELoopEndNode.hpp"
#include "REIntData.hpp"

RELoopEndModel::RELoopEndModel()
{
	_node = std::make_shared<RELoopEndNode>();
	_loopEndNode = std::dynamic_pointer_cast<RELoopEndNode>(_node);
	_result = _node;

	_count = std::make_shared<REIntData>(0);
}

unsigned int RELoopEndModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 3;
	else
		result = 1;

	return result;
}

NodeDataType RELoopEndModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);


	if(type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ QString("REOpenGLNode"),  QString::fromUtf8("循环节点") };
		else if (index == 2)
			return NodeDataType{ REIntData().type().id,  QString::fromUtf8("循环次数") };
	}

	return RELoopEndNode().type();
}

void RELoopEndModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);


	if (!data) {
		Q_EMIT dataInvalidated(0);
		if (portIndex == 1)
		{
			_loopEndNode->setLoopNode(nullptr);
		}
		return;
	}

	if (portIndex == 1)
	{
		auto node = std::dynamic_pointer_cast<REOpenGLNode>(data);
		_loopEndNode->setLoopNode(node);
	}
	else if (portIndex == 2)
	{
		auto count = std::dynamic_pointer_cast<REIntData>(data);
		_loopEndNode->setLoopCount(count->value());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RELoopEndModel::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


