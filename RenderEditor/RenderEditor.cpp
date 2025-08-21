#include "RenderEditor.h"

#include "service/REOpenGLRenderService.h"



#include "NodeData/REVec3SourceDataModel.h"
#include "NodeData/REOpenGLDisplayModel.h"
#include "NodeData/REVec3CrossModel.hpp"
#include "NodeData/REGLClearColorModel.h"
#include "NodeData/RECreateVertexModel.h"
#include "NodeData/REVAOAttribModel.h"
#include "NodeData/REGLDrawArraysMode.h"
#include "NodeData/REFloatArraySourceDataModel.h"
#include "NodeData/RETextSourceDataModel.h"
#include "NodeData/RETextDisplayDataModel.h"
#include "NodeData/RECreateShaderModel.h"
#include "NodeData/REUseShaderModel.h"
#include "NodeData/REIntSourceDataModel.h"
#include "NodeData/REFloatSourceDataModel.h"
#include "NodeData/RESetUniformIntModel.h"
#include "NodeData/RESetUniformVec3Model.h"
#include "NodeData/RESetUniformMat4Model.h"
#include "NodeData/REFileDisplayDataModel.h"
#include "NodeData/REImageLoaderModel.h"
#include "NodeData/RECreateTextureModel.h"
#include "NodeData/REUseTextureModel.h"
#include "NodeData/REScaleModel.h"
#include "NodeData/RETranslateModel.h"
#include "NodeData/REProjectionModel.h"
#include "NodeData/RERotateModel.h"
#include "NodeData/REViewModel.h"
#include "NodeData/RETimerModel.h"
#include "NodeData/RELoopModel.h"
#include "NodeData/RELoopEndModel.h"
#include "NodeData/RESinModel.h"



static std::shared_ptr<NodeDelegateModelRegistry> registerDataModels()
{
	auto ret = std::make_shared<NodeDelegateModelRegistry>();

	ret->registerModel<REVec3SourceDataModel>("数学");
	ret->registerModel<REVec3CrossModel>("数学");
	ret->registerModel<RESinModel>("数学");
	ret->registerModel<REFloatArraySourceDataModel>("数据");
	ret->registerModel<RETextSourceDataModel>("数据");
	ret->registerModel<RETextDisplayDataModel>("数据");
	ret->registerModel<REIntSourceDataModel>("数据");
	ret->registerModel<REFloatSourceDataModel>("数据");
	ret->registerModel<REFileDisplayDataModel>("数据");
	ret->registerModel<REImageLoaderModel>("数据");
	ret->registerModel<REOpenGLDisplayModel>("OpenGL");
	ret->registerModel<REGLClearColorModel>("OpenGL");
	ret->registerModel<REVAOAttribModel>("OpenGL");
	ret->registerModel<RECreateVertexModel>("OpenGL");
	ret->registerModel<REGLDrawArraysMode>("OpenGL");
	ret->registerModel<RECreateShaderModel>("OpenGL");
	ret->registerModel<REUseShaderModel>("OpenGL");
	ret->registerModel<RESetUniformIntModel>("OpenGL");
	ret->registerModel<RESetUniformMat4Model>("OpenGL");
	ret->registerModel<RESetUniformVec3Model>("OpenGL");
	ret->registerModel<RECreateTextureModel>("OpenGL");
	ret->registerModel<REUseTextureModel>("OpenGL");
	ret->registerModel<RETranslateModel>("变换");
	ret->registerModel<RERotateModel>("变换");
	ret->registerModel<REScaleModel>("变换");
	ret->registerModel<REViewModel>("变换");
	ret->registerModel<REProjectionModel>("变换");
	ret->registerModel<RETimerModel>("Timer");
	ret->registerModel<RELoopModel>("流程");
	ret->registerModel<RELoopEndModel>("流程");

	return ret;
}

RenderEditor::RenderEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RenderEditorClass())
{
    ui->setupUi(this);

	initView();
}

RenderEditor::~RenderEditor()
{
    delete ui;
}

void RenderEditor::save()
{
	_scene->save();
}

void RenderEditor::initView()
{
	std::shared_ptr<NodeDelegateModelRegistry> registry = registerDataModels();
	DataFlowGraphModel* dataFlowGraphModel = new DataFlowGraphModel(registry);

	_scene = new DataFlowGraphicsScene(*dataFlowGraphModel, this);

	_scene->load();

	GraphicsView* view = new GraphicsView(_scene);

	ui->tabWidget->addTab(view, "渲染管线编辑");


	ui->tabWidget->addTab(REOpenGLRenderService::getInstance().getOpenGLWidget(), "渲染窗口");
}
