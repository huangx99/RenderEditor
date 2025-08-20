#include "REVec3ComputeModel.h"

#include "REVec3Data.hpp"

REVec3ComputeModel::REVec3ComputeModel()
{
}

unsigned int REVec3ComputeModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType REVec3ComputeModel::dataType(PortType, PortIndex) const
{
	return REVec3Data().type();
}

void REVec3ComputeModel::setInData(std::shared_ptr<NodeData> nodeData, PortIndex const portIndex)
{
	auto numberData = std::dynamic_pointer_cast<REVec3Data>(nodeData);

	if (!nodeData) {
		Q_EMIT dataInvalidated(0);
	}

	if (portIndex == 0)
	{
		_vec3a = numberData;
	}
	else if (portIndex == 1)
	{
		_vec3b = numberData;
	}

	compute();

}

std::shared_ptr<NodeData> REVec3ComputeModel::outData(PortIndex)
{
	return std::static_pointer_cast<NodeData>(_result);
}
