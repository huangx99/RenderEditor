#pragma once

#include <QtCore/QObject>

#include "REStringData.hpp"

#include <QtNodes/NodeDelegateModel>

#include <iostream>

using QtNodes::NodeData;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class QLineEdit;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class RETextSourceDataModel : public NodeDelegateModel
{
public:
    RETextSourceDataModel();

public:
    QString caption() const override { return QString("string"); }

    bool captionVisible() const override { return false; }

    static QString Name() { return QString("string"); }

    QString name() const override { return RETextSourceDataModel::Name(); }

	virtual QJsonObject save() const override;

	virtual void load(QJsonObject const & /*p*/) override;

public:
    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex const portIndex) override;

    void setInData(std::shared_ptr<NodeData>, PortIndex const) override {}

    QWidget *embeddedWidget() override;

private slots:

    void onTextEdited(QString const &string);

private:
    QLineEdit *_lineEdit;
};
