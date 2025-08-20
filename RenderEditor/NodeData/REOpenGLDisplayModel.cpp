#include "REOpenGLDisplayModel.h"

#include "REVec3Data.hpp"
#include "REOpenGLNode.hpp"

REOpenGLDisplayModel::REOpenGLDisplayModel()
{
	_display = new REOpenGLControlWidget();
}

unsigned int REOpenGLDisplayModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 1;
	else
		result = 0;

	return result;
}

NodeDataType REOpenGLDisplayModel::dataType(PortType portType, PortIndex port) const
{
	if (port == 0)
	{
		return NodeDataType{ QString::fromUtf8("REOpenGLNode"),   QString::fromUtf8("函数注入") };
	}
	return REVec3Data().type();
}

void REOpenGLDisplayModel::setInData(std::shared_ptr<NodeData> data, PortIndex const port)
{
	_data = std::dynamic_pointer_cast<REOpenGLNode>(data);
	_display->update();
	if (!_data)
	{
		_display->getOpenGLWidget()->clearNode();
		return;
	}

	if (_data) 
	{
		//找到根节点
		while (_data->getPre())
		{
			_data = _data->getPre();
		}
		_display->getOpenGLWidget()->setOpenGLNode(_data);
		_display->getOpenGLWidget()->initializeNode();
		_display->showOpenGLWidget();
		//_display->getOpenGLWidget()->update();
	}
	else
	{

	}
}

std::shared_ptr<NodeData> REOpenGLDisplayModel::outData(PortIndex)
{
	return nullptr;
}
