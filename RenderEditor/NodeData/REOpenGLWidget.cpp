#include "REOpenGLWidget.h"
#include <QOpenGLShaderProgram>
#include <QDateTime>

REOpenGLWidget::REOpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	_context = std::make_shared<REOpenGLContext>();

	//setFocusPolicy(Qt::StrongFocus); // 允许键盘事件
	//setMouseTracking(true);          // 鼠标追踪
	//setCursor(Qt::BlankCursor);      // 隐藏鼠标光标
}

REOpenGLWidget::~REOpenGLWidget()
{
	
}

void REOpenGLWidget::setOpenGLNode(std::shared_ptr<REOpenGLNode> node)
{
	_root = node;

	update();
}

//我遇到一个问题，当我清理所有VAO、材质再重新创建的时候，弹出的窗口就黑屏了
//嗯，我大概知道你的情况了。
//你现在是把 `ui- > openGLWidget` 直接弹出来做全屏，这样确实**避免了共享上下文和 VAO 丢失的问题**，但是你又会在运行过程中**手动清理所有 VAO / 材质并重新创建 * *，结果就黑屏了。
//
//这个黑屏的原因其实很简单：
//`QOpenGLWidget` 在 Qt 里有一个隐藏的 **FBO** 作为离屏缓冲，每次 `paintGL()` 都先渲染到这个 FBO，再画到窗口上。
//如果你在弹出 / 切回的过程中，销毁了资源，然后又没等到合适的时机重新创建，就会出现：
//
//* `paintGL()` 还没准备好数据 → 直接画背景 → 黑屏。
//
//-- -
//
//## 核心原因
//
//1. 你销毁资源的时机可能**不在 GL 上下文当前时**（比如在其他线程或非 `makeCurrent()` 状态）。
//2. 重新创建 VAO / 材质的代码可能没有在 * *`initializeGL()` 或 `paintGL()`** 里执行，而是在别的地方调用。
//3. QOpenGLWidget 全屏 / 恢复时， * *可能会触发一次 `resizeGL()` 和重建 FBO**，这会让你还没创建好的资源无法显示。
//
//-- -
//
//## 解决方案
//
//### 方案一：销毁 / 创建资源都放到 GL 上下文当前时
//
//```cpp
//void REOpenGLWidget::recreateResources()
//{
//	makeCurrent(); // 确保 GL 上下文已绑定
//
//	// 清理旧资源
//	glDeleteVertexArrays(...);
//	glDeleteBuffers(...);
//	glDeleteTextures(...);
//
//	// 创建新资源
//	initVAO();
//	initTextures();
//
//	doneCurrent();
//}
//```
//
//-- -
//
//### 方案二：用标志位推迟创建
//
//如果资源创建很耗时，可以设置一个标志，在下一帧的 `paintGL()` 再创建：
//
//```cpp
//bool needRecreate = false;
//
//void REOpenGLWidget::requestRecreate()
//{
//	needRecreate = true;
//	update(); // 触发 paintGL
//}
//
//void REOpenGLWidget::paintGL()
//{
//	if (needRecreate) {
//		recreateResources();
//		needRecreate = false;
//	}
//
//	drawScene();
//}
//```
//
//这样可以保证资源的创建和使用都在同一个 GL 上下文中完成。
//
//-- -
//
//### 方案三：全屏和窗口模式切换时避免重建上下文
//
//* `QOpenGLWidget` 在不同平台有时会在 `showFullScreen()`/`showNormal()` 时重建 FBO，但不会重建 OpenGLContext（除非你手动换父窗口类型）。
//* 如果你是频繁全屏切换，可以在切换前**先准备好资源**，或者在切换后立即 `update()` 触发一次绘制。
//
//-- -
//
//总结：
//你这种黑屏是因为资源清理 / 创建不在正确的 OpenGL 上下文中完成，或者在全屏切换时 FBO / VAO 状态没同步。解决方法就是**在 makeCurrent() 状态下重新创建资源**，最好放在 `paintGL()` 或延迟一帧执行。


void REOpenGLWidget::initializeNode()
{
	//使用makeCurrent原因见上面对话
	makeCurrent();
	clearContext();
	glEnable(GL_DEPTH_TEST);

	std::shared_ptr<REOpenGLNode> node = _root;
	while (node)
	{
		node->setOpenGLFunc(this);
		node->setContext(_context);
		node->execute();

		node = node->getNext();
	}

	doneCurrent();
}

