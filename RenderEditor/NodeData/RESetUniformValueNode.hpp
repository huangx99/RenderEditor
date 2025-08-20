#pragma once
#include "REOpenGLNode.hpp"
#include <QString>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

template<typename T>
struct RESetUniformParam
{
	QString _name;
	T _value;
};

enum REValueSetTimeType
{
	VSTT_once,
	VSTT_update
};

template<typename T>
class RESetUniformNode : public REOpenGLNode
{
public:
	virtual ~RESetUniformNode() {}

	RESetUniformNode() : REOpenGLNode() { _nodeType = ONT_Initialize; }

	NodeDataType type() const override
	{
		return NodeDataType{
			QString::fromUtf8("REOpenGLNode"),
			QString::fromUtf8(typeid(T).name()) // 类型名
		};
	}

	void setShader(const QString& shader) { _shader = shader; }
	void setParam(const RESetUniformParam<T>& param) { _param = param; }
	RESetUniformParam<T> getParam() const { return _param; }

	REValueSetTimeType getTimeType() const { return _type; }
	void setTimeType(REValueSetTimeType type)
	{ 
		_type = type; 
		if (_type == VSTT_once)
		{
			_nodeType = ONT_Initialize;
		}
		else if (_type == VSTT_update)
		{
			_nodeType = ONT_Update;
		}
	}

	virtual void execute()
	{
		if (_context)
		{
			auto shaderProgram = _context->getShader(_shader.toStdString());
			if (shaderProgram != nullptr)
			{
				shaderProgram->setUniformValue(_param._name.toUtf8().constData(), _param._value);
			}
		}
	}

	virtual void clear() {}

private:
	QString _shader;
	RESetUniformParam<T> _param;

	REValueSetTimeType _type = VSTT_once;
};
