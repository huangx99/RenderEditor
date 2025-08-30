#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "RESetUniformValueNode.hpp"
#include "REFloatData.hpp"
#include "REStringData.hpp"
#include "REValueSetTimeEditor.h"
#include "REOpenGLModel.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RESetUniformFloatModel : public REOpenGLModel
{

public:
	RESetUniformFloatModel();

	virtual ~RESetUniformFloatModel() = default;
	QString caption() const override { return QString::fromUtf8("uniform_float"); }

	QString name() const override { return QString::fromUtf8("uniform_float"); }

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

	std::shared_ptr<RESetUniformNode<float>> _setUniformNode = nullptr;

	REValueSetTimeEditor* _editor;

};
