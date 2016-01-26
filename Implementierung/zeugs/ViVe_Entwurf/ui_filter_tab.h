/********************************************************************************
** Form generated from reading UI file 'filter_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_TAB_H
#define UI_FILTER_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "Gui_Elements/optionbuttonmenu.h"
#include "Gui_Elements/pickablefilters.h"
#include "Gui_Elements/videoplayeroverview.h"

QT_BEGIN_NAMESPACE

class Ui_Filter_tab
{
public:
    VideoPlayerOverview *videoPlayerOverview;
    QListWidget *selectedFilterList;
    OptionButtonMenu *optionButtonMenu;
    QTabWidget *tabWidget;
    QWidget *filters;
    QScrollArea *artefactsScrollArea_2;
    PickableFilters *scrollAreaWidgetContents_4;
    QWidget *artefacts;
    QScrollArea *artefactsScrollArea;
    PickableFilters *scrollAreaWidgetContents_3;

    void setupUi(QFrame *Filter_tab)
    {
        if (Filter_tab->objectName().isEmpty())
            Filter_tab->setObjectName(QStringLiteral("Filter_tab"));
        Filter_tab->resize(941, 881);
        Filter_tab->setFrameShape(QFrame::StyledPanel);
        Filter_tab->setFrameShadow(QFrame::Raised);
        videoPlayerOverview = new VideoPlayerOverview(Filter_tab);
        videoPlayerOverview->setObjectName(QStringLiteral("videoPlayerOverview"));
        videoPlayerOverview->setGeometry(QRect(520, 510, 411, 111));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoPlayerOverview->sizePolicy().hasHeightForWidth());
        videoPlayerOverview->setSizePolicy(sizePolicy);
        videoPlayerOverview->setFrameShape(QFrame::StyledPanel);
        videoPlayerOverview->setFrameShadow(QFrame::Raised);
        selectedFilterList = new QListWidget(Filter_tab);
        selectedFilterList->setObjectName(QStringLiteral("selectedFilterList"));
        selectedFilterList->setGeometry(QRect(10, 10, 241, 621));
        QFont font;
        font.setPointSize(12);
        selectedFilterList->setFont(font);
        selectedFilterList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        optionButtonMenu = new OptionButtonMenu(Filter_tab);
        optionButtonMenu->setObjectName(QStringLiteral("optionButtonMenu"));
        optionButtonMenu->setGeometry(QRect(270, 10, 246, 402));
        optionButtonMenu->setFrameShape(QFrame::StyledPanel);
        optionButtonMenu->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(Filter_tab);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 640, 921, 231));
        tabWidget->setFont(font);
        filters = new QWidget();
        filters->setObjectName(QStringLiteral("filters"));
        artefactsScrollArea_2 = new QScrollArea(filters);
        artefactsScrollArea_2->setObjectName(QStringLiteral("artefactsScrollArea_2"));
        artefactsScrollArea_2->setGeometry(QRect(0, 0, 921, 201));
        artefactsScrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        artefactsScrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new PickableFilters();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 919, 199));
        artefactsScrollArea_2->setWidget(scrollAreaWidgetContents_4);
        tabWidget->addTab(filters, QString());
        artefacts = new QWidget();
        artefacts->setObjectName(QStringLiteral("artefacts"));
        artefactsScrollArea = new QScrollArea(artefacts);
        artefactsScrollArea->setObjectName(QStringLiteral("artefactsScrollArea"));
        artefactsScrollArea->setGeometry(QRect(0, 0, 921, 201));
        artefactsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        artefactsScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new PickableFilters();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 919, 199));
        artefactsScrollArea->setWidget(scrollAreaWidgetContents_3);
        tabWidget->addTab(artefacts, QString());

        retranslateUi(Filter_tab);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Filter_tab);
    } // setupUi

    void retranslateUi(QFrame *Filter_tab)
    {
        Filter_tab->setWindowTitle(QApplication::translate("Filter_tab", "Frame", 0));
        tabWidget->setTabText(tabWidget->indexOf(filters), QApplication::translate("Filter_tab", "Filters", 0));
        tabWidget->setTabText(tabWidget->indexOf(artefacts), QApplication::translate("Filter_tab", "Artefacts", 0));
    } // retranslateUi

};

namespace Ui {
    class Filter_tab: public Ui_Filter_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_TAB_H
