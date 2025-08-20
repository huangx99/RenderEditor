#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>
#include "REOpenGLModel.hpp"


class RECreateVertexDataNode;
class REFloatArrayData;
class REStringData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RECreateVertexModel : public REOpenGLModel
{

public:
	RECreateVertexModel();

	virtual ~RECreateVertexModel() = default;
	QString caption() const override { return QString::fromUtf8("createVertex"); }

	QString name() const override { return QString::fromUtf8("createVertex"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }


protected:

	std::shared_ptr<REFloatArrayData> _data;
	std::shared_ptr<REStringData> _VAOID;

	std::shared_ptr<RECreateVertexDataNode> _createVertexDataNode;

};
