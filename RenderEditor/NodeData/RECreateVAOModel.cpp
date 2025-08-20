#include "RECreateVAOModel.h"

#include "RECreateVAONode.hpp"
#include "REFloatArrayData.hpp"
#include "REStringData.hpp"

RECreateVAOModel::RECreateVAOModel()
{
	_node = std::make_shared<RECreateVAONode>();
	_vaoID = std::make_shared<REStringData>(QString::fromStdString(_node->getID()));

	_result = _node;
}

unsigned int RECreateVAOModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 1;
	else
		result = 2;

	return result;
}

NodeDataType RECreateVAOModel::dataType(PortType type, PortIndex index) const
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
		else if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("VAO") };
	}

	return REFloatArrayData().type();
}

void RECreateVAOModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
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
		
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RECreateVAOModel::outData(PortIndex index)
{
	if (index == 1)
	{
		return std::static_pointer_cast<NodeData>(_vaoID);
	}
	return std::static_pointer_cast<NodeData>(_result);
}


