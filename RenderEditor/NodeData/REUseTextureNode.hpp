#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class REUseTextureNode : public REOpenGLNode
{
public:
	virtual ~REUseTextureNode() {}

	REUseTextureNode() :REOpenGLNode() { }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REUseTextureNode") }; }

	void setTexture(const QString& tex) { _texture = tex; }

	void setTextureIndex(int index) { _index = index; }

	virtual void execute()
	{
		_func->glActiveTexture(GL_TEXTURE0 + _index);
		_func->glBindTexture(GL_TEXTURE_2D, _context->getTexture(_texture.toStdString()));
	}

	virtual void clear()
	{
	}

private:
	QString _texture;
	//纹理启用下标
	int _index = 0;
};