#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include <QTimer>

class REFloatData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RETimerModel : public NodeDelegateModel
{

public:
	RETimerModel();

	virtual ~RETimerModel() = default;
	QString caption() const override { return QString::fromUtf8("Timer"); }

	QString name() const override { return QString::fromUtf8("Timer"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

private slots:
	void onTimerOut();

protected:

	std::shared_ptr<REFloatData> _result;
	float _count = 0.0;
	QTimer* _timer;

	float _speed = 1.0;
};
