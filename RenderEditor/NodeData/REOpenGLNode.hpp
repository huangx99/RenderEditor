#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QOpenGLFunctions_3_3_Core>
#include "REOpenGLContext.h"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

#include <QString>
#include <QRandomGenerator>

enum REOpenGLNodeType
{
	ONT_Initialize, // 初始化阶段（一次性执行）
	ONT_Update      // 更新阶段（每帧/多次执行）
};

//双向n叉树实现for循环与if else


class REOpenGLNode : public NodeData
{
public:
	REOpenGLNode()
	{
		_ID = generateRandomString().toStdString();
	}

	virtual ~REOpenGLNode()
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("REOpenGLNode"), QString::fromUtf8("REOpenGLNode") }; }

	virtual void execute() {}
	virtual void clear() {}

	void setOpenGLFunc(QOpenGLFunctions_3_3_Core* func) 
	{
		_func = func;
	}

	//设置上一节点，并重构当前节点
	void setContext(std::shared_ptr<REOpenGLContext> context)
	{
		_context = context;
	}

	//设置上一节点，并重构当前节点
	void setNode(std::shared_ptr<REOpenGLNode> node) 
	{ 
		//清理
		_nodes.clear();

		//重新生成执行顺序
		auto nodes = node->getNodes();
		_nodes.insert(_nodes.begin(), nodes.begin(), nodes.end());
		_nodes.push_back(node); 
	}

	virtual void setNext(std::shared_ptr<REOpenGLNode> node)
	{
		_next = node;
	}

	virtual std::shared_ptr<REOpenGLNode> getNext()
	{
		return _next;
	}

	virtual std::shared_ptr<REOpenGLNode> getPre()
	{
		return _pre;
	}

	virtual void setPre(std::shared_ptr<REOpenGLNode> node)
	{
		_pre = node;
	}

	void setNodeType(REOpenGLNodeType type) { _nodeType = type; }
	REOpenGLNodeType getNodeType() const { return _nodeType; }

	std::vector<std::shared_ptr<REOpenGLNode>> getNodes() { return _nodes; }

	std::string getID() const { return _ID; };

	void setBacktrackingNode(std::shared_ptr<REOpenGLNode> node) { _backtrackingNode = node; }

	std::shared_ptr<REOpenGLNode> getBacktrackingNode() const { return _backtrackingNode; }

private:
	QString generateRandomString(int length = 8, const QString& charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")
	{
		QString result;
		result.reserve(length);

		int charsetSize = charset.size();
		for (int i = 0; i < length; ++i) {
			int index = QRandomGenerator::global()->bounded(charsetSize);
			result.append(charset.at(index));
		}

		return result;
	}

protected:
	std::string _ID;

	std::vector<std::shared_ptr<REOpenGLNode>> _nodes;

	//n叉树前向
	std::shared_ptr<REOpenGLNode> _next = nullptr;
	//n叉树逆向
	std::shared_ptr<REOpenGLNode> _pre = nullptr;

	//回溯节点
	std::shared_ptr<REOpenGLNode> _backtrackingNode = nullptr;
	
	
	std::shared_ptr<REOpenGLContext> _context;
	

	//不能在openglWidget使用fun，否则可能存在多个上下文，所以把func传入使用
	QOpenGLFunctions_3_3_Core* _func = nullptr;

	REOpenGLNodeType _nodeType = ONT_Update;
};
