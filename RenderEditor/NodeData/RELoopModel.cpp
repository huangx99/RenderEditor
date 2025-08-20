#include "RELoopModel.h"

#include "RELoopNode.hpp"
#include "REIntData.hpp"
#include "REFloatData.hpp"

RELoopModel::RELoopModel()
{
	_node = std::make_shared<RELoopNode>();
	_loopNode = std::dynamic_pointer_cast<RELoopNode>(_node);
	_result = _node;

	_loopNode->setModel(this);
	_count = std::make_shared<REIntData>(0);
	_residualCount = std::make_shared<REFloatData>(0);
}

unsigned int RELoopModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 4;

	return result;
}

NodeDataType RELoopModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REIntData().type().id,  QString::fromUtf8("循环次数") };
	}
	else
	{
		if(index == 1)
			return NodeDataType{ QString("REOpenGLNode"),  QString::fromUtf8("循环节点") };
		else if (index == 2)
			return NodeDataType{ REIntData().type().id,  QString::fromUtf8("循环次数") };
		else if (index == 3)
			return NodeDataType{ REFloatData().type().id,  QString::fromUtf8("剩余循环次数") };
	}

	return RELoopNode().type();
}

void RELoopModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);


	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (portIndex == 0)
	{
		Q_EMIT dataUpdated(0);
		Q_EMIT dataUpdated(1);
	}

	if (portIndex == 1)
	{
		_count = std::dynamic_pointer_cast<REIntData>(data);
		RELoopNodeParam param;
		param.count = _count->value();
		_loopNode->setParam(param);

		Q_EMIT dataUpdated(2);
	}

	
}

std::shared_ptr<NodeData> RELoopModel::outData(PortIndex index)
{
	if (index == 2)
	{
		return std::static_pointer_cast<NodeData>(_count);
	}
	else if (index == 3)
	{
		_residualCount->setValue(_loopNode->getResidualCount());
		return std::static_pointer_cast<NodeData>(_residualCount);
	}
	return std::static_pointer_cast<NodeData>(_result);
}

void RELoopModel::updateCount()
{
	Q_EMIT dataUpdated(3);
}


