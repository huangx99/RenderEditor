#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

struct REVAOAttribParam
{
	//着色器下标
	int location = 0;
	//顶点分量
	int count = 3;
	//数据类型
	unsigned int type = GL_FLOAT;
	//启用映射
	bool openMap = GL_FALSE;
	//数据字节数
	int byteSize = 12;//默认3*sizeof(float)
	//地址偏移
	int stride = 0;
};

class REVAOAttribNode : public REOpenGLNode
{
public:
	virtual ~REVAOAttribNode() {}

	REVAOAttribNode() :REOpenGLNode() { _nodeType = ONT_Initialize; }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REVAOAttribNode") }; }

	void setParam(const REVAOAttribParam& param) { _param = param; }

	void setVAO(const std::string& VAO) { _VAO = VAO; }

	virtual void execute()
	{
		_func->glVertexAttribPointer
		(
			_param.location,
			_param.count, 
			_param.type,
			_param.openMap,
			_param.byteSize,
			(void*)_param.stride
		);
		_func->glEnableVertexAttribArray(_param.location);
	}

	virtual void clear()
	{
		if (_context)
		{
			GLuint VAO = _context->getVAO(_VAO);
			_func->glDeleteVertexArrays(1, &VAO);
			_context->updateVAO(_VAO, 0);
		}
	}

private:
	REVAOAttribParam _param;

	std::string _VAO;
};