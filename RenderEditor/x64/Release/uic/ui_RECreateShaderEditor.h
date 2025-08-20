/********************************************************************************
** Form generated from reading UI file 'RECreateShaderEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECREATESHADEREDITOR_H
#define UI_RECREATESHADEREDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RECreateShaderEditorClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_vertexPath;
    QPushButton *pushButton_vertexPath;
    QLabel *label_2;
    QLineEdit *lineEdit_fragmentPath;
    QPushButton *pushButton_fragmentPath;

    void setupUi(QWidget *RECreateShaderEditorClass)
    {
        if (RECreateShaderEditorClass->objectName().isEmpty())
            RECreateShaderEditorClass->setObjectName(QString::fromUtf8("RECreateShaderEditorClass"));
        RECreateShaderEditorClass->resize(600, 400);
        gridLayout = new QGridLayout(RECreateShaderEditorClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RECreateShaderEditorClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_vertexPath = new QLineEdit(RECreateShaderEditorClass);
        lineEdit_vertexPath->setObjectName(QString::fromUtf8("lineEdit_vertexPath"));

        gridLayout->addWidget(lineEdit_vertexPath, 0, 1, 1, 1);

        pushButton_vertexPath = new QPushButton(RECreateShaderEditorClass);
        pushButton_vertexPath->setObjectName(QString::fromUtf8("pushButton_vertexPath"));
        pushButton_vertexPath->setMinimumSize(QSize(35, 30));
        pushButton_vertexPath->setMaximumSize(QSize(35, 30));

        gridLayout->addWidget(pushButton_vertexPath, 0, 2, 1, 1);

        label_2 = new QLabel(RECreateShaderEditorClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_fragmentPath = new QLineEdit(RECreateShaderEditorClass);
        lineEdit_fragmentPath->setObjectName(QString::fromUtf8("lineEdit_fragmentPath"));

        gridLayout->addWidget(lineEdit_fragmentPath, 1, 1, 1, 1);

        pushButton_fragmentPath = new QPushButton(RECreateShaderEditorClass);
        pushButton_fragmentPath->setObjectName(QString::fromUtf8("pushButton_fragmentPath"));
        pushButton_fragmentPath->setMinimumSize(QSize(35, 30));
        pushButton_fragmentPath->setMaximumSize(QSize(35, 30));

        gridLayout->addWidget(pushButton_fragmentPath, 1, 2, 1, 1);


        retranslateUi(RECreateShaderEditorClass);

        QMetaObject::connectSlotsByName(RECreateShaderEditorClass);
    } // setupUi

    void retranslateUi(QWidget *RECreateShaderEditorClass)
    {
        RECreateShaderEditorClass->setWindowTitle(QApplication::translate("RECreateShaderEditorClass", "RECreateShaderEditor", nullptr));
        label->setText(QApplication::translate("RECreateShaderEditorClass", "\351\241\266\347\202\271\347\235\200\350\211\262\345\231\250", nullptr));
        pushButton_vertexPath->setText(QApplication::translate("RECreateShaderEditorClass", "...", nullptr));
        label_2->setText(QApplication::translate("RECreateShaderEditorClass", "\347\211\207\346\256\265\347\235\200\350\211\262\345\231\250", nullptr));
        pushButton_fragmentPath->setText(QApplication::translate("RECreateShaderEditorClass", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECreateShaderEditorClass: public Ui_RECreateShaderEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECREATESHADEREDITOR_H
