#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QJsonObject>
#include <QObject>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "REMat4Data.hpp"
#include "REVec3Data.hpp"
#include "REFloatData.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RERotateModel : public NodeDelegateModel
{

public:
	RERotateModel();

	virtual ~RERotateModel() = default;
	QString caption() const override { return QString::fromUtf8("rotate"); }

	QString name() const override { return QString::fromUtf8("rotate"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

protected:

	std::shared_ptr<REMat4Data> _result;

	std::shared_ptr<REVec3Data> _axis;

	std::shared_ptr<REFloatData> _angle;

	//旋转矩阵
	std::shared_ptr<REMat4Data> _mat;
};
