#include "REFloatSourceDataModel.h"

#include "REFloatData.hpp"

REFloatSourceDataModel::REFloatSourceDataModel()
{
	_editor = new QDoubleSpinBox();
	_editor->setMaximum(99999999999);
	_editor->setMinimum(-99999999999);
	_editor->setDecimals(6);
	_editor->setValue(0.);
	_editor->adjustSize();
	connect(_editor, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &REFloatSourceDataModel::onValueChanged);

	
}

QJsonObject REFloatSourceDataModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	modelJson["value"] = _editor->value();
	return modelJson;
}

void REFloatSourceDataModel::load(QJsonObject const & config)
{
	_editor->setValue(config["value"].toDouble());
}

unsigned int REFloatSourceDataModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 0;
	else
		result = 1;

	return result;
}

NodeDataType REFloatSourceDataModel::dataType(PortType, PortIndex) const
{
	return REFloatData().type();
}

std::shared_ptr<NodeData> REFloatSourceDataModel::outData(PortIndex index)
{
	_result = std::make_shared<REFloatData>(_editor->value());

	return std::static_pointer_cast<NodeData>(_result);
}


void REFloatSourceDataModel::onValueChanged(double value)
{
	Q_EMIT dataUpdated(0);
}
