#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>


class RECreateVAONode;
class REStringData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RECreateVAOModel : public NodeDelegateModel
{

public:
	RECreateVAOModel();

	virtual ~RECreateVAOModel() = default;
	QString caption() const override { return QString::fromUtf8("createVAO"); }

	QString name() const override { return QString::fromUtf8("createVAO"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }


protected:

	std::shared_ptr<RECreateVAONode> _result;
	std::shared_ptr<RECreateVAONode> _node;

	std::shared_ptr<REStringData> _vaoID;

};
