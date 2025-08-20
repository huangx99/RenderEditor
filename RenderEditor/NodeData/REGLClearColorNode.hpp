#pragma once
#include "REOpenGLNode.hpp"

class REGLClearColorNode : public REOpenGLNode
{
public:
	virtual ~REGLClearColorNode() {}

	REGLClearColorNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REOpenGLNode") }; }

	void setColor(const glm::vec4& color) { _clearColor = color; }

	virtual void execute()
	{
		_func->glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);
	}

	virtual void clear()
	{
		_func->glClearColor(0., 0., 0., 0.);
	}

private:
	glm::vec4 _clearColor = glm::vec4(1., 0., 0., 1.);
};