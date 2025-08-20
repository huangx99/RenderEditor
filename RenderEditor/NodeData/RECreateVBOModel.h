#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>


class RECreateVBONode;
class REFloatArrayData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RECreateVBOModel : public NodeDelegateModel
{

public:
	RECreateVBOModel();

	virtual ~RECreateVBOModel() = default;
	QString caption() const override { return QString::fromUtf8("createVBO"); }

	QString name() const override { return QString::fromUtf8("createVBO"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }


protected:

	std::shared_ptr<RECreateVBONode> _result;
	std::shared_ptr<RECreateVBONode> _node;

};
