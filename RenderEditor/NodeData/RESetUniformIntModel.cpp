#include "RESetUniformIntModel.h"

#include "REUseShaderNode.hpp"
#include "REStringData.hpp"

RESetUniformIntModel::RESetUniformIntModel()
{
	_node = std::make_shared<RESetUniformNode<int>>();
	_result = _node;
	_setUniformNode = std::dynamic_pointer_cast<RESetUniformNode<int>>(_node);

	_editor = new REValueSetTimeEditor();

	_editor->adjustSize();
	connect(_editor, &REValueSetTimeEditor::dataUpdate, this, &RESetUniformIntModel::onDataUpdate);
}

QJsonObject RESetUniformIntModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto param = _editor->getTime();
	modelJson["valueTime"] = param;
	return modelJson;
}

void RESetUniformIntModel::load(QJsonObject const & modelJson)
{
	int time = 0;
	time = modelJson["valueTime"].toInt();
	_editor->setTime(time);
}

void RESetUniformIntModel::onDataUpdate()
{
	_setUniformNode->setTimeType((REValueSetTimeType)_editor->getTime());
}

unsigned int RESetUniformIntModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 4;
	else
		result = 1;

	return result;
}

NodeDataType RESetUniformIntModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
		return REOpenGLModel::dataType(type, index);

	if (type == PortType::In)
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("Shader") };
		else if(index == 2)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("name") };
		else if (index == 3)
			return NodeDataType{ REIntData().type().id,  QString::fromUtf8("value") };
	}

	return RESetUniformNode<int>().type();
}

void RESetUniformIntModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
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
		auto value = std::dynamic_pointer_cast<REIntData>(data);
		auto param = _setUniformNode->getParam();
		param._value = value->value();
		_setUniformNode->setParam(param);
	}
}

std::shared_ptr<NodeData> RESetUniformIntModel::outData(PortIndex index)
{
	return std::static_pointer_cast<NodeData>(_result);
}


