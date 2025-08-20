#pragma once

#include <QWidget>
#include "ui_REVec3Editor.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class REVec3EditorClass; };
QT_END_NAMESPACE

class REVec3Editor : public QWidget
{
	Q_OBJECT

public:
	REVec3Editor(QWidget *parent = nullptr);
	~REVec3Editor();

	glm::vec3 getValue() const;

	void setValue(const glm::vec3& value);

signals:
	void valueEdited(const glm::vec3& value);

public slots:
	void onAnySpinBoxValueChanged(double value);

	
private:
	Ui::REVec3EditorClass *ui;

	glm::vec3 _value;
};
