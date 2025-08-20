#pragma once

#include <QWidget>
#include "ui_REValueSetTimeEditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class REValueSetTimeEditorClass; };
QT_END_NAMESPACE

class REValueSetTimeEditor : public QWidget
{
	Q_OBJECT

public:
	REValueSetTimeEditor(QWidget *parent = nullptr);
	~REValueSetTimeEditor();

	//0:一次，1:无限制
	int getTime() const;

	//0:一次，1:无限制
	void setTime(int timeType);

signals:
	void dataUpdate();

private:
	Ui::REValueSetTimeEditorClass *ui;
};
