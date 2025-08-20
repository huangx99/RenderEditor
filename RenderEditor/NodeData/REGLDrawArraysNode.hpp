#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

struct REDrawArraysParam
{
	//绘制模式
	unsigned int mode = GL_TRIANGLES;
	//顶点起始位
	int startIndex = 0;
	//顶点数量
	int pointCount = 3;
};

class REGLDrawArraysNode : public REOpenGLNode
{
public:
	virtual ~REGLDrawArraysNode() {}

	REGLDrawArraysNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REOpenGLNode") }; }

	void setParam(const REDrawArraysParam& param) { _param = param; }

	void setVAO(const std::string& VAO) { _VAO = VAO; }


	virtual void execute()
	{
		int vao = _context->getVAO(_VAO);
		if (vao)
		{
			_func->glBindVertexArray(vao);
			_func->glDrawArrays(_param.mode, _param.startIndex, _param.pointCount);
		}

	}

	virtual void clear()
	{

	}

private:
	REDrawArraysParam _param;
	std::string _VAO;

};