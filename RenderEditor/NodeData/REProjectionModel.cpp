#include "REProjectionModel.h"

REProjectionModel::REProjectionModel()
{
	_zoom = std::make_shared<REFloatData>(45.0);
	_scrWidth = std::make_shared<REFloatData>(800);
	_scrHeight = std::make_shared<REFloatData>(600);
	_near = std::make_shared<REFloatData>(0.1f);
	_far = std::make_shared<REFloatData>(100.0);
}

unsigned int REProjectionModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 5;
	else
		result = 1;

	return result;
}

NodeDataType REProjectionModel::dataType(PortType type, PortIndex index) const
{
	if (type == PortType::In)
	{
		std::vector<QString> name{ "zoom", "width", "height", "near", "far"};
		return NodeDataType{ REFloatData().type().id, name[index] };
	}
	else if (type == PortType::Out)
	{
		if (index == 0)
		{
			return REMat4Data().type();
		}
	}
	return REMat4Data().type();
}

void REProjectionModel::setInData(std::shared_ptr<NodeData> data, PortIndex const index)
{
	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	switch (index)
	{
	case 0:
		_zoom = std::dynamic_pointer_cast<REFloatData>(data);
		break;
	case 1:
		_scrWidth = std::dynamic_pointer_cast<REFloatData>(data);
		break;
	case 2:
		_scrHeight = std::dynamic_pointer_cast<REFloatData>(data);
		break;
	case 3:
		_near = std::dynamic_pointer_cast<REFloatData>(data);
		break;
	case 4:
		_far = std::dynamic_pointer_cast<REFloatData>(data);
		break;
	default:
		break;
	}

	emit dataUpdated(0);
}

std::shared_ptr<NodeData> REProjectionModel::outData(PortIndex)
{
	glm::mat4 projection = glm::perspective
	(
		glm::radians(_zoom->value()),
		(float)_scrWidth->value() / (float)_scrHeight->value(),
		_near->value(), 
		_far->value()
	);

	_result = std::make_shared<REMat4Data>(projection);

	return std::static_pointer_cast<NodeData>(_result);
}
