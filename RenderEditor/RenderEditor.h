#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RenderEditor.h"

#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/GraphicsView>
#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModelRegistry>
#include <QtNodes/DataFlowGraphicsScene>

using QtNodes::DataFlowGraphicsScene;
using QtNodes::DataFlowGraphModel;
using QtNodes::GraphicsView;
using QtNodes::NodeDelegateModelRegistry;

QT_BEGIN_NAMESPACE
namespace Ui { class RenderEditorClass; };
QT_END_NAMESPACE

class RenderEditor : public QMainWindow
{
    Q_OBJECT

public:
    RenderEditor(QWidget *parent = nullptr);
    ~RenderEditor();

	void save();

private:
	void initView();

private:
    Ui::RenderEditorClass *ui;

	DataFlowGraphicsScene* _scene;
};
