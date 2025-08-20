#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QJsonObject>
#include <QObject>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "REMat4Data.hpp"
#include "REVec3Data.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class REViewModel : public NodeDelegateModel
{

public:
	REViewModel();

	virtual ~REViewModel() = default;
	QString caption() const override { return QString::fromUtf8("view"); }

	QString name() const override { return QString::fromUtf8("view"); }

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override { return nullptr; }

protected:

	std::shared_ptr<REVec3Data> _position;

	std::shared_ptr<REVec3Data> _front;

	std::shared_ptr<REVec3Data> _up;


	//视图矩阵
	std::shared_ptr<REMat4Data> _result;
};
