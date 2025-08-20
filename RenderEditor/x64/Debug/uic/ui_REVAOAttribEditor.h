/********************************************************************************
** Form generated from reading UI file 'REVAOAttribEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVAOATTRIBEDITOR_H
#define UI_REVAOATTRIBEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_REVAOAttribEditorClass
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox_location;
    QLabel *label_2;
    QSpinBox *spinBox_count;
    QLabel *label_3;
    QComboBox *comboBox_type;
    QLabel *label_4;
    QComboBox *comboBox_map;
    QLabel *label_5;
    QSpinBox *spinBox_byteSize;
    QLabel *label_6;
    QSpinBox *spinBox_stride;

    void setupUi(QWidget *REVAOAttribEditorClass)
    {
        if (REVAOAttribEditorClass->objectName().isEmpty())
            REVAOAttribEditorClass->setObjectName(QString::fromUtf8("REVAOAttribEditorClass"));
        REVAOAttribEditorClass->resize(600, 196);
        formLayout = new QFormLayout(REVAOAttribEditorClass);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(REVAOAttribEditorClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBox_location = new QSpinBox(REVAOAttribEditorClass);
        spinBox_location->setObjectName(QString::fromUtf8("spinBox_location"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_location);

        label_2 = new QLabel(REVAOAttribEditorClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBox_count = new QSpinBox(REVAOAttribEditorClass);
        spinBox_count->setObjectName(QString::fromUtf8("spinBox_count"));
        spinBox_count->setMaximum(999999999);
        spinBox_count->setValue(3);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_count);

        label_3 = new QLabel(REVAOAttribEditorClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox_type = new QComboBox(REVAOAttribEditorClass);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_type);

        label_4 = new QLabel(REVAOAttribEditorClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_map = new QComboBox(REVAOAttribEditorClass);
        comboBox_map->addItem(QString());
        comboBox_map->addItem(QString());
        comboBox_map->setObjectName(QString::fromUtf8("comboBox_map"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_map);

        label_5 = new QLabel(REVAOAttribEditorClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        spinBox_byteSize = new QSpinBox(REVAOAttribEditorClass);
        spinBox_byteSize->setObjectName(QString::fromUtf8("spinBox_byteSize"));
        spinBox_byteSize->setMaximum(999999999);
        spinBox_byteSize->setValue(12);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_byteSize);

        label_6 = new QLabel(REVAOAttribEditorClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        spinBox_stride = new QSpinBox(REVAOAttribEditorClass);
        spinBox_stride->setObjectName(QString::fromUtf8("spinBox_stride"));
        spinBox_stride->setMaximum(999999999);
        spinBox_stride->setValue(0);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_stride);


        retranslateUi(REVAOAttribEditorClass);

        QMetaObject::connectSlotsByName(REVAOAttribEditorClass);
    } // setupUi

    void retranslateUi(QWidget *REVAOAttribEditorClass)
    {
        REVAOAttribEditorClass->setWindowTitle(QApplication::translate("REVAOAttribEditorClass", "REVAOAttribEditor", nullptr));
        label->setText(QApplication::translate("REVAOAttribEditorClass", "\347\235\200\350\211\262\345\231\250\344\275\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("REVAOAttribEditorClass", "\351\241\266\347\202\271\345\210\206\351\207\217", nullptr));
        label_3->setText(QApplication::translate("REVAOAttribEditorClass", "\345\210\206\351\207\217\347\261\273\345\236\213", nullptr));
        comboBox_type->setItemText(0, QApplication::translate("REVAOAttribEditorClass", "GL_BYTE", nullptr));
        comboBox_type->setItemText(1, QApplication::translate("REVAOAttribEditorClass", "GL_UNSIGNED_BYTE", nullptr));
        comboBox_type->setItemText(2, QApplication::translate("REVAOAttribEditorClass", "GL_SHORT", nullptr));
        comboBox_type->setItemText(3, QApplication::translate("REVAOAttribEditorClass", "GL_UNSIGNED_SHORT", nullptr));
        comboBox_type->setItemText(4, QApplication::translate("REVAOAttribEditorClass", "GL_INT", nullptr));
        comboBox_type->setItemText(5, QApplication::translate("REVAOAttribEditorClass", "GL_UNSIGNED_INT", nullptr));
        comboBox_type->setItemText(6, QApplication::translate("REVAOAttribEditorClass", "GL_FLOAT", nullptr));
        comboBox_type->setItemText(7, QApplication::translate("REVAOAttribEditorClass", "GL_2_BYTES", nullptr));
        comboBox_type->setItemText(8, QApplication::translate("REVAOAttribEditorClass", "GL_3_BYTES", nullptr));
        comboBox_type->setItemText(9, QApplication::translate("REVAOAttribEditorClass", "GL_4_BYTES", nullptr));
        comboBox_type->setItemText(10, QApplication::translate("REVAOAttribEditorClass", "GL_DOUBLE", nullptr));

        label_4->setText(QApplication::translate("REVAOAttribEditorClass", "\345\220\257\347\224\250\346\230\240\345\260\204", nullptr));
        comboBox_map->setItemText(0, QApplication::translate("REVAOAttribEditorClass", "\345\205\263\351\227\255", nullptr));
        comboBox_map->setItemText(1, QApplication::translate("REVAOAttribEditorClass", "\345\220\257\347\224\250", nullptr));

        label_5->setText(QApplication::translate("REVAOAttribEditorClass", "\351\241\266\347\202\271\345\255\227\350\212\202\346\225\260", nullptr));
        label_6->setText(QApplication::translate("REVAOAttribEditorClass", "\345\201\217\347\247\273\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REVAOAttribEditorClass: public Ui_REVAOAttribEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVAOATTRIBEDITOR_H
