#pragma once

#include <QtNodes/NodeDelegateModel>

#include "REOpenGLNode.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REOpenGLModel : public NodeDelegateModel
{

public:
	REOpenGLModel()
	{
		_node = std::make_shared<REOpenGLNode>();
		_result = _node;
	}

	virtual ~REOpenGLModel() = default;

public:
	unsigned int nPorts(PortType portType) const override
	{
		return 0;
	}

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override
	{
		if (portType == PortType::In)
		{
			return NodeDataType{ QString("REOpenGLNode"),  QString::fromUtf8("函数注入") };
		}
		else
		{
			return NodeDataType{ QString("REOpenGLNode"),  QString::fromUtf8("函数输出") };
		}
	}

	void setInData(std::shared_ptr<NodeData> node, PortIndex const portIndex) override
	{
		if (!node) {
			//重构n叉树
			if (_node)
			{
				auto pre = _node->getPre();
				if (pre)
				{
					pre->setNext(nullptr);
					_node->setPre(nullptr);
				}
			}
			return;
		}
		if (portIndex == 0)
		{
			auto openGLNode = std::dynamic_pointer_cast<REOpenGLNode>(node);
			_node->setNode(openGLNode);
			//构建双向n叉树
			openGLNode->setNext(_node);
			_node->setPre(openGLNode);
		}
	}

	std::shared_ptr<NodeData> outData(PortIndex port) override
	{
		return std::static_pointer_cast<NodeData>(_result);
	}

	QWidget *embeddedWidget() override { return nullptr; }


protected:

	std::shared_ptr<REOpenGLNode> _result;
	std::shared_ptr<REOpenGLNode> _node;
};
