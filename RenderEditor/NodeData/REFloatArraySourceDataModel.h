#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include <QTextEdit>

class REFloatArrayData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REFloatArraySourceDataModel : public NodeDelegateModel
{

public:
	REFloatArraySourceDataModel();

	virtual ~REFloatArraySourceDataModel() = default;
	QString caption() const override { return QString::fromUtf8("floatArray"); }

	QString name() const override { return QString::fromUtf8("floatArray"); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override {}

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return _editor; }

private slots:
	void onTextChanged();

protected:

	std::shared_ptr<REFloatArrayData> _result;

	QTextEdit *_editor;
};
