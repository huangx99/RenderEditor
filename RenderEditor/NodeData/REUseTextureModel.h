#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REOpenGLModel.hpp"

class REUseTextureNode;
class REStringData;
class REPixmapData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REUseTextureModel : public REOpenGLModel
{

public:
	REUseTextureModel();

	virtual ~REUseTextureModel() = default;
	QString caption() const override { return QString::fromUtf8("useTexture"); }

	QString name() const override { return QString::fromUtf8("useTexture"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override;


public slots:
	void onDataUpdate();

protected:

	std::shared_ptr<REUseTextureNode> _useTextureNode;
};
