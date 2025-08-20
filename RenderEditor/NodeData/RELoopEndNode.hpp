#pragma once
#include "REOpenGLNode.hpp"
#include <vector>


class RELoopEndNode : public REOpenGLNode
{
public:
	virtual ~RELoopEndNode() {}

	RELoopEndNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("RELoopEndNode") }; }

	void setLoopNode(std::shared_ptr<REOpenGLNode> node) { _loopNode = node; }

	void setLoopCount(int count) 
	{ 
		_loopCount = count; 
		_loopCountTemp = _loopCount;
	}

	virtual std::shared_ptr<REOpenGLNode> getNext () override
	{
		if (_loopCount > 0 && _loopNode)
		{
			return _loopNode;
		}
		else
		{
			_loopCount = _loopCountTemp;
			return REOpenGLNode::getNext();
		}
	}

	virtual void execute()
	{
		_loopCount--;
	}

	virtual void clear()
	{

	}

private:
	int _loopCount = 0;
	int _loopCountTemp = 0;
	std::shared_ptr<REOpenGLNode> _loopNode = nullptr;
};