#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RenderEditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RenderEditorClass; };
QT_END_NAMESPACE

class RenderEditor : public QMainWindow
{
    Q_OBJECT

public:
    RenderEditor(QWidget *parent = nullptr);
    ~RenderEditor();

private:
	void initView();

private:
    Ui::RenderEditorClass *ui;
};
