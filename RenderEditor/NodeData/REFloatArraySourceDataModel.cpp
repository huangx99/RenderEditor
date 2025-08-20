#include "REFloatArraySourceDataModel.h"

#include "REFloatArrayData.hpp"

REFloatArraySourceDataModel::REFloatArraySourceDataModel()
{
	_editor = new QTextEdit();
	_editor->adjustSize();
	connect(_editor, &QTextEdit::textChanged, this, &REFloatArraySourceDataModel::onTextChanged);
}

QJsonObject REFloatArraySourceDataModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	modelJson["value"] = _editor->toPlainText();
	return modelJson;
}

void REFloatArraySourceDataModel::load(QJsonObject const & config)
{
	_editor->setText(config["value"].toString());
}

unsigned int REFloatArraySourceDataModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 0;
	else
		result = 1;

	return result;
}

NodeDataType REFloatArraySourceDataModel::dataType(PortType, PortIndex) const
{
	return REFloatArrayData().type();
}

std::shared_ptr<NodeData> REFloatArraySourceDataModel::outData(PortIndex)
{
	// 假设 _editor 里有内容，例如："1.2, 3.4, 5.6"
	QString text = _editor->toPlainText();  // 获取 QTextBrowser 内容
	QStringList list = text.split(',', QString::SkipEmptyParts);  // 按逗号分割，忽略空项

	std::vector<float> values;
	for (const QString& item : list)
	{
		bool ok;
		float value = item.trimmed().toFloat(&ok);  // 去空格并转换为 float
		if (ok)
			values.push_back(value);
	}

	_result = std::make_shared<REFloatArrayData>(values);

	return std::static_pointer_cast<NodeData>(_result);
}


void REFloatArraySourceDataModel::onTextChanged()
{
	Q_EMIT dataUpdated(0);
}