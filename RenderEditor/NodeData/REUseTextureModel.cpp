#include "REUseTextureModel.h"

#include "REUseTextureNode.hpp"
#include "REPixmapData.hpp"
#include "REStringData.hpp"
#include "REIntData.hpp"

REUseTextureModel::REUseTextureModel()
{
	_node = std::make_shared<REUseTextureNode>();
	_result = _node;

	_useTextureNode = std::dynamic_pointer_cast<REUseTextureNode>(_node);
}

void REUseTextureModel::onDataUpdate()
{

}

unsigned int REUseTextureModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 3;
	else
		result = 1;

	return result;
}

NodeDataType REUseTextureModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("Texture") };
		else if (index == 2)
			return NodeDataType{ REIntData().type().id,  QString::fromUtf8("纹理位置") };
	}

	return REUseTextureNode().type();
}

void REUseTextureModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (portIndex == 1)
	{
		auto texture = std::dynamic_pointer_cast<REStringData>(data);
		_useTextureNode->setTexture(texture->value());
	}
	else if (portIndex == 2)
	{
		auto index = std::dynamic_pointer_cast<REIntData>(data);
		_useTextureNode->setTextureIndex(index->value());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> REUseTextureModel::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}

QWidget * REUseTextureModel::embeddedWidget()
{
	return nullptr;
}
