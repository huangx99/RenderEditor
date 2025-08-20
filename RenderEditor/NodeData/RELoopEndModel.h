#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REOpenGLModel.hpp"

class REIntData;
class RELoopEndNode;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RELoopEndModel : public REOpenGLModel
{

public:
	RELoopEndModel();

	virtual ~RELoopEndModel() = default;
	QString caption() const override { return QString::fromUtf8("loopEnd"); }

	QString name() const override { return QString::fromUtf8("loopEnd"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }


protected:

	std::shared_ptr<REIntData> _count;

	std::shared_ptr<RELoopEndNode> _loopEndNode;

};
