#include "REValueSetTimeEditor.h"

REValueSetTimeEditor::REValueSetTimeEditor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::REValueSetTimeEditorClass())
{
	ui->setupUi(this);

	connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) { emit dataUpdate(); });
}

REValueSetTimeEditor::~REValueSetTimeEditor()
{
	delete ui;
}

int REValueSetTimeEditor::getTime() const
{
	return ui->comboBox->currentIndex();
}

void REValueSetTimeEditor::setTime(int timeType)
{
	ui->comboBox->setCurrentIndex(timeType);
}
