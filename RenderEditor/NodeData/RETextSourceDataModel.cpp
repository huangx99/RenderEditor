#include "RETextSourceDataModel.h"

#include <QtWidgets/QLineEdit>

RETextSourceDataModel::RETextSourceDataModel()
    : _lineEdit{nullptr}
{
    //
}

QJsonObject RETextSourceDataModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	modelJson["value"] = _lineEdit->text();

	return modelJson;
}

void RETextSourceDataModel::load(QJsonObject const & config)
{
	QString value = config["value"].toString();
	_lineEdit->setText(value);
}

unsigned int RETextSourceDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType) {
    case PortType::In:
        result = 0;
        break;

    case PortType::Out:
        result = 1;

    default:
        break;
    }

    return result;
}

void RETextSourceDataModel::onTextEdited(QString const &string)
{
    Q_UNUSED(string);

    Q_EMIT dataUpdated(0);
}

NodeDataType RETextSourceDataModel::dataType(PortType, PortIndex) const
{
    return REStringData().type();
}

std::shared_ptr<NodeData> RETextSourceDataModel::outData(PortIndex const portIndex)
{
    Q_UNUSED(portIndex);
    return std::make_shared<REStringData>(_lineEdit->text());
}

QWidget *RETextSourceDataModel::embeddedWidget()
{
    if (!_lineEdit) {
        _lineEdit = new QLineEdit("Default Text"),

        connect(_lineEdit, &QLineEdit::textEdited, this, &RETextSourceDataModel::onTextEdited);
    }

    return _lineEdit;
}
