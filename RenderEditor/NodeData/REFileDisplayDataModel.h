#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QObject>

#include <iostream>
#include <QTextBrowser>

#include "REStringData.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class QLabel;

class REFileDisplayDataModel : public NodeDelegateModel
{

public:
    REFileDisplayDataModel();

    ~REFileDisplayDataModel() = default;

public:
    QString caption() const override { return QString::fromUtf8("文件内容"); }

    bool captionVisible() const override { return false; }

    QString name() const override { return QString::fromUtf8("文件内容"); }

public:
    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) override;

    QWidget *embeddedWidget() override;

private:
    std::shared_ptr<REStringData> _fileData;

    QTextBrowser *_label;
};