void REOpenGLWidget::clearContext()
{
	//glDeleteBuffers(...)       // 删除 VBO / EBO
	//glDeleteVertexArrays(...)  // 删除 VAO
	//glDeleteTextures(...)      // 删除纹理
	//glDeleteProgram(...)       // 删除着色器程序
	//glDeleteFramebuffers(...)  // 删除 FBO
	//glDeleteRenderbuffers(...) // 删除 RBO

	this->glBindVertexArray(0);
	this->glBindBuffer(GL_ARRAY_BUFFER, 0);
	this->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// 解绑纹理
	this->glBindTexture(GL_TEXTURE_2D, 0);

	// 停用 shader program
	this->glUseProgram(0);

	// 关闭启用的功能
	//this->glDisable(GL_DEPTH_TEST);
	//this->glDisable(GL_BLEND);
	//this->glDisable(GL_CULL_FACE);

	for (auto VBO : _context->getVBOs())
	{
		this->glDeleteBuffers(1, &VBO.second);
	}

	for (auto EBO : _context->getEBOs())
	{
		this->glDeleteBuffers(1, &EBO.second);
	}

	for (auto VAO : _context->getVAOs())
	{
		this->glDeleteVertexArrays(1, &VAO.second);
	}

	for (auto texture : _context->getTextures())
	{
		this->glDeleteTextures(1, &texture.second);
	}

	for (auto shader : _context->getShaders())
	{
		shader.second->removeAllShaders();
	}

	_context->clear();
}

void REOpenGLWidget::clearNode()
{
	_nodes.clear();
	_root = nullptr;
}


void REOpenGLWidget::initializeGL()
{
	initializeOpenGLFunctions();

	glClearColor(0., 0., 0., 0.);
	glEnable(GL_DEPTH_TEST);

	//渲染帧数
	_lastTime = QDateTime::currentMSecsSinceEpoch();
	QCursor::setPos(mapToGlobal(QPoint(width() / 2, height() / 2)));
}

void REOpenGLWidget::resizeGL(int w, int h)
{
	//处理相机
	_projection.setToIdentity();
	_projection.perspective(45.0f, float(w) / float(h), 0.1f, 100.0f);

	glViewport(0, 0, w, h);
}

void REOpenGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//----相机逻辑----------------------------------------
	qint64 now = QDateTime::currentMSecsSinceEpoch();
	_deltaTime = (now - _lastTime) / 1000.0f;
	_lastTime = now;

	QMatrix4x4 view = camera.getViewMatrix();
	
	//遍历shader
	for (auto shader : _context->getShaders())
	{
		shader.second->bind();
		shader.second->setUniformValue("view", view);
		shader.second->setUniformValue("projection", _projection);
	}

	//----相机逻辑end----------------------------------------
	std::shared_ptr<REOpenGLNode> node = _root;
	while (node)
	{
		if (node->getNodeType() == ONT_Initialize)
		{
			node = node->getNext();
			continue;
		}
			
		node->setOpenGLFunc(this);
		node->setContext(_context);
		node->execute();

		node = node->getNext();
	}

	//this->glBindVertexArray(1);
	
	//this->glDrawArrays(GL_TRIANGLES, 0, 3);

	this->glBindVertexArray(0);

	update();
}


void REOpenGLWidget::keyPressEvent(QKeyEvent *event) 
{
	camera.processKeyboard(static_cast<Qt::Key>(event->key()), _deltaTime); // 实时帧率
	update();
}

void REOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	// 第一次移动鼠标，初始化 lastX/lastY
	if (firstMouse) {
		lastX = width() / 2;
		lastY = height() / 2;
		firstMouse = false;

		// 将鼠标放到窗口中心
		QCursor::setPos(mapToGlobal(QPoint(lastX, lastY)));
		return;
	}

	// 计算偏移量
	float xoffset = event->x() - lastX;
	float yoffset = lastY - event->y(); // y轴反向

	// 更新 lastX/lastY 为窗口中心
	lastX = width() / 2;
	lastY = height() / 2;

	// 处理鼠标移动
	camera.processMouseMovement(xoffset, yoffset);

	// 每次移动后把光标重置到窗口中心
	QCursor::setPos(mapToGlobal(QPoint(width() / 2, height() / 2)));

	// 刷新绘制
	update();
}
