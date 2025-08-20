#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class RECreateVertexDataNode : public REOpenGLNode
{
public:
	virtual ~RECreateVertexDataNode() {}

	RECreateVertexDataNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("RECreateVertexDataNode") }; }

	void setVertices(const std::vector<float>& data) { _vertices = data; }

	virtual void execute();

	virtual void clear();

private:
	std::vector<float> _vertices;

	GLuint _VBO;
	GLuint _VAO;

};