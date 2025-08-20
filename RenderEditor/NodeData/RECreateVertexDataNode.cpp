#include "RECreateVertexDataNode.h"

void RECreateVertexDataNode::execute()

{
	if (_context->getVBO(_ID) && _context->getVAO(_ID))
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
	_func->glGenVertexArrays(1, &_VAO);
	_func->glBindVertexArray(_VAO);

	_func->glEnableVertexAttribArray(0);

	
	_func->glGenBuffers(1, &_VBO);
	_func->glBindBuffer(GL_ARRAY_BUFFER, _VBO);


	_func->glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(float), _vertices.data(), GL_STATIC_DRAW);

	_context->addVBO(_ID, _VBO);
	_context->addVAO(_ID, _VAO);
}

void RECreateVertexDataNode::clear()
{
	if (_context && _func)
	{
		_context->updateVBO(_ID, 0);
		_context->updateVAO(_ID, 0);

		_func->glDeleteBuffers(1, &_VBO);
		_func->glDeleteVertexArrays(1, &_VAO);
	}
}
