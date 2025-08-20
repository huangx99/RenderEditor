#include "RESetUniformVec3Model.h"

#include "REUseShaderNode.hpp"
#include "REStringData.hpp"

RESetUniformVec3Model::RESetUniformVec3Model()
{
	_node = std::make_shared<RESetUniformNode<QVector3D>>();
	_result = _node;
	_setUniformNode = std::dynamic_pointer_cast<RESetUniformNode<QVector3D>>(_node);

	_editor = new REValueSetTimeEditor();

	_editor->adjustSize();
	connect(_editor, &REValueSetTimeEditor::dataUpdate, this, &RESetUniformVec3Model::onDataUpdate);
}

QJsonObject RESetUniformVec3Model::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto param = _editor->getTime();
	modelJson["valueTime"] = param;
	return modelJson;
}

void RESetUniformVec3Model::load(QJsonObject const & modelJson)
{
	int time = 0;
	time = modelJson["valueTime"].toInt();
	_editor->setTime(time);
}

void RESetUniformVec3Model::onDataUpdate()
{
	_setUniformNode->setTimeType((REValueSetTimeType)_editor->getTime());
}

unsigned int RESetUniformVec3Model::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 4;
	else
		result = 1;

	return result;
}

NodeDataType RESetUniformVec3Model::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
	{
		return REOpenGLModel::dataType(type, index);
	}

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("Shader") };
		else if (index == 2)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("name") };
		else if (index == 3)
			return NodeDataType{ REVec3Data().type().id,  QString::fromUtf8("value") };
	}

	return RESetUniformNode<QVector3D>().type();
}

void RESetUniformVec3Model::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
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
	}
	else if (portIndex == 1)
	{
		auto shader = std::dynamic_pointer_cast<REStringData>(data);
		_setUniformNode->setShader(shader->value());
	}
	else if (portIndex == 2)
	{
		auto name = std::dynamic_pointer_cast<REStringData>(data);
		auto param = _setUniformNode->getParam();
		param._name = name->value();
		_setUniformNode->setParam(param);
	}
	else if (portIndex == 3)
	{
		auto value = std::dynamic_pointer_cast<REVec3Data>(data);
		auto param = _setUniformNode->getParam();
		glm::vec3 vec3 = value->value();
		param._value = QVector3D(vec3.x, vec3.y, vec3.y);
		_setUniformNode->setParam(param);
	}
}

std::shared_ptr<NodeData> RESetUniformVec3Model::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


