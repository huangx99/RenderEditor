#pragma once
#include "REOpenGLNode.hpp"
#include <vector>

class RECreateTextureNode : public REOpenGLNode
{
public:
	virtual ~RECreateTextureNode() {}

	RECreateTextureNode() :REOpenGLNode() { _nodeType = ONT_Initialize; }

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("RECreateTextureNode") }; }

	void setPixelMap(const QPixmap& pixmap) { _pixmap = pixmap; }

	virtual void execute()
	{
		GLuint textureId;

		_func->glGenTextures(1, &textureId);
		_func->glBindTexture(GL_TEXTURE_2D, textureId);

		// 转 QImage，并转换为 RGBA 格式
		QImage img = _pixmap.toImage().convertToFormat(QImage::Format_RGBA8888);

		// 注意：QImage 是左上角为原点，而 OpenGL 纹理是左下角，所以需要镜像
		img = img.mirrored();

		// 传输到显存
		_func->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
			img.width(), img.height(), 0,
			GL_RGBA, GL_UNSIGNED_BYTE, img.bits());

		_func->glGenerateMipmap(GL_TEXTURE_2D);

		// 设置纹理参数
		_func->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		_func->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		_func->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		_func->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		_func->glBindTexture(GL_TEXTURE_2D, 0);

		_context->addTexture(_ID, textureId);
	}

	virtual void clear()
	{
		if (_context)
		{
			_context->removeTexture(_ID);
		}
	}

private:
	QPixmap _pixmap;
};