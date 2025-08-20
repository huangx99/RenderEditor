#pragma once

#include <QWidget>
#include "ui_REOpenGLControlWidget.h"
#include "REOpenGLWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class REOpenGLControlWidgetClass; };
QT_END_NAMESPACE

class REOpenGLControlWidget : public QWidget
{
	Q_OBJECT

public:
	REOpenGLControlWidget(QWidget *parent = nullptr);
	~REOpenGLControlWidget();

	REOpenGLWidget* getOpenGLWidget() const;

	void showOpenGLWidget();

private:
	Ui::REOpenGLControlWidgetClass *ui;

	REOpenGLWidget* _openGLWidget = nullptr;

	QOpenGLWidget * _popGLWidget = nullptr;
};
