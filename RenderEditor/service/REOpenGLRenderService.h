#pragma once
#include "..\NodeData\REOpenGLWidget.h"
class REOpenGLRenderService 
{
public:
	static REOpenGLRenderService& getInstance();


	REOpenGLRenderService(const REOpenGLRenderService&) = delete;
	REOpenGLRenderService& operator=(const REOpenGLRenderService&) = delete;

	REOpenGLWidget* getOpenGLWidget() const;

private:
	REOpenGLRenderService();
	~REOpenGLRenderService();

	REOpenGLWidget* _widget = nullptr;
};