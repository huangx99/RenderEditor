#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include "REVec3Editor.h"

class REVec3Data;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REVec3SourceDataModel : public NodeDelegateModel
{

public:
	REVec3SourceDataModel();

	virtual ~REVec3SourceDataModel() = default;
	QString caption() const override { return QString::fromUtf8("vec3"); }

	QString name() const override { return QString::fromUtf8("vec3"); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return _editor; }

private slots:
	void onValueEdit(const glm::vec3 &value);

protected:

	std::shared_ptr<REVec3Data> _result;

	REVec3Editor *_editor;
};
