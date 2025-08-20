#include "RESetUniformMat4Model.h"

#include "REUseShaderNode.hpp"
#include "REStringData.hpp"

RESetUniformMat4Model::RESetUniformMat4Model()
{
	_node = std::make_shared<RESetUniformNode<QMatrix4x4>>();
	_result = _node;
	_setUniformNode = std::dynamic_pointer_cast<RESetUniformNode<QMatrix4x4>>(_node);

	_editor = new REValueSetTimeEditor();

	_editor->adjustSize();
	connect(_editor, &REValueSetTimeEditor::dataUpdate, this, &RESetUniformMat4Model::onDataUpdate);
}

QJsonObject RESetUniformMat4Model::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto param = _editor->getTime();
	modelJson["valueTime"] = param;
	return modelJson;
}

void RESetUniformMat4Model::load(QJsonObject const & modelJson)
{
	int time = 0;
	time = modelJson["valueTime"].toInt();
	_editor->setTime(time);
}

void RESetUniformMat4Model::onDataUpdate()
{
	_setUniformNode->setTimeType((REValueSetTimeType)_editor->getTime());
}

unsigned int RESetUniformMat4Model::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 4;
	else
		result = 1;

	return result;
}

NodeDataType RESetUniformMat4Model::dataType(PortType type, PortIndex index) const
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
			return NodeDataType{ REMat4Data().type().id,  QString::fromUtf8("value") };
	}

	return RESetUniformNode<QMatrix4x4>().type();
}

void RESetUniformMat4Model::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
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
		auto value = std::dynamic_pointer_cast<REMat4Data>(data);
		auto param = _setUniformNode->getParam();
		param._value = QMatrix4x4(glm::value_ptr(value->value())).transposed();
		_setUniformNode->setParam(param);
	}
}

std::shared_ptr<NodeData> RESetUniformMat4Model::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


