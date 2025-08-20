#pragma once

#include <QWidget>
#include "ui_REDrawArraysEditor.h"
#include "REGLDrawArraysNode.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class REDrawArraysEditorClass; };
QT_END_NAMESPACE

class REDrawArraysEditor : public QWidget
{
	Q_OBJECT

public:
	REDrawArraysEditor(QWidget *parent = nullptr);
	~REDrawArraysEditor();

	void setParam(const REDrawArraysParam& param);

	REDrawArraysParam getParam() const;

private slots:
	void on_spinBox_start_valueChanged(int value);
	void on_spinBox_pointCount_valueChanged(int value);
	void on_comboBox_mode_currentIndexChanged(int index);

signals:
	void dataUpdate();

private:
	Ui::REDrawArraysEditorClass *ui;

	REDrawArraysParam _param;
};
