#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include "REOpenGLControlWidget.h"

class REOpenGLNode;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REOpenGLDisplayModel : public NodeDelegateModel
{

public:
	REOpenGLDisplayModel();

	virtual ~REOpenGLDisplayModel() = default;
	QString caption() const override { return QString::fromUtf8("OpenGL窗口"); }

	QString name() const override { return QString::fromUtf8("OpenGL窗口"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> nodeData, PortIndex const portIndex) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return _display; }

protected:
	std::shared_ptr<REOpenGLNode> _data;

	REOpenGLControlWidget *_display;
};
