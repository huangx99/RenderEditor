#pragma once

#include <QWidget>
#include "ui_RECreateShaderEditor.h"
#include "RECreateShaderNode.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class RECreateShaderEditorClass; };
QT_END_NAMESPACE

class RECreateShaderEditor : public QWidget
{
	Q_OBJECT

public:
	RECreateShaderEditor(QWidget *parent = nullptr);
	~RECreateShaderEditor();

	RECreateShaderParam getParam() const;


	void setParam(const RECreateShaderParam& param);

private slots:
	void on_pushButton_vertexPath_clicked(bool clicked = false);
	void on_pushButton_fragmentPath_clicked(bool clicked = false);
	void on_lineEdit_vertexPath_textEdited(QString const &string);
	void on_lineEdit_fragmentPath_textEdited(QString const &string);
signals:
	void dataUpdate();
private:
	Ui::RECreateShaderEditorClass *ui;

	RECreateShaderParam _param;
};
