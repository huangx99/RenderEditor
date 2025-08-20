#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class RELoopModel;

struct RELoopNodeParam
{
	//循环次数
	int count = 0;
};

class RELoopNode : public REOpenGLNode
{
public:
	virtual ~RELoopNode() {}

	RELoopNode() :REOpenGLNode() {  }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("RELoopNode") }; }

	void setParam(const RELoopNodeParam& param) 
	{ 
		_param = param; 
		_loopCountTemp = param.count;
	}

	//剩余的执行次数
	int getResidualCount() { return _loopCountTemp; }

	void setModel(RELoopModel* model);

	virtual void execute();

	virtual void clear()
	{

	}

private:
	RELoopNodeParam _param;

	RELoopModel* _model = nullptr;

	int _loopCountTemp = 0;
};