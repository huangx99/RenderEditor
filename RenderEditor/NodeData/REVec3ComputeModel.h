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

class REVec3ComputeModel : public NodeDelegateModel
{

public:
	REVec3ComputeModel();

	virtual ~REVec3ComputeModel() = default;
	QString caption() const override { return QString::fromUtf8("compute"); }

	QString name() const override { return QString::fromUtf8("compute"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }


protected:
	virtual void compute() = 0;

protected:
	std::shared_ptr<REVec3Data> _vec3a = nullptr;
	std::shared_ptr<REVec3Data> _vec3b = nullptr;

	std::shared_ptr<REVec3Data> _result;
};
