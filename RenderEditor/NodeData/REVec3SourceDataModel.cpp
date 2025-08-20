#include "REVec3SourceDataModel.h"

#include "REVec3Data.hpp"
#include "REFloatData.hpp"

REVec3SourceDataModel::REVec3SourceDataModel()
{
	_editor = new REVec3Editor();
	_editor->adjustSize();

	connect(_editor, &REVec3Editor::valueEdited, this, &REVec3SourceDataModel::onValueEdit);
}

QJsonObject REVec3SourceDataModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto value = _editor->getValue();
	modelJson["x"] = value.x;
	modelJson["y"] = value.y;
	modelJson["z"] = value.z;
	return modelJson;
}

void REVec3SourceDataModel::load(QJsonObject const & modelJson)
{
	glm::vec3 value;
	value.x = modelJson["x"].toDouble();
	value.y = modelJson["y"].toDouble();
	value.z = modelJson["z"].toDouble();
	_editor->setValue(value);
}

unsigned int REVec3SourceDataModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 3;
	else
		result = 1;

	return result;
}

NodeDataType REVec3SourceDataModel::dataType(PortType type, PortIndex) const
{
	if (type == PortType::In)
	{
		return REFloatData().type();
	}
	return REVec3Data().type();
}

void REVec3SourceDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}
	auto floatData = std::dynamic_pointer_cast<REFloatData>(data);
	glm::vec3 value = _editor->getValue();
	if (portIndex == 0)
	{
		value.x = floatData->value();
	}
	else if (portIndex == 1)
	{
		value.y = floatData->value();
	}
	else if (portIndex == 2)
	{
		value.z = floatData->value();
	}

	_editor->setValue(value);

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> REVec3SourceDataModel::outData(PortIndex)
{
	glm::vec3 value;

	value = _editor->getValue();

	_result = std::make_shared<REVec3Data>(value);

	return std::static_pointer_cast<NodeData>(_result);
}


void REVec3SourceDataModel::onValueEdit(const glm::vec3 &value)
{
	Q_EMIT dataUpdated(0);
}