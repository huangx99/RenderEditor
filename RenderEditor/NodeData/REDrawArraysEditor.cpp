#include "REDrawArraysEditor.h"

REDrawArraysEditor::REDrawArraysEditor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::REDrawArraysEditorClass())
{
	ui->setupUi(this);
}

REDrawArraysEditor::~REDrawArraysEditor()
{
	delete ui;
}

void REDrawArraysEditor::setParam(const REDrawArraysParam & param)
{
	_param = param;
	ui->comboBox_mode->setCurrentIndex(param.mode);
	ui->spinBox_pointCount->setValue(param.pointCount);
	ui->spinBox_start->setValue(param.startIndex);
}

REDrawArraysParam REDrawArraysEditor::getParam() const
{
	return _param;
}

void REDrawArraysEditor::on_spinBox_start_valueChanged(int value)
{
	_param.startIndex = value;
	emit dataUpdate();
}

void REDrawArraysEditor::on_spinBox_pointCount_valueChanged(int value)
{
	_param.pointCount = value;
	emit dataUpdate();
}

void REDrawArraysEditor::on_comboBox_mode_currentIndexChanged(int index)
{
	//#define GL_POINTS                         0x0000
	//#define GL_LINES                          0x0001
	//#define GL_LINE_LOOP                      0x0002
	//#define GL_LINE_STRIP                     0x0003
	//#define GL_TRIANGLES                      0x0004
	//#define GL_TRIANGLE_STRIP                 0x0005
	//#define GL_TRIANGLE_FAN                   0x0006
	//#define GL_QUADS                          0x0007
	//#define GL_QUAD_STRIP                     0x0008
	//#define GL_POLYGON                        0x0009
	_param.mode = index;
	emit dataUpdate();
}
