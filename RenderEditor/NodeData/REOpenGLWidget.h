#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <QKeyEvent>
#include <QMouseEvent>
#include "REOpenGLNode.hpp"
#include "REOpenGLContext.h"
#include "REFPSCamera.h"

class REOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core
{
	Q_OBJECT
public:
	REOpenGLWidget(QWidget *parent = nullptr);
	~REOpenGLWidget();

	void setOpenGLNode(std::shared_ptr<REOpenGLNode> node);

	//处理初始化节点（需在setOpenGLNode后调用）
	void initializeNode();

	void clearContext();

	void clearNode();

protected:
	void initializeGL() override;
	void paintGL() override;
	void keyPressEvent(QKeyEvent * event) override;
	void mouseMoveEvent(QMouseEvent * event) override;
	void resizeGL(int w, int h) override;

private:
	//双向n叉树根节点
	std::shared_ptr<REOpenGLNode> _root;

	std::vector<std::shared_ptr<REOpenGLNode>> _nodes;

	std::shared_ptr<REOpenGLContext> _context;

	
	//-----相机------
	REFPSCamera camera;
	QMatrix4x4 _projection;
	bool firstMouse = true;
	float lastX = 0, lastY = 0;
	qint64 _lastTime;
	//相机移动帧率实时
	float _deltaTime = 0.0f;
	//--------------
};