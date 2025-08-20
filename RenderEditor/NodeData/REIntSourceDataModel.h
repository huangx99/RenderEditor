#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include <QSpinBox>

class REIntData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REIntSourceDataModel : public NodeDelegateModel
{

public:
	REIntSourceDataModel();

	virtual ~REIntSourceDataModel() = default;
	QString caption() const override { return QString::fromUtf8("int"); }

	QString name() const override { return QString::fromUtf8("int"); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override {}

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return _editor; }

private slots:
	void onValueChanged(int value);

protected:

	std::shared_ptr<REIntData> _result;

	QSpinBox *_editor;
};
