#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include "REOpenGLModel.hpp"


class REGLClearColorNode;
class REVec3Data;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REGLClearColorModel : public REOpenGLModel
{

public:
	REGLClearColorModel();

	virtual ~REGLClearColorModel() = default;
	QString caption() const override { return QString::fromUtf8("glClearColor"); }

	QString name() const override { return QString::fromUtf8("glClearColor"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

};
