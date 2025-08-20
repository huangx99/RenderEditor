#include "REGLDrawArraysMode.h"

#include "REGLDrawArraysNode.hpp"
#include "REStringData.hpp"

REGLDrawArraysMode::REGLDrawArraysMode()
{
	_node = std::make_shared<REGLDrawArraysNode>();
	_drawArrayNode = std::dynamic_pointer_cast<REGLDrawArraysNode>(_node);
	_editor = new REDrawArraysEditor();
	_editor->adjustSize();
	_result = _node;

	connect(_editor, &REDrawArraysEditor::dataUpdate, this, &REGLDrawArraysMode::onDataUpdate);
}

QJsonObject REGLDrawArraysMode::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto param = _editor->getParam();
	modelJson["mode"] = (int)param.mode;
	modelJson["pointCount"] = param.pointCount;
	modelJson["startIndex"] = param.startIndex;
	return modelJson;
}

void REGLDrawArraysMode::load(QJsonObject const & modelJson)
{
	REDrawArraysParam param;
	param.mode = modelJson["mode"].toInt();
	param.pointCount = modelJson["pointCount"].toInt();
	param.startIndex = modelJson["startIndex"].toInt();
	_editor->setParam(param);
}


unsigned int REGLDrawArraysMode::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType REGLDrawArraysMode::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
	{
		return REOpenGLModel::dataType(type, index);
	}
	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("VAO") };
	}

	return REGLDrawArraysNode().type();
}

void REGLDrawArraysMode::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if(portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		if (portIndex == 1)
		{
			_drawArrayNode->setVAO("");
		}

		return;
	}


	if (portIndex == 1)
	{
		auto str = std::dynamic_pointer_cast<REStringData>(data);

		_drawArrayNode->setVAO(str->value().toStdString());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> REGLDrawArraysMode::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


void REGLDrawArraysMode::onDataUpdate()
{
	if (_drawArrayNode)
	{
		_drawArrayNode->setParam(_editor->getParam());
	}

	Q_EMIT dataUpdated(0);
}