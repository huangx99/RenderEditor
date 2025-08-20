#pragma once

#include <QWidget>
#include "ui_REVAOAttribEditor.h"
#include "REVAOAttribNode.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class REVAOAttribEditorClass; };
QT_END_NAMESPACE


class REVAOAttribEditor : public QWidget
{
	Q_OBJECT

public:
	REVAOAttribEditor(QWidget *parent = nullptr);
	~REVAOAttribEditor();

	REVAOAttribParam getParam() const;

	void setParam(const REVAOAttribParam& param);

private slots:
	void on_spinBox_location_valueChanged(int value);
	void on_spinBox_count_valueChanged(int value);
	void on_spinBox_byteSize_valueChanged(int value);
	void on_spinBox_stride_valueChanged(int value);

	void on_comboBox_map_currentIndexChanged(int index);
	void on_comboBox_type_currentIndexChanged(int index);

signals:
	void dataUpdate();

private:
	Ui::REVAOAttribEditorClass *ui;

	REVAOAttribParam _param;
};
