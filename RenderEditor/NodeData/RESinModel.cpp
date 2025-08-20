#include "RESinModel.h"

#include "REFloatData.hpp"

RESinModel::RESinModel()
{
	_result = std::make_shared<REFloatData>();
}

unsigned int RESinModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 1;
	else
		result = 1;

	return result;
}

NodeDataType RESinModel::dataType(PortType, PortIndex) const
{
	return REFloatData().type();
}

void RESinModel::setInData(std::shared_ptr<NodeData> nodeData, PortIndex const portIndex)
{
	auto numberData = std::dynamic_pointer_cast<REFloatData>(nodeData);

	if (!nodeData) {
		Q_EMIT dataInvalidated(0);
	}

	if (portIndex == 0)
	{
		_result->setValue(std::sin(numberData->value()));
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RESinModel::outData(PortIndex)
{
	return std::static_pointer_cast<NodeData>(_result);
}
