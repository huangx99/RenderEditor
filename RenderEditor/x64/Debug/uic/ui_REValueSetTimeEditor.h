/********************************************************************************
** Form generated from reading UI file 'REValueSetTimeEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVALUESETTIMEEDITOR_H
#define UI_REVALUESETTIMEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_REValueSetTimeEditorClass
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *REValueSetTimeEditorClass)
    {
        if (REValueSetTimeEditorClass->objectName().isEmpty())
            REValueSetTimeEditorClass->setObjectName(QString::fromUtf8("REValueSetTimeEditorClass"));
        REValueSetTimeEditorClass->resize(600, 400);
        formLayout = new QFormLayout(REValueSetTimeEditorClass);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(REValueSetTimeEditorClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(REValueSetTimeEditorClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);


        retranslateUi(REValueSetTimeEditorClass);

        QMetaObject::connectSlotsByName(REValueSetTimeEditorClass);
    } // setupUi

    void retranslateUi(QWidget *REValueSetTimeEditorClass)
    {
        REValueSetTimeEditorClass->setWindowTitle(QApplication::translate("REValueSetTimeEditorClass", "REValueSetTimeEditor", nullptr));
        label->setText(QApplication::translate("REValueSetTimeEditorClass", "\345\200\274\350\256\276\347\275\256\346\254\241\346\225\260", nullptr));
        comboBox->setItemText(0, QApplication::translate("REValueSetTimeEditorClass", "\344\270\200\346\254\241", nullptr));
        comboBox->setItemText(1, QApplication::translate("REValueSetTimeEditorClass", "\345\270\247\346\233\264\346\226\260", nullptr));

    } // retranslateUi

};

namespace Ui {
    class REValueSetTimeEditorClass: public Ui_REValueSetTimeEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVALUESETTIMEEDITOR_H
