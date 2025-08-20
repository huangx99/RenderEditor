#include "REImageLabel.h"
#include <QFileDialog>
#include <QDir>
#include <QEvent>

REImageLabel::REImageLabel(QWidget *parent)
	: QLabel(parent)
{
	setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

	QFont f = font();
	f.setBold(true);
	f.setItalic(true);
	setFont(f);

	setMinimumSize(200, 200);
	setMaximumSize(500, 300);

	installEventFilter(this);
}

void REImageLabel::setPath(const QString & path)
{
	int w = width();
	int h = height();
	_path = path;
	_pixmap = QPixmap(path);
	setPixmap(_pixmap.scaled(w, h, Qt::KeepAspectRatio));

	emit imageLoaded(_pixmap);
}

bool REImageLabel::eventFilter(QObject *object, QEvent *event)
{
	if (object == this) {
		int w = width();
		int h = height();

		if (event->type() == QEvent::MouseButtonPress) {
			QString fileName = QFileDialog::getOpenFileName(nullptr,
				tr("Open Image"),
				QDir::homePath(),
				tr("Image Files (*.png *.jpg *.bmp)"));

			if (!fileName.isEmpty()) {
				_path = fileName;
				_pixmap = QPixmap(fileName);
				setPixmap(_pixmap.scaled(w, h, Qt::KeepAspectRatio));

				emit imageLoaded(_pixmap);
			}
			return true;
		}
		else if (event->type() == QEvent::Resize) {
			if (!_pixmap.isNull())
				setPixmap(_pixmap.scaled(w, h, Qt::KeepAspectRatio));
		}
	}
	return QLabel::eventFilter(object, event);
}
