#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REVAOAttribEditor.h"
#include "REOpenGLModel.hpp"


class REVAOAttribNode;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REVAOAttribModel : public REOpenGLModel
{

public:
	REVAOAttribModel();

	virtual ~REVAOAttribModel() = default;
	QString caption() const override { return QString::fromUtf8("attribVAO"); }

	QString name() const override { return QString::fromUtf8("attribVAO"); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return _editor; }

private slots:
	void onDataUpdate();
protected:

	std::shared_ptr<REVAOAttribNode> _VAOAttribNode;

	REVAOAttribEditor* _editor;

};
