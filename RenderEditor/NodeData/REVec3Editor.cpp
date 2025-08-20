#include "REVec3Editor.h"

REVec3Editor::REVec3Editor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::REVec3EditorClass())
{
	ui->setupUi(this);

	ui->label_red->setStyleSheet("background-color: red;");
	ui->label_green->setStyleSheet("background-color: green;");
	ui->label_blue->setStyleSheet("background-color: blue;");

	connect(ui->doubleSpinBox_x, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		this, &REVec3Editor::onAnySpinBoxValueChanged);

	connect(ui->doubleSpinBox_y, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		this, &REVec3Editor::onAnySpinBoxValueChanged);

	connect(ui->doubleSpinBox_z, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		this, &REVec3Editor::onAnySpinBoxValueChanged);

	_value = glm::vec3(0.0);
}

REVec3Editor::~REVec3Editor()
{
	delete ui;
}

glm::vec3 REVec3Editor::getValue() const
{
	return _value;
}

void REVec3Editor::setValue(const glm::vec3 & value)
{
	ui->doubleSpinBox_x->setValue(value.x);
	ui->doubleSpinBox_y->setValue(value.y);
	ui->doubleSpinBox_z->setValue(value.z);
}


void REVec3Editor::onAnySpinBoxValueChanged(double value)
{
	_value.x = ui->doubleSpinBox_x->value();
	_value.y = ui->doubleSpinBox_y->value();
	_value.z = ui->doubleSpinBox_z->value();

	emit valueEdited(_value);
}