/********************************************************************************
** Form generated from reading UI file 'REDrawArraysEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDRAWARRAYSEDITOR_H
#define UI_REDRAWARRAYSEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_REDrawArraysEditorClass
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_mode;
    QLabel *label_2;
    QSpinBox *spinBox_start;
    QLabel *label_3;
    QSpinBox *spinBox_pointCount;

    void setupUi(QWidget *REDrawArraysEditorClass)
    {
        if (REDrawArraysEditorClass->objectName().isEmpty())
            REDrawArraysEditorClass->setObjectName(QString::fromUtf8("REDrawArraysEditorClass"));
        REDrawArraysEditorClass->resize(600, 400);
        formLayout = new QFormLayout(REDrawArraysEditorClass);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(REDrawArraysEditorClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_mode = new QComboBox(REDrawArraysEditorClass);
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->setObjectName(QString::fromUtf8("comboBox_mode"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_mode);

        label_2 = new QLabel(REDrawArraysEditorClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBox_start = new QSpinBox(REDrawArraysEditorClass);
        spinBox_start->setObjectName(QString::fromUtf8("spinBox_start"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_start);

        label_3 = new QLabel(REDrawArraysEditorClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBox_pointCount = new QSpinBox(REDrawArraysEditorClass);
        spinBox_pointCount->setObjectName(QString::fromUtf8("spinBox_pointCount"));
        spinBox_pointCount->setMaximum(999999999);
        spinBox_pointCount->setValue(3);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_pointCount);


        retranslateUi(REDrawArraysEditorClass);

        QMetaObject::connectSlotsByName(REDrawArraysEditorClass);
    } // setupUi

    void retranslateUi(QWidget *REDrawArraysEditorClass)
    {
        REDrawArraysEditorClass->setWindowTitle(QApplication::translate("REDrawArraysEditorClass", "REDrawArraysEditor", nullptr));
        label->setText(QApplication::translate("REDrawArraysEditorClass", "\347\273\230\345\210\266\346\250\241\345\274\217", nullptr));
        comboBox_mode->setItemText(0, QApplication::translate("REDrawArraysEditorClass", "GL_POINTS", nullptr));
        comboBox_mode->setItemText(1, QApplication::translate("REDrawArraysEditorClass", "GL_LINES", nullptr));
        comboBox_mode->setItemText(2, QApplication::translate("REDrawArraysEditorClass", "GL_LINE_LOOP", nullptr));
        comboBox_mode->setItemText(3, QApplication::translate("REDrawArraysEditorClass", "GL_LINE_STRIP", nullptr));
        comboBox_mode->setItemText(4, QApplication::translate("REDrawArraysEditorClass", "GL_TRIANGLES", nullptr));
        comboBox_mode->setItemText(5, QApplication::translate("REDrawArraysEditorClass", "GL_TRIANGLE_STRIP", nullptr));
        comboBox_mode->setItemText(6, QApplication::translate("REDrawArraysEditorClass", "GL_TRIANGLE_FAN", nullptr));
        comboBox_mode->setItemText(7, QApplication::translate("REDrawArraysEditorClass", "GL_QUADS", nullptr));
        comboBox_mode->setItemText(8, QApplication::translate("REDrawArraysEditorClass", "GL_QUAD_STRIP", nullptr));
        comboBox_mode->setItemText(9, QApplication::translate("REDrawArraysEditorClass", "GL_POLYGON", nullptr));

        label_2->setText(QApplication::translate("REDrawArraysEditorClass", "\351\241\266\347\202\271\346\225\260\347\273\204\350\265\267\345\247\213\344\275\215", nullptr));
        label_3->setText(QApplication::translate("REDrawArraysEditorClass", "\351\241\266\347\202\271\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REDrawArraysEditorClass: public Ui_REDrawArraysEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDRAWARRAYSEDITOR_H
