#include "REOpenGLControlWidget.h"
#include <QWindow>
#include <QSurface>
REOpenGLControlWidget::REOpenGLControlWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::REOpenGLControlWidgetClass())
{
	ui->setupUi(this);
	this->resize(800, 600);
}

REOpenGLControlWidget::~REOpenGLControlWidget()
{
	delete ui;
}

REOpenGLWidget * REOpenGLControlWidget::getOpenGLWidget() const
{
	return ui->openGLWidget;
}

void REOpenGLControlWidget::showOpenGLWidget()
{
	return;
	// 解除父子关系，变成顶层窗口
	ui->openGLWidget->setParent(nullptr);

	// 设置成全屏
	ui->openGLWidget->showFullScreen();
}
