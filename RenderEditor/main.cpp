#include "RenderEditor.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// 创建并配置 QSurfaceFormat
	QSurfaceFormat format;
	format.setDepthBufferSize(24);        // 深度缓冲
	format.setStencilBufferSize(8);       // 模板缓冲
	format.setSamples(4);                 // 关键：设置多重采样数量 (4x MSAA)
	// format.setSamples(8);             // 可以尝试 8x，但性能开销更大
	format.setProfile(QSurfaceFormat::CoreProfile); // 或者 CompatibilityProfile
	format.setVersion(3, 3);              // 设置 OpenGL 版本

	// 将格式应用到所有 OpenGL 上下文
	QSurfaceFormat::setDefaultFormat(format);
	/*std::shared_ptr<NodeDelegateModelRegistry> registry = registerDataModels();
	DataFlowGraphModel dataFlowGraphModel(registry);

	DataFlowGraphicsScene scene(dataFlowGraphModel);

	scene.load();

	GraphicsView view(&scene);

	view.setWindowTitle(QString::fromUtf8(""));
	
	view.show();*/

	RenderEditor* editor = new RenderEditor;
	editor->show();

	app.exec();

	editor->save();

	return 0;
}
