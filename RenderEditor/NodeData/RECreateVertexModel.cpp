#include "RECreateVertexModel.h"

#include "RECreateVertexDataNode.h"
#include "REFloatArrayData.hpp"
#include "REStringData.hpp"

RECreateVertexModel::RECreateVertexModel()
{
	_node = std::make_shared<RECreateVertexDataNode>();
	_createVertexDataNode = std::dynamic_pointer_cast<RECreateVertexDataNode>(_node);
	_result = _node;

	_VAOID = std::make_shared<REStringData>(QString::fromStdString(_node->getID()));
}

unsigned int RECreateVertexModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 2;

	return result;
}

NodeDataType RECreateVertexModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REFloatArrayData().type().id,  QString::fromUtf8("顶点数据") };
	}
	else
	{
		if(index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("VAO") };
	}

	return RECreateVertexDataNode().type();
}

void RECreateVertexModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);


	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	else if (portIndex == 1)
	{
		auto floatArray = std::dynamic_pointer_cast<REFloatArrayData>(data);
		_createVertexDataNode->setVertices(floatArray->value());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RECreateVertexModel::outData(PortIndex index)
{
	if (index == 1)
	{
		return std::static_pointer_cast<NodeData>(_VAOID);
	}
	return std::static_pointer_cast<NodeData>(_result);
}


