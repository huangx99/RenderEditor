#include "RenderEditor.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

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

	//scene.save();

	return 0;
}
