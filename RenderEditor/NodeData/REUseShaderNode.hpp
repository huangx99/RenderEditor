#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class REUseShaderNode : public REOpenGLNode
{
public:
	virtual ~REUseShaderNode() {}

	REUseShaderNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REUseShaderNode") }; }

	void setShader(const QString& shader) { _shader = shader; }

	virtual void execute()
	{
		if (_context)
		{
			auto shaderProgram = _context->getShader(_shader.toStdString());
			if (shaderProgram != nullptr)
			{
				shaderProgram->bind();
			}
		}
	}

	virtual void clear(){}

private:
	QString _shader;
};