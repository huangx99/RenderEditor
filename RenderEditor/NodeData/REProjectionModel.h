#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QJsonObject>
#include <QObject>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "REMat4Data.hpp"
#include "REFloatData.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REProjectionModel : public NodeDelegateModel
{

public:
	REProjectionModel();

	virtual ~REProjectionModel() = default;
	QString caption() const override { return QString::fromUtf8("projection"); }

	QString name() const override { return QString::fromUtf8("projection"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

protected:

	std::shared_ptr<REMat4Data> _result;

	//视场
	std::shared_ptr<REFloatData> _zoom;

	//屏幕宽
	std::shared_ptr<REFloatData> _scrWidth;

	//屏幕长
	std::shared_ptr<REFloatData> _scrHeight;

	//近平面
	std::shared_ptr<REFloatData> _near;

	//远平面
	std::shared_ptr<REFloatData> _far;
};
