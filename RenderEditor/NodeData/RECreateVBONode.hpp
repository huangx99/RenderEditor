#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class RECreateVBONode : public REOpenGLNode
{
public:
	virtual ~RECreateVBONode() {}

	RECreateVBONode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REOpenGLNode") }; }

	void setVertices(const std::vector<float>& data) { _vertices = data; }

	virtual void execute()
	{
		if (_context->getVBO(_ID))
		{
			return;
		}

		if (_vertices.size() == 0)
		{
			_vertices =
			{
				-0.5f, -0.5f, 0.0f, // left  
				 0.5f, -0.5f, 0.0f, // right 
				 0.0f,  0.5f, 0.0f  // top   
			};
		}
		GLuint VBO;
		_func->glGenBuffers(1, &VBO);
		_func->glBindBuffer(GL_ARRAY_BUFFER, VBO);


		_func->glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(float), _vertices.data(), GL_STATIC_DRAW);

		_context->addVBO(_ID, VBO);
	}

	virtual void clear() {}

private:
	std::vector<float> _vertices;
};