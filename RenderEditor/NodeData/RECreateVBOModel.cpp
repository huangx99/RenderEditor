#include "RECreateVBOModel.h"

#include "RECreateVBONode.hpp"
#include "REFloatArrayData.hpp"

RECreateVBOModel::RECreateVBOModel()
{
	_node = std::make_shared<RECreateVBONode>();
	_result = _node;
}

unsigned int RECreateVBOModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType RECreateVBOModel::dataType(PortType type, PortIndex index) const
{
	if (type == PortType::In)
	{
		if (index == 0)
			return NodeDataType{ QString("REOpenGLNode"),  QString::fromUtf8("函数注入") };
	}
	else
	{
		if (index == 0)
			return NodeDataType{ QString("REOpenGLNode"),  QString::fromUtf8("函数输出") };
	}

	return REFloatArrayData().type();
}

void RECreateVBOModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (portIndex == 0)
	{
		auto node = std::dynamic_pointer_cast<REOpenGLNode>(data);
		_node->setNode(node);

		_result = _node;
	}
	else if (portIndex == 1)
	{
		auto floatArray = std::dynamic_pointer_cast<REFloatArrayData>(data);
		_node->setVertices(floatArray->value());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RECreateVBOModel::outData(PortIndex)
{
	return std::static_pointer_cast<NodeData>(_result);
}


