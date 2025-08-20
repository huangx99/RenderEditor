#include "REImageLoaderModel.h"

#include <QtCore/QDir>
#include <QtCore/QEvent>

#include <QtWidgets/QFileDialog>

REImageLoaderModel::REImageLoaderModel()
	: _label(new REImageLabel())
{
	_label->setText(QString::fromUtf8("双击加载图片"));
	_label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

	QFont f = _label->font();
	f.setBold(true);
	f.setItalic(true);

	_label->setFont(f);

	_label->setMinimumSize(200, 200);
	_label->setMaximumSize(500, 300);

	_label->installEventFilter(this);

	connect(_label, &REImageLabel::imageLoaded, this, [this](const QPixmap &pixmap) {
		_pixmap = pixmap;
		Q_EMIT dataUpdated(0);
	});
}

QJsonObject REImageLoaderModel::save() const
{
	QJsonObject modelJson = NodeDelegateModel::save();
	
	modelJson["imagePath"] = _label->getPath();
	return modelJson;
}

void REImageLoaderModel::load(QJsonObject const & modelJson)
{
	_label->setPath(modelJson["imagePath"].toString());
}


unsigned int REImageLoaderModel::nPorts(PortType portType) const
{
	unsigned int result = 1;

	switch (portType) {
	case PortType::In:
		result = 0;
		break;

	case PortType::Out:
		result = 1;

	default:
		break;
	}

	return result;
}

NodeDataType REImageLoaderModel::dataType(PortType const, PortIndex const) const
{
	return REPixmapData().type();
}

std::shared_ptr<NodeData> REImageLoaderModel::outData(PortIndex)
{
	return std::make_shared<REPixmapData>(_pixmap);
}
