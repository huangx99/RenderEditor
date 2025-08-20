/********************************************************************************
** Form generated from reading UI file 'RenderEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDEREDITOR_H
#define UI_RENDEREDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderEditorClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RenderEditorClass)
    {
        if (RenderEditorClass->objectName().isEmpty())
            RenderEditorClass->setObjectName(QString::fromUtf8("RenderEditorClass"));
        RenderEditorClass->resize(600, 400);
        centralWidget = new QWidget(RenderEditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RenderEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RenderEditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 29));
        RenderEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RenderEditorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RenderEditorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RenderEditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RenderEditorClass->setStatusBar(statusBar);

        retranslateUi(RenderEditorClass);

        QMetaObject::connectSlotsByName(RenderEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *RenderEditorClass)
    {
        RenderEditorClass->setWindowTitle(QApplication::translate("RenderEditorClass", "RenderEditor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderEditorClass: public Ui_RenderEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDEREDITOR_H
