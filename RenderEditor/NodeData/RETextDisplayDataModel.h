#pragma once

#include "RETextData.hpp"

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include <iostream>
#include <vector>

using QtNodes::ConnectionPolicy;
using QtNodes::NodeData;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class RETextDisplayDataModel : public NodeDelegateModel
{
public:
    RETextDisplayDataModel();

    virtual ~RETextDisplayDataModel() {}

public:
    QString caption() const override { return QString("text显示"); }

    bool captionVisible() const override { return false; }

    static QString Name() { return QString("text显示"); }

    QString name() const override { return RETextDisplayDataModel::Name(); }

public:
    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex const port) override;

    void setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex) override;

    QWidget *embeddedWidget() override { return _label; }

private:
    QLabel *_label;
    QString _inputText;
};
