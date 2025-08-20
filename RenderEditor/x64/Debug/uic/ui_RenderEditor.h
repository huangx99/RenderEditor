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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderEditorClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *nodeEdit;
    QHBoxLayout *horizontalLayout_2;
    QWidget *openglWidget;
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
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        nodeEdit = new QWidget();
        nodeEdit->setObjectName(QString::fromUtf8("nodeEdit"));
        horizontalLayout_2 = new QHBoxLayout(nodeEdit);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(nodeEdit, QString());
        openglWidget = new QWidget();
        openglWidget->setObjectName(QString::fromUtf8("openglWidget"));
        tabWidget->addTab(openglWidget, QString());

        horizontalLayout->addWidget(tabWidget);

        RenderEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RenderEditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        RenderEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RenderEditorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RenderEditorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RenderEditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RenderEditorClass->setStatusBar(statusBar);

        retranslateUi(RenderEditorClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RenderEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *RenderEditorClass)
    {
        RenderEditorClass->setWindowTitle(QApplication::translate("RenderEditorClass", "RenderEditor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(nodeEdit), QApplication::translate("RenderEditorClass", "\350\212\202\347\202\271\347\274\226\350\276\221\345\231\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(openglWidget), QApplication::translate("RenderEditorClass", "  \346\270\262\346\237\223\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderEditorClass: public Ui_RenderEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDEREDITOR_H
