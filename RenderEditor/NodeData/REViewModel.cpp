#include "REViewModel.h"

REViewModel::REViewModel()
{
	_position = std::make_shared<REVec3Data>(glm::vec3(0., 0., 0.));
	_front = std::make_shared<REVec3Data>(glm::vec3(0., 0., -1.));
	_up = std::make_shared<REVec3Data>(glm::vec3(0., 1., 0.));
}

unsigned int REViewModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 3;
	else
		result = 1;

	return result;
}

NodeDataType REViewModel::dataType(PortType type, PortIndex index) const
{
	if (type == PortType::In)
	{
		if (index == 0)
		{
			return NodeDataType{ REVec3Data().type().id, QString::fromUtf8("position") };
		}
		else if (index == 1)
		{
			return NodeDataType{ REVec3Data().type().id, QString::fromUtf8("front") };
		}
		else if (index == 2)
		{
			return NodeDataType{ REVec3Data().type().id, QString::fromUtf8("up") };
		}
	}
	else if (type == PortType::Out)
	{
		if (index == 0)
		{
			return NodeDataType{ REMat4Data().type().id, QString::fromUtf8("view mat") };
		}
	}
	return REMat4Data().type();
}

void REViewModel::setInData(std::shared_ptr<NodeData> data, PortIndex const index)
{
	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	if (index == 0)
	{
		_position = std::dynamic_pointer_cast<REVec3Data>(data);
	}
	else if (index == 1)
	{
		_front = std::dynamic_pointer_cast<REVec3Data>(data);
	}
	else if (index == 2)
	{
		_up = std::dynamic_pointer_cast<REVec3Data>(data);
	}

	emit dataUpdated(0);
}

std::shared_ptr<NodeData> REViewModel::outData(PortIndex)
{
	
	auto resultData = glm::lookAt(_position->value(), _position->value() + _front->value(), _up->value());

	_result = std::make_shared<REMat4Data>(resultData);

	return std::static_pointer_cast<NodeData>(_result);
}
