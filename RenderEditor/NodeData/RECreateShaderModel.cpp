#include "RECreateShaderModel.h"

#include "RECreateShaderNode.hpp"
#include "REFloatArrayData.hpp"
#include "REStringData.hpp"

RECreateShaderModel::RECreateShaderModel()
{
	_node = std::make_shared<RECreateShaderNode>();
	_createShaderNode = std::dynamic_pointer_cast<RECreateShaderNode>(_node);

	_result = _node;
	
	_ShaderID = std::make_shared<REStringData>(QString::fromStdString(_node->getID()));
	_fragmentCode = std::make_shared<REStringData>("");
	_vertexCode = std::make_shared<REStringData>("");

	_editor = new RECreateShaderEditor;
	_editor->adjustSize();

	connect(_editor, &RECreateShaderEditor::dataUpdate, this, &RECreateShaderModel::onDataUpdate);
}

QJsonObject RECreateShaderModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	auto param = _editor->getParam();
	modelJson["vertexShaderPath"] = param.vertexShaderPath;
	modelJson["fragmentShaderPath"] = param.fragmentShaderPath;
	return modelJson;
}

void RECreateShaderModel::load(QJsonObject const & modelJson)
{
	RECreateShaderParam param;
	param = _editor->getParam();
	param.vertexShaderPath = modelJson["vertexShaderPath"].toString();
	param.fragmentShaderPath = modelJson["fragmentShaderPath"].toString();
	_editor->setParam(param);
}

void RECreateShaderModel::onDataUpdate()
{
	auto param = _editor->getParam();
	bool update = _createShaderNode->setParam(param);

	if (update)
	{
		_editor->adjustSize();

		QString fs = readFileAsQString(param.fragmentShaderPath);
		_fragmentCode->setValue(fs);

		QString vs = readFileAsQString(param.vertexShaderPath);
		_vertexCode->setValue(vs);

		Q_EMIT dataUpdated(0);
		Q_EMIT dataUpdated(2);
		Q_EMIT dataUpdated(3);
	}
}

unsigned int RECreateShaderModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 1;
	else
		result = 4;

	return result;
}

NodeDataType RECreateShaderModel::dataType(PortType type, PortIndex index) const
{
	if (index == 0)
	{
		return REOpenGLModel::dataType(type, index);
	}


	if (type == PortType::In)
	{
		
	}
	else
	{
		if (index == 1)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("Shader") };
		else if (index == 2)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("vertex code") };
		else if (index == 3)
			return NodeDataType{ REStringData().type().id,  QString::fromUtf8("fragment code") };
	}

	return RECreateShaderNode().type();
}

void RECreateShaderModel::setInData(std::shared_ptr<NodeData> data, PortIndex const portIndex)
{
	if (portIndex == 0)
		REOpenGLModel::setInData(data, portIndex);

	if (!data) {
		Q_EMIT dataInvalidated(0);

		return;
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RECreateShaderModel::outData(PortIndex index)
{
	if (index == 0)
	{
		return std::static_pointer_cast<NodeData>(_result);
	}
	else if (index == 1)
	{
		return std::static_pointer_cast<NodeData>(_ShaderID);
	}
	else if (index == 2)
	{
		return std::static_pointer_cast<NodeData>(_vertexCode);
	}
	else if (index == 3)
	{
		return std::static_pointer_cast<NodeData>(_fragmentCode);
	}
	
	return nullptr;
}

QWidget * RECreateShaderModel::embeddedWidget()
{
	return _editor;
}


QString RECreateShaderModel::readFileAsQString(const QString &filePath)
{
	QFile file(filePath);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		// 打开失败时返回空字符串（你可以选择抛异常或记录错误）
		return QString::fromUtf8("文件路径错误");
	}

	QTextStream in(&file);
	in.setCodec("UTF-8"); // 设置编码（默认就是 UTF-8，也可以视情况更改）
	QString content = in.readAll();
	file.close();

	return content;
}