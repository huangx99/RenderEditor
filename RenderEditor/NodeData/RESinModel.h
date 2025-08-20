#pragma once
#include <QtNodes/NodeDelegateModel>

#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

class REFloatData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RESinModel : public NodeDelegateModel
{

public:
	RESinModel();

	virtual ~RESinModel() = default;
	QString caption() const override { return QString::fromUtf8("sin"); }

	QString name() const override { return QString::fromUtf8("sin"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

protected:
	std::shared_ptr<REFloatData> _result;
};
