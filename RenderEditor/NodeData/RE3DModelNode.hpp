#pragma once
#include "REOpenGLNode.hpp"
#include <vector>
#include "Model.h"

struct RE3DModelParam
{
	QString modelPath;
};

class RE3DModelNode : public REOpenGLNode
{
public:
	virtual ~RE3DModelNode() {}

	RE3DModelNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("RE3DModelNode") }; }

	void setParam(const RE3DModelParam& param) {
		_param = param; 
		if (_model)
		{
			_model->clear();
			delete _model;
			_model = nullptr;
		}
	}

	void setShader(const QString& shader)
	{
		_shader = shader;
	}

	virtual void execute()
	{
		if (!_model)
		{
			_model = new Model(_param.modelPath.toStdString(), _func);
		}
		std::shared_ptr<QOpenGLShaderProgram> shader = _context->getShader(_shader.toStdString());
		_model->Draw(shader);
	}

	virtual void clear()
	{
		
	}

private:
	RE3DModelParam _param;
	QString _shader;
	Model* _model = nullptr;
};