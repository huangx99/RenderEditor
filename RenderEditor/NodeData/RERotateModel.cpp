#include "RERotateModel.h"

RERotateModel::RERotateModel()
{
	_axis = std::make_shared<REVec3Data>(glm::vec3(0.f));
	_angle = std::make_shared<REFloatData>(0.);
	_mat = std::make_shared<REMat4Data>(glm::mat4(1.0));
}

unsigned int RERotateModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 3;
	else
		result = 1;

	return result;
}

NodeDataType RERotateModel::dataType(PortType type, PortIndex index) const
{
	if (type == PortType::In)
	{
		if (index == 0)
		{
			return NodeDataType{ REMat4Data().type().id, QString::fromUtf8("mat")};
		}
		else if (index == 1)
		{
			return NodeDataType{ REVec3Data().type().id, QString::fromUtf8("axis") };
		}
		else if (index == 2)
		{
			return NodeDataType{ REFloatData().type().id, QString::fromUtf8("angle") };
		}
	}
	else if (type == PortType::Out)
	{
		if (index == 0)
		{
			return NodeDataType{ REMat4Data().type().id, QString::fromUtf8("rotate mat") };
		}
	}
	return REMat4Data().type();
}

void RERotateModel::setInData(std::shared_ptr<NodeData> data, PortIndex const index)
{
	if (!data) {
		Q_EMIT dataInvalidated(0);

		if (index == 0)
		{
			_mat->setValue(glm::mat4(1.0));
		}
		else if (index == 1)
		{
			_axis->setValue(glm::vec3(0.));
		}
		else if (index == 2)
		{
			_angle->setValue(0.);
		}

		return;
	}


	if (index == 0)
	{
		_mat = std::dynamic_pointer_cast<REMat4Data>(data);
	}
	else if (index == 1)
	{
		_axis = std::dynamic_pointer_cast<REVec3Data>(data);
	}
	else if (index == 2)
	{
		_angle = std::dynamic_pointer_cast<REFloatData>(data);
	}

	emit dataUpdated(0);
}

std::shared_ptr<NodeData> RERotateModel::outData(PortIndex)
{
	glm::vec3 rotate = _axis->value();
	glm::mat4 mat = _mat->value();
	mat = glm::rotate(mat, glm::radians(_angle->value()), rotate);

	//_mat->setValue(mat);

	_result = std::make_shared<REMat4Data>(mat);

	return std::static_pointer_cast<NodeData>(_result);
}
