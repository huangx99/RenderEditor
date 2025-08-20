#include "RECreateTextureModel.h"

#include "RECreateTextureNode.hpp"
#include "REPixmapData.hpp"
#include "REStringData.hpp"

RECreateTextureModel::RECreateTextureModel()
{
	_node = std::make_shared<RECreateTextureNode>();
	_result = _node;

	_createTextureNode = std::dynamic_pointer_cast<RECreateTextureNode>(_node);

	_textureID = std::make_shared<REStringData>(QString::fromStdString(_node->getID()));
	

	//connect(_editor, &RECreateShaderEditor::dataUpdate, this, &RECreateTextureModel::onDataUpdate);
}

void RECreateTextureModel::onDataUpdate()
{
	
}

unsigned int RECreateTextureModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 2;

	return result;
}

NodeDataType RECreateTextureModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);
	

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REPixmapData().type().id,  QString::fromUtf8("纹理") };
	}
	else
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("Texture") };
	}

	return RECreateTextureNode().type();
}

void RECreateTextureModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (portIndex == 1)
	{
		auto pixmap = std::dynamic_pointer_cast<REPixmapData>(data);
		_createTextureNode->setPixelMap(pixmap->pixmap());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RECreateTextureModel::outData(PortIndex index)
{
	if (index == 0)
	{
		return std::static_pointer_cast<NodeData>(_result);
	}
	else if (index == 1)
	{
		return std::static_pointer_cast<NodeData>(_textureID);
	}

	return nullptr;
}

QWidget * RECreateTextureModel::embeddedWidget()
{
	return nullptr;
}
