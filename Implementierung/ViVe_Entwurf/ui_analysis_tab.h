/********************************************************************************
** Form generated from reading UI file 'analysis_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSIS_TAB_H
#define UI_ANALYSIS_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "Gui_Elements/analysisbox.h"
#include "Gui_Elements/analysisboxcontainer.h"
#include "Gui_Elements/videoplayeroverview.h"

QT_BEGIN_NAMESPACE

class Ui_Analysis_Tab
{
public:
    QFrame *optionsContainer;
    QComboBox *comboBox_2;
    QPushButton *pushButton_20;
    VideoPlayerOverview *frame;
    AnalysisBox *frame1;
    AnalysisBoxContainer *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QFrame *Analysis_Tab)
    {
        if (Analysis_Tab->objectName().isEmpty())
            Analysis_Tab->setObjectName(QStringLiteral("Analysis_Tab"));
        Analysis_Tab->resize(941, 881);
        Analysis_Tab->setFrameShape(QFrame::StyledPanel);
        Analysis_Tab->setFrameShadow(QFrame::Raised);
        optionsContainer = new QFrame(Analysis_Tab);
        optionsContainer->setObjectName(QStringLiteral("optionsContainer"));
        optionsContainer->setGeometry(QRect(20, 270, 901, 101));
        optionsContainer->setStyleSheet(QStringLiteral("background-color: rgb(181, 181, 181);"));
        optionsContainer->setFrameShape(QFrame::StyledPanel);
        optionsContainer->setFrameShadow(QFrame::Raised);
        comboBox_2 = new QComboBox(optionsContainer);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(710, 70, 180, 22));
        QFont font;
        font.setPointSize(12);
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QLatin1String("background-color: rgb(116, 116, 116);\n"
"color: rgb(255, 255, 255);"));
        pushButton_20 = new QPushButton(optionsContainer);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(30, 40, 220, 31));
        pushButton_20->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-color: rgb(69, 62, 62);\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c);\n"
"	background: rgb(115, 115, 115);\n"
"	border-width: 1px;\n"
"	border-color:rgb(255, 255, 255);\n"
"	border-style: outset;\n"
"	border-radius: 7;\n"
"	padding: 3px;\n"
"	font-size: 18px;\n"
"	min-width: 8em;\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));
        frame = new VideoPlayerOverview(optionsContainer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(300, 10, 401, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame1 = new AnalysisBox(Analysis_Tab);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setGeometry(QRect(20, 20, 871, 241));
        scrollArea = new AnalysisBoxContainer(Analysis_Tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 380, 911, 491));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 909, 489));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Analysis_Tab);

        QMetaObject::connectSlotsByName(Analysis_Tab);
    } // setupUi

    void retranslateUi(QFrame *Analysis_Tab)
    {
        Analysis_Tab->setWindowTitle(QApplication::translate("Analysis_Tab", "Frame", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Analysis_Tab", "RGB difference", 0)
         << QApplication::translate("Analysis_Tab", "Macroblocks", 0)
        );
        pushButton_20->setText(QApplication::translate("Analysis_Tab", "Save results", 0));
    } // retranslateUi

};

namespace Ui {
    class Analysis_Tab: public Ui_Analysis_Tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSIS_TAB_H
