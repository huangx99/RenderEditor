#include "REFileDisplayDataModel.h"

#include <QtWidgets/QLabel>

REFileDisplayDataModel::REFileDisplayDataModel()
    : _label{nullptr}
{}

unsigned int REFileDisplayDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType) {
    case PortType::In:
        result = 1;
        break;

    case PortType::Out:
        result = 0;

    default:
        break;
    }

    return result;
}

NodeDataType REFileDisplayDataModel::dataType(PortType, PortIndex) const
{
    return REStringData().type();
}

std::shared_ptr<NodeData> REFileDisplayDataModel::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void REFileDisplayDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex)
{
    _fileData = std::dynamic_pointer_cast<REStringData>(data);

    if (!_label)
        return;

    if (_fileData) {
        _label->setText(_fileData->value());
    } else {
        _label->clear();
    }

}

QWidget *REFileDisplayDataModel::embeddedWidget()
{
    if (!_label) {
        _label = new QTextBrowser();
   
    }

    return _label;
}