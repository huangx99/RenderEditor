
#include "REIntSourceDataModel.h"
#include "REIntData.hpp"

REIntSourceDataModel::REIntSourceDataModel()
{
	_editor = new QSpinBox();
	
	_editor->setValue(0);
	_editor->setMinimum(-9999999);
	_editor->setMaximum(9999999);
	_editor->adjustSize();
	connect(_editor, QOverload<int>::of(&QSpinBox::valueChanged), this, &REIntSourceDataModel::onValueChanged);
}

QJsonObject REIntSourceDataModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	modelJson["value"] = _editor->value();
	return modelJson;
}

void REIntSourceDataModel::load(QJsonObject const & config)
{
	_editor->setValue(config["value"].toInt());
}

unsigned int REIntSourceDataModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 0;
	else
		result = 1;

	return result;
}

NodeDataType REIntSourceDataModel::dataType(PortType, PortIndex) const
{
	return REIntData().type();
}

std::shared_ptr<NodeData> REIntSourceDataModel::outData(PortIndex index)
{
	_result = std::make_shared<REIntData>(_editor->value());

	return std::static_pointer_cast<NodeData>(_result);
}


void REIntSourceDataModel::onValueChanged(int value)
{
	Q_EMIT dataUpdated(0);
}