/********************************************************************************
** Form generated from reading UI file 'REOpenGLControlWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REOPENGLCONTROLWIDGET_H
#define UI_REOPENGLCONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "REOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_REOpenGLControlWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    REOpenGLWidget *openGLWidget;

    void setupUi(QWidget *REOpenGLControlWidgetClass)
    {
        if (REOpenGLControlWidgetClass->objectName().isEmpty())
            REOpenGLControlWidgetClass->setObjectName(QString::fromUtf8("REOpenGLControlWidgetClass"));
        REOpenGLControlWidgetClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(REOpenGLControlWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        openGLWidget = new REOpenGLWidget(REOpenGLControlWidgetClass);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        verticalLayout->addWidget(openGLWidget);


        retranslateUi(REOpenGLControlWidgetClass);

        QMetaObject::connectSlotsByName(REOpenGLControlWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *REOpenGLControlWidgetClass)
    {
        REOpenGLControlWidgetClass->setWindowTitle(QApplication::translate("REOpenGLControlWidgetClass", "REOpenGLControlWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REOpenGLControlWidgetClass: public Ui_REOpenGLControlWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REOPENGLCONTROLWIDGET_H
