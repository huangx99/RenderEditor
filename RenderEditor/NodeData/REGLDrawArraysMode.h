#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REDrawArraysEditor.h"
#include "REOpenGLModel.hpp"


class REGLDrawArraysNode;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REGLDrawArraysMode : public REOpenGLModel
{

public:
	REGLDrawArraysMode();

	virtual ~REGLDrawArraysMode() = default;
	QString caption() const override { return QString::fromUtf8("glDrawArrays"); }

	QString name() const override { return QString::fromUtf8("glDrawArrays"); }

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

	REDrawArraysEditor* _editor;

	std::shared_ptr<REGLDrawArraysNode> _drawArrayNode = nullptr;
};
