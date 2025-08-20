#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class RECreateVAONode : public REOpenGLNode
{
public:
	virtual ~RECreateVAONode() {}

	RECreateVAONode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REOpenGLNode") }; }

	//void setVertices(const std::vector<float>& data) { _vertices = data; }

	virtual void execute()
	{
		if (_context->getVAO(_ID))
		{
			return;
		}
		_func->glGenVertexArrays(1, &_VAO);
		_func->glBindVertexArray(_VAO);

		_func->glEnableVertexAttribArray(0);
		_func->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		_func->glBindVertexArray(0);

		_context->addVAO(_ID, _VAO);
	}

	virtual void clear()
	{
		_func->glDeleteVertexArrays(1, &_VAO);
		_context->updateVAO(_ID, 0);
	}
private:
	std::vector<float> _vertices;

	GLuint _VAO;
};