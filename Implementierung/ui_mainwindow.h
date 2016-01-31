/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionLoad;
    QAction *actionNew;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralwidget;
    QTabWidget *tab_tabs;
    QWidget *Filtersandartefacts;
    QWidget *filterTab;
    QWidget *videoandanalysis;
    QMenuBar *menubar;
    QMenu *menuProject;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(955, 955);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tab_tabs = new QTabWidget(centralwidget);
        tab_tabs->setObjectName(QStringLiteral("tab_tabs"));
        tab_tabs->setGeometry(QRect(0, 0, 950, 920));
        tab_tabs->setMinimumSize(QSize(950, 920));
        tab_tabs->setMaximumSize(QSize(950, 920));
        QFont font;
        font.setPointSize(12);
        tab_tabs->setFont(font);
        Filtersandartefacts = new QWidget();
        Filtersandartefacts->setObjectName(QStringLiteral("Filtersandartefacts"));
        filterTab = new QWidget(Filtersandartefacts);
        filterTab->setObjectName(QStringLiteral("filterTab"));
        filterTab->setGeometry(QRect(0, 0, 951, 881));
        tab_tabs->addTab(Filtersandartefacts, QString());
        videoandanalysis = new QWidget();
        videoandanalysis->setObjectName(QStringLiteral("videoandanalysis"));
        tab_tabs->addTab(videoandanalysis, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 955, 23));
        QFont font1;
        font1.setPointSize(10);
        menubar->setFont(font1);
        menuProject = new QMenu(menubar);
        menuProject->setObjectName(QStringLiteral("menuProject"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuProject->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuProject->addAction(actionSave);
        menuProject->addAction(actionSaveAs);
        menuProject->addAction(actionLoad);
        menuProject->addAction(actionNew);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);

        tab_tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "SaveAs", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        tab_tabs->setTabText(tab_tabs->indexOf(Filtersandartefacts), QApplication::translate("MainWindow", "Filters and artefacts", 0));
        tab_tabs->setTabText(tab_tabs->indexOf(videoandanalysis), QApplication::translate("MainWindow", "Video and analysis", 0));
        menuProject->setTitle(QApplication::translate("MainWindow", "Project", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
