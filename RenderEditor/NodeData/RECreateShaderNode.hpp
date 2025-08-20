#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

struct RECreateShaderParam
{
	//顶点着色器代码位置
	QString vertexShaderPath;
	//片段着色器代码位置
	QString fragmentShaderPath;

	//顶点着色器内容
	QString vertexShader;
	//片段色器内容
	QString fragmentShader;
};

class RECreateShaderNode : public REOpenGLNode
{
public:
	virtual ~RECreateShaderNode() {}

	RECreateShaderNode() :REOpenGLNode()
	{ 
		_nodeType = ONT_Initialize;
		_program = std::make_shared<QOpenGLShaderProgram>();
	}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("RECreateShaderNode") }; }

	bool setParam(const RECreateShaderParam& param)
	{
		if (_param.fragmentShaderPath != param.fragmentShaderPath || _param.vertexShaderPath != param.vertexShaderPath)
		{
			_param = param;
			return true;
		}

		return false;
	}

	virtual void execute()
	{
		if (_program->isLinked())
		{
			_program->release();
		}

		_program->removeAllShaders();

		if (_param.vertexShader.size())
		{
			bool result = _program->addShaderFromSourceCode(QOpenGLShader::Vertex, _param.vertexShader);
		}
		else if (_param.vertexShaderPath.size())
		{
			bool result = _program->addShaderFromSourceFile(QOpenGLShader::Vertex, _param.vertexShaderPath);
		}

		if (_param.fragmentShader.size())
		{
			bool result = _program->addShaderFromSourceCode(QOpenGLShader::Fragment, _param.fragmentShader);
		}
		else if (_param.fragmentShaderPath.size())
		{
			bool result = _program->addShaderFromSourceFile(QOpenGLShader::Fragment, _param.fragmentShaderPath);
		}

		bool result = _program->link();

		if(_context->getShader(_ID) == nullptr)
			_context->addShader(_ID, _program);
	}

	virtual void clear()
	{
		if (_context)
		{
			_context->removeShader(_ID);
		}
	}

private:
	RECreateShaderParam _param;

	std::shared_ptr<QOpenGLShaderProgram> _program;
};