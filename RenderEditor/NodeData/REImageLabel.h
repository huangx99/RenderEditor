#pragma once

#include <QLabel>
#include <QPixmap>

class REImageLabel : public QLabel
{
	Q_OBJECT
public:
	explicit REImageLabel(QWidget *parent = nullptr);

	QPixmap pixmapData() const { return _pixmap; }
	QString getPath() const { return _path; }
	void setPath(const QString& path);

signals:
	void imageLoaded(const QPixmap &pixmap);

protected:
	bool eventFilter(QObject *object, QEvent *event) override;

private:
	QPixmap _pixmap;

	QString _path;
};
