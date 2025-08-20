#pragma once

#include <iostream>

#include <QLabel>

#include <QtNodes/NodeDelegateModel>
#include <QtNodes/NodeDelegateModelRegistry>


#include "REPixmapData.hpp"
#include "REImageLabel.h"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;


class REImageLoaderModel : public NodeDelegateModel
{
public:
	REImageLoaderModel();

	~REImageLoaderModel() = default;

public:
	QString caption() const override { return QString::fromUtf8("图片加载"); }

	QString name() const override { return QString("图片加载"); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
	virtual QString modelName() const { return QString("图片"); }

	unsigned int nPorts(PortType const portType) const override;

	NodeDataType dataType(PortType const portType, PortIndex const portIndex) const override;

	std::shared_ptr<NodeData> outData(PortIndex const port) override;

	void setInData(std::shared_ptr<NodeData>, PortIndex const portIndex) override {}

	QWidget *embeddedWidget() override { return _label; }

	bool resizable() const override { return true; }

private:
	REImageLabel *_label;

	QPixmap _pixmap;
};
