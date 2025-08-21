#include "RECreateShaderEditor.h"

#include <QFileDialog>
RECreateShaderEditor::RECreateShaderEditor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::RECreateShaderEditorClass())
{
	ui->setupUi(this);

	//connect(
	//	ui->lineEdit_vertexPath, &QLineEdit::textEdited, 
	//	this, &RECreateShaderEditor::on_lineEdit_vertexPath_textEdited);

	//connect(
	//	ui->lineEdit_fragmentPath, &QLineEdit::textEdited,
	//	this, &RECreateShaderEditor::on_lineEdit_fragmentPath_textEdited);
}

RECreateShaderEditor::~RECreateShaderEditor()
{
	delete ui;
}
RECreateShaderParam RECreateShaderEditor::getParam() const
{
	RECreateShaderParam param;

	param.fragmentShaderPath = ui->lineEdit_fragmentPath->text();
	param.vertexShaderPath = ui->lineEdit_vertexPath->text();

	return param;
}
void RECreateShaderEditor::setParam(const RECreateShaderParam & param)
{
	_param = param;
	ui->lineEdit_fragmentPath->setText(_param.fragmentShaderPath);
	ui->lineEdit_vertexPath->setText(_param.vertexShaderPath);

	emit dataUpdate();
}
void RECreateShaderEditor::on_pushButton_vertexPath_clicked(bool clicked)
{
	// 打开单文件选择
	QString filePath = QFileDialog::getOpenFileName(
		this,                          // 父窗口
		"选择文件",                    // 标题
		"",                            // 默认路径（空字符串表示当前目录）
		"着色器文件 (*.vert *.frag);;所有文件 (*.*)" // 过滤器
	);

	if (!filePath.isEmpty()) {
		ui->lineEdit_vertexPath->setText(filePath);
		emit dataUpdate();
	}

}

void RECreateShaderEditor::on_pushButton_fragmentPath_clicked(bool clicked)
{
	// 打开单文件选择
	QString filePath = QFileDialog::getOpenFileName(
		this,                          // 父窗口
		"选择文件",                    // 标题
		"",                            // 默认路径（空字符串表示当前目录）
		"着色器文件 (*.vert *.frag);;所有文件 (*.*)" // 过滤器
	);

	if (!filePath.isEmpty()) {
		ui->lineEdit_fragmentPath->setText(filePath);
		emit dataUpdate();
	}
}

void RECreateShaderEditor::on_pushButton_Compile_clicked(bool clicked)
{
	emit dataUpdate();
}

void RECreateShaderEditor::on_lineEdit_vertexPath_textEdited(QString const & string)
{
	if (_param.vertexShaderPath != string)
	{
		emit dataUpdate();
		_param.vertexShaderPath = string;
	}
}

void RECreateShaderEditor::on_lineEdit_fragmentPath_textEdited(QString const & string)
{
	if (_param.fragmentShaderPath != string)
	{
		emit dataUpdate();
		_param.fragmentShaderPath = string;
	}
}
