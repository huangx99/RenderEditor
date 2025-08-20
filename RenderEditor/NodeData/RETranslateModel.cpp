#include "RETranslateModel.h"

RETranslateModel::RETranslateModel()
{
	_translate = std::make_shared<REVec3Data>(glm::vec3(0.));
	_mat = std::make_shared<REMat4Data>(glm::mat4(1.0));
}

unsigned int RETranslateModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 2;
	else
		result = 1;

	return result;
}

NodeDataType RETranslateModel::dataType(PortType type, PortIndex index) const
{
	if (type == PortType::In)
	{
		if (index == 0)
		{
			return  NodeDataType{ REMat4Data().type().id, QString::fromUtf8("mat") };
		}
		else if (index == 1)
		{
			return NodeDataType{ REVec3Data().type().id, QString::fromUtf8("translate") };
		}
	}
	else if (type == PortType::Out)
	{
		if (index == 0)
		{
			return  NodeDataType{ REMat4Data().type().id, QString::fromUtf8("translate mat") };
		}
	}
	return REMat4Data().type();
}

void RETranslateModel::setInData(std::shared_ptr<NodeData> data, PortIndex const index)
{
	if (!data) {
		Q_EMIT dataInvalidated(0);

		if (index == 0)
		{
			_mat->setValue(glm::mat4(1.0));
		}
		else if (index == 1)
		{
			_translate->setValue(glm::vec3(0.));
		}

		return;
	}

	if (index == 0)
	{
		_mat = std::dynamic_pointer_cast<REMat4Data>(data);
	}
	else if (index == 1)
	{
		_translate = std::dynamic_pointer_cast<REVec3Data>(data);
	}

	emit dataUpdated(0);
}

std::shared_ptr<NodeData> RETranslateModel::outData(PortIndex)
{
	glm::vec3 translate = _translate->value();
	glm::mat4 mat = _mat->value();

	mat = glm::translate(mat, translate);

	//_mat->setValue(mat);

	_result = std::make_shared<REMat4Data>(mat);

	return std::static_pointer_cast<NodeData>(_result);
}
