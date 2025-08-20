#include "RETextDisplayDataModel.h"

RETextDisplayDataModel::RETextDisplayDataModel()
    : _label(new QLabel("Resulting Text"))
{
    _label->setMargin(3);
}

unsigned int RETextDisplayDataModel::nPorts(PortType portType) const
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

NodeDataType RETextDisplayDataModel::dataType(PortType, PortIndex) const
{
    return RETextData().type();
}

std::shared_ptr<NodeData> RETextDisplayDataModel::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void RETextDisplayDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex const)
{
    auto textData = std::dynamic_pointer_cast<RETextData>(data);

    if (textData) {
        _inputText = textData->text();
    } else {
        _inputText = "";
    }

    _label->setText(_inputText);
    _label->adjustSize();
}
