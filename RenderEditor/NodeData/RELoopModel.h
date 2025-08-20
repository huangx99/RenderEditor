#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REOpenGLModel.hpp"

class REIntData;
class REFloatData;
class RELoopNode;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RELoopModel : public REOpenGLModel
{

public:
	RELoopModel();

	virtual ~RELoopModel() = default;
	QString caption() const override { return QString::fromUtf8("loop"); }

	QString name() const override { return QString::fromUtf8("loop"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

	void updateCount();
protected:

	std::shared_ptr<REIntData> _count;
	std::shared_ptr<REFloatData> _residualCount;

	std::shared_ptr<RELoopNode> _loopNode;

};
