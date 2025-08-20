/********************************************************************************
** Form generated from reading UI file 'REVec3Editor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVEC3EDITOR_H
#define UI_REVEC3EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_REVec3EditorClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_x;
    QLabel *label_red;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_y;
    QLabel *label_green;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_z;
    QLabel *label_blue;

    void setupUi(QWidget *REVec3EditorClass)
    {
        if (REVec3EditorClass->objectName().isEmpty())
            REVec3EditorClass->setObjectName(QString::fromUtf8("REVec3EditorClass"));
        REVec3EditorClass->resize(452, 365);
        verticalLayout = new QVBoxLayout(REVec3EditorClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(REVec3EditorClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_x = new QDoubleSpinBox(REVec3EditorClass);
        doubleSpinBox_x->setObjectName(QString::fromUtf8("doubleSpinBox_x"));
        doubleSpinBox_x->setMinimum(-999999999999999.000000000000000);
        doubleSpinBox_x->setMaximum(100000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_x, 0, 1, 1, 1);

        label_red = new QLabel(REVec3EditorClass);
        label_red->setObjectName(QString::fromUtf8("label_red"));

        gridLayout->addWidget(label_red, 0, 2, 1, 1);

        label_2 = new QLabel(REVec3EditorClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBox_y = new QDoubleSpinBox(REVec3EditorClass);
        doubleSpinBox_y->setObjectName(QString::fromUtf8("doubleSpinBox_y"));
        doubleSpinBox_y->setMinimum(-1000000000000000000.000000000000000);
        doubleSpinBox_y->setMaximum(1000000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_y, 1, 1, 1, 1);

        label_green = new QLabel(REVec3EditorClass);
        label_green->setObjectName(QString::fromUtf8("label_green"));

        gridLayout->addWidget(label_green, 1, 2, 1, 1);

        label_3 = new QLabel(REVec3EditorClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        doubleSpinBox_z = new QDoubleSpinBox(REVec3EditorClass);
        doubleSpinBox_z->setObjectName(QString::fromUtf8("doubleSpinBox_z"));
        doubleSpinBox_z->setMinimum(-1000000000000000000000.000000000000000);
        doubleSpinBox_z->setMaximum(10000000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_z, 2, 1, 1, 1);

        label_blue = new QLabel(REVec3EditorClass);
        label_blue->setObjectName(QString::fromUtf8("label_blue"));

        gridLayout->addWidget(label_blue, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(REVec3EditorClass);

        QMetaObject::connectSlotsByName(REVec3EditorClass);
    } // setupUi

    void retranslateUi(QWidget *REVec3EditorClass)
    {
        REVec3EditorClass->setWindowTitle(QApplication::translate("REVec3EditorClass", "REVec3Editor", nullptr));
        label->setText(QApplication::translate("REVec3EditorClass", "x", nullptr));
        label_red->setText(QString());
        label_2->setText(QApplication::translate("REVec3EditorClass", "y", nullptr));
        label_green->setText(QString());
        label_3->setText(QApplication::translate("REVec3EditorClass", "z", nullptr));
        label_blue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class REVec3EditorClass: public Ui_REVec3EditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVEC3EDITOR_H
