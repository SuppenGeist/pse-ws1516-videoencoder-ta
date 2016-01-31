/********************************************************************************
** Form generated from reading UI file 'filtertab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERTAB_H
#define UI_FILTERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterTab
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QScrollArea *scrollAreaFilters;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_2;
    QScrollArea *scrollAreaArtefacts;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *videoPlayer;
    QWidget *panel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *up;
    QPushButton *down;
    QPushButton *remove;
    QSpacerItem *verticalSpacer;
    QPushButton *loadVideo;
    QPushButton *apply;
    QPushButton *saveVideo;
    QSpacerItem *verticalSpacer_2;
    QPushButton *loadConfig;
    QPushButton *saveConfig;
    QSpacerItem *verticalSpacer_3;
    QPushButton *reset;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QFrame *frame;

    void setupUi(QFrame *FilterTab)
    {
        if (FilterTab->objectName().isEmpty())
            FilterTab->setObjectName(QStringLiteral("FilterTab"));
        FilterTab->resize(941, 891);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilterTab->sizePolicy().hasHeightForWidth());
        FilterTab->setSizePolicy(sizePolicy);
        FilterTab->setMinimumSize(QSize(941, 891));
        FilterTab->setMaximumSize(QSize(941, 891));
        QFont font;
        font.setPointSize(12);
        FilterTab->setFont(font);
        FilterTab->setFrameShape(QFrame::StyledPanel);
        FilterTab->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(FilterTab);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 640, 921, 241));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        scrollAreaFilters = new QScrollArea(tab);
        scrollAreaFilters->setObjectName(QStringLiteral("scrollAreaFilters"));
        scrollAreaFilters->setGeometry(QRect(0, 0, 921, 210));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaFilters->sizePolicy().hasHeightForWidth());
        scrollAreaFilters->setSizePolicy(sizePolicy1);
        scrollAreaFilters->setMinimumSize(QSize(0, 210));
        scrollAreaFilters->setMaximumSize(QSize(921, 210));
        scrollAreaFilters->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaFilters->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaFilters->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollAreaFilters->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 919, 191));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaFilters->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        scrollAreaArtefacts = new QScrollArea(tab_2);
        scrollAreaArtefacts->setObjectName(QStringLiteral("scrollAreaArtefacts"));
        scrollAreaArtefacts->setGeometry(QRect(0, 0, 921, 210));
        sizePolicy1.setHeightForWidth(scrollAreaArtefacts->sizePolicy().hasHeightForWidth());
        scrollAreaArtefacts->setSizePolicy(sizePolicy1);
        scrollAreaArtefacts->setMinimumSize(QSize(0, 210));
        scrollAreaArtefacts->setMaximumSize(QSize(921, 210));
        scrollAreaArtefacts->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaArtefacts->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollAreaArtefacts->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollAreaArtefacts->setWidgetResizable(true);
        scrollAreaArtefacts->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 919, 191));
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy2);
        scrollAreaArtefacts->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab_2, QString());
        videoPlayer = new QWidget(FilterTab);
        videoPlayer->setObjectName(QStringLiteral("videoPlayer"));
        videoPlayer->setGeometry(QRect(460, 20, 461, 371));
        panel = new QWidget(FilterTab);
        panel->setObjectName(QStringLiteral("panel"));
        panel->setGeometry(QRect(460, 500, 461, 91));
        verticalLayoutWidget = new QWidget(FilterTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(250, 10, 201, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        up = new QPushButton(verticalLayoutWidget);
        up->setObjectName(QStringLiteral("up"));
        up->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(up);

        down = new QPushButton(verticalLayoutWidget);
        down->setObjectName(QStringLiteral("down"));
        down->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(down);

        remove = new QPushButton(verticalLayoutWidget);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(remove);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        loadVideo = new QPushButton(verticalLayoutWidget);
        loadVideo->setObjectName(QStringLiteral("loadVideo"));
        loadVideo->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(loadVideo);

        apply = new QPushButton(verticalLayoutWidget);
        apply->setObjectName(QStringLiteral("apply"));
        apply->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(apply);

        saveVideo = new QPushButton(verticalLayoutWidget);
        saveVideo->setObjectName(QStringLiteral("saveVideo"));
        saveVideo->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(saveVideo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        loadConfig = new QPushButton(verticalLayoutWidget);
        loadConfig->setObjectName(QStringLiteral("loadConfig"));
        loadConfig->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(loadConfig);

        saveConfig = new QPushButton(verticalLayoutWidget);
        saveConfig->setObjectName(QStringLiteral("saveConfig"));
        saveConfig->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(saveConfig);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        reset = new QPushButton(verticalLayoutWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setStyleSheet(QLatin1String("QPushButton {\n"
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
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgb(69, 62, 62);\n"
"	border-style: inset;\n"
"}"));

        verticalLayout->addWidget(reset);

        listWidget = new QListWidget(FilterTab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 231, 581));
        groupBox = new QGroupBox(FilterTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(250, 380, 201, 211));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 20, 201, 191));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(FilterTab);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FilterTab);
    } // setupUi

    void retranslateUi(QFrame *FilterTab)
    {
        FilterTab->setWindowTitle(QApplication::translate("FilterTab", "Frame", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FilterTab", "Filters", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FilterTab", "Artefacts", 0));
        up->setText(QApplication::translate("FilterTab", "Up", 0));
        down->setText(QApplication::translate("FilterTab", "Down", 0));
        remove->setText(QApplication::translate("FilterTab", "Remove", 0));
        loadVideo->setText(QApplication::translate("FilterTab", "Load video", 0));
        apply->setText(QApplication::translate("FilterTab", "Apply to video", 0));
        saveVideo->setText(QApplication::translate("FilterTab", "Save video", 0));
        loadConfig->setText(QApplication::translate("FilterTab", "Load configuration", 0));
        saveConfig->setText(QApplication::translate("FilterTab", "Save configuration", 0));
        reset->setText(QApplication::translate("FilterTab", "Reset", 0));
        groupBox->setTitle(QApplication::translate("FilterTab", "Filter/Artefact options:", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterTab: public Ui_FilterTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERTAB_H
