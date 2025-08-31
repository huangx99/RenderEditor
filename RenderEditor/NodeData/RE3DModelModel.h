#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REOpenGLModel.hpp"


class RE3DModelNode;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RE3DModelModel : public REOpenGLModel
{

public:
	RE3DModelModel();

	virtual ~RE3DModelModel() = default;
	QString caption() const override { return QString::fromUtf8("3DModel"); }

	QString name() const override { return QString::fromUtf8("3DModel"); }


public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

protected:

	std::shared_ptr<RE3DModelNode> _3DModelNode;
};
