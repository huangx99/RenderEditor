#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QLineEdit>
#include <QtCore/QJsonObject>
#include <QObject>
#include <QtWidgets/QLabel>

#include "RECreateShaderEditor.h"
#include "REOpenGLModel.hpp"


class RECreateShaderNode;
class REStringData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class RECreateShaderModel : public REOpenGLModel
{

public:
	RECreateShaderModel();

	virtual ~RECreateShaderModel() = default;
	QString caption() const override { return QString::fromUtf8("createShader"); }

	QString name() const override { return QString::fromUtf8("createShader"); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
	unsigned int nPorts(PortType portType) const override;

	NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

	void setInData(std::shared_ptr<NodeData> data, PortIndex const index) override;

	std::shared_ptr<NodeData> outData(PortIndex port) override;

	QWidget *embeddedWidget() override;

private:
	QString readFileAsQString(const QString &filePath);

public slots:
	void onDataUpdate();

protected:

	std::shared_ptr<REStringData> _ShaderID;
	std::shared_ptr<REStringData> _vertexCode;
	std::shared_ptr<REStringData> _fragmentCode;

	std::shared_ptr<RECreateShaderNode> _createShaderNode;


	RECreateShaderEditor* _editor;
};
