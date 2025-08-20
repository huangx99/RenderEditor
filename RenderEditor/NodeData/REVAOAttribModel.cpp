#include "REVAOAttribModel.h"

#include "REVAOAttribNode.hpp"
#include "REStringData.hpp"

REVAOAttribModel::REVAOAttribModel()
{
	_node = std::make_shared<REVAOAttribNode>();

	_VAOAttribNode = std::dynamic_pointer_cast<REVAOAttribNode>(_node);

	_editor = new REVAOAttribEditor();
	_editor->adjustSize();
	_result = _node;

	connect(_editor, &REVAOAttribEditor::dataUpdate, this, &REVAOAttribModel::onDataUpdate);
}

QJsonObject REVAOAttribModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto param = _editor->getParam();
	modelJson["byteSize"] = param.byteSize;
	modelJson["count"] = param.count;
	modelJson["location"] = param.location;
	modelJson["openMap"] = param.openMap;
	modelJson["stride"] = param.stride;
	modelJson["type"] = (int)param.type;
	return modelJson;
}

void REVAOAttribModel::load(QJsonObject const & modelJson)
{
	REVAOAttribParam param;
	param.byteSize = modelJson["byteSize"].toInt();
	param.count = modelJson["count"].toInt();
	param.location = modelJson["location"].toInt();
	param.openMap = modelJson["openMap"].toBool();
	param.stride = modelJson["stride"].toInt();
	param.type = modelJson["type"].toInt();
	_editor->setParam(param);
}

unsigned int REVAOAttribModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType REVAOAttribModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("VAO") };
	}

	return REVAOAttribNode().type();
}

void REVAOAttribModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		if (portIndex == 1)
		{
			_VAOAttribNode->setVAO("");
		}

		return;
	}

	if (portIndex == 1)
	{
		auto str = std::dynamic_pointer_cast<REStringData>(data);
		_VAOAttribNode->setVAO(str->value().toStdString());
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> REVAOAttribModel::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


void REVAOAttribModel::onDataUpdate()
{
	if (_VAOAttribNode)
	{
		_VAOAttribNode->setParam(_editor->getParam());
	}

	Q_EMIT dataUpdated(0);
}