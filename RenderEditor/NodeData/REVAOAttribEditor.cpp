#include "REVAOAttribEditor.h"


REVAOAttribEditor::REVAOAttribEditor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::REVAOAttribEditorClass())
{
	ui->setupUi(this);
}

REVAOAttribEditor::~REVAOAttribEditor()
{
	delete ui;
}

void REVAOAttribEditor::setParam(const REVAOAttribParam & param)
{
	ui->comboBox_map->setCurrentIndex((int)param.openMap);
	ui->comboBox_type->setCurrentIndex(param.type - 0x1400);
	ui->spinBox_byteSize->setValue(param.byteSize);
	ui->spinBox_count->setValue(param.count);
	ui->spinBox_location->setValue(param.location);
	ui->spinBox_stride->setValue(param.stride);
	_param = param;
}

REVAOAttribParam REVAOAttribEditor::getParam() const
{
	return _param;
}

void REVAOAttribEditor::on_spinBox_location_valueChanged(int value)
{
	_param.location = value;
	emit dataUpdate();
}

void REVAOAttribEditor::on_spinBox_count_valueChanged(int value)
{
	_param.count = value;
	emit dataUpdate();
}

void REVAOAttribEditor::on_spinBox_byteSize_valueChanged(int value)
{
	_param.byteSize = value;
	emit dataUpdate();
}

void REVAOAttribEditor::on_spinBox_stride_valueChanged(int value)
{
	_param.stride = value;
	emit dataUpdate();
}

void REVAOAttribEditor::on_comboBox_map_currentIndexChanged(int index)
{
	_param.openMap = index;
	emit dataUpdate();
}

void REVAOAttribEditor::on_comboBox_type_currentIndexChanged(int index)
{
	//#define GL_BYTE                           0x1400
	//#define GL_UNSIGNED_BYTE                  0x1401
	//#define GL_SHORT                          0x1402
	//#define GL_UNSIGNED_SHORT                 0x1403
	//#define GL_INT                            0x1404
	//#define GL_UNSIGNED_INT                   0x1405
	//#define GL_FLOAT                          0x1406
	//#define GL_2_BYTES                        0x1407
	//#define GL_3_BYTES                        0x1408
	//#define GL_4_BYTES                        0x1409
	//#define GL_DOUBLE                         0x140A
	
	_param.type = index + 0x1400;
	emit dataUpdate();
}
