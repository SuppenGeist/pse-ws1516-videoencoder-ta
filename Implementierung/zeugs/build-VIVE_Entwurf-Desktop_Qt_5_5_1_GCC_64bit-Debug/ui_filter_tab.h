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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "Gui_Elements/exsistingfilters.h"
#include "Gui_Elements/optionbuttonmenu.h"
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
    ExsistingFilters *filterScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QWidget *artefacts;
    ExsistingFilters *artefactsScrollArea;
    QWidget *scrollAreaWidgetContents_3;

    void setupUi(QFrame *Filter_tab)
    {
        if (Filter_tab->objectName().isEmpty())
            Filter_tab->setObjectName(QStringLiteral("Filter_tab"));
        Filter_tab->resize(941, 881);
        Filter_tab->setFrameShape(QFrame::StyledPanel);
        Filter_tab->setFrameShadow(QFrame::Raised);
        videoPlayerOverview = new VideoPlayerOverview(Filter_tab);
        videoPlayerOverview->setObjectName(QStringLiteral("videoPlayerOverview"));
        videoPlayerOverview->setGeometry(QRect(510, 480, 401, 111));
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
        filterScrollArea = new ExsistingFilters(filters);
        filterScrollArea->setObjectName(QStringLiteral("filterScrollArea"));
        filterScrollArea->setGeometry(QRect(0, 0, 921, 201));
        sizePolicy.setHeightForWidth(filterScrollArea->sizePolicy().hasHeightForWidth());
        filterScrollArea->setSizePolicy(sizePolicy);
        filterScrollArea->setMinimumSize(QSize(921, 201));
        filterScrollArea->setMaximumSize(QSize(921, 201));
        filterScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 919, 199));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filterScrollArea->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(filters, QString());
        artefacts = new QWidget();
        artefacts->setObjectName(QStringLiteral("artefacts"));
        artefactsScrollArea = new ExsistingFilters(artefacts);
        artefactsScrollArea->setObjectName(QStringLiteral("artefactsScrollArea"));
        artefactsScrollArea->setGeometry(QRect(0, 0, 921, 201));
        artefactsScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
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
