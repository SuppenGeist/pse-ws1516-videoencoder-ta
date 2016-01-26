/********************************************************************************
** Form generated from reading UI file 'analysisboxcontainer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISBOXCONTAINER_H
#define UI_ANALYSISBOXCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalysisBoxContainer
{
public:
    QWidget *scrollAreaWidgetContents;

    void setupUi(QScrollArea *AnalysisBoxContainer)
    {
        if (AnalysisBoxContainer->objectName().isEmpty())
            AnalysisBoxContainer->setObjectName(QStringLiteral("AnalysisBoxContainer"));
        AnalysisBoxContainer->resize(911, 491);
        AnalysisBoxContainer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        AnalysisBoxContainer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AnalysisBoxContainer->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 892, 489));
        AnalysisBoxContainer->setWidget(scrollAreaWidgetContents);

        retranslateUi(AnalysisBoxContainer);

        QMetaObject::connectSlotsByName(AnalysisBoxContainer);
    } // setupUi

    void retranslateUi(QScrollArea *AnalysisBoxContainer)
    {
        AnalysisBoxContainer->setWindowTitle(QApplication::translate("AnalysisBoxContainer", "ScrollArea", 0));
    } // retranslateUi

};

namespace Ui {
    class AnalysisBoxContainer: public Ui_AnalysisBoxContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISBOXCONTAINER_H
