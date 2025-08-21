#include "REOpenGLRenderService.h"
#include <iostream>

REOpenGLWidget * REOpenGLRenderService::getOpenGLWidget() const
{
	return _widget;
}

REOpenGLRenderService::REOpenGLRenderService()
{
	_widget = new REOpenGLWidget;
	_widget->update();
}

REOpenGLRenderService::~REOpenGLRenderService() 
{

}

REOpenGLRenderService& REOpenGLRenderService::getInstance()
{
	static REOpenGLRenderService instance;
	return instance;
}