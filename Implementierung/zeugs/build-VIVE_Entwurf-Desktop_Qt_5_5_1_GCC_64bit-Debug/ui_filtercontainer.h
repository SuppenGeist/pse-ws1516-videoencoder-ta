/********************************************************************************
** Form generated from reading UI file 'filtercontainer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCONTAINER_H
#define UI_FILTERCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterContainer
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *filterPng;
    QLabel *filterName;

    void setupUi(QFrame *FilterContainer)
    {
        if (FilterContainer->objectName().isEmpty())
            FilterContainer->setObjectName(QStringLiteral("FilterContainer"));
        FilterContainer->resize(200, 200);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilterContainer->sizePolicy().hasHeightForWidth());
        FilterContainer->setSizePolicy(sizePolicy);
        FilterContainer->setFrameShape(QFrame::StyledPanel);
        FilterContainer->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(FilterContainer);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 202, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        filterPng = new QLabel(verticalLayoutWidget);
        filterPng->setObjectName(QStringLiteral("filterPng"));
        sizePolicy.setHeightForWidth(filterPng->sizePolicy().hasHeightForWidth());
        filterPng->setSizePolicy(sizePolicy);
        filterPng->setMinimumSize(QSize(200, 150));
        filterPng->setMaximumSize(QSize(200, 150));
        filterPng->setPixmap(QPixmap(QString::fromUtf8(":/filterIcons/Picture/Filter_icons/blur_filter.png")));
        filterPng->setScaledContents(true);

        verticalLayout->addWidget(filterPng);

        filterName = new QLabel(verticalLayoutWidget);
        filterName->setObjectName(QStringLiteral("filterName"));

        verticalLayout->addWidget(filterName);


        retranslateUi(FilterContainer);

        QMetaObject::connectSlotsByName(FilterContainer);
    } // setupUi

    void retranslateUi(QFrame *FilterContainer)
    {
        FilterContainer->setWindowTitle(QApplication::translate("FilterContainer", "Frame", 0));
        filterPng->setText(QString());
        filterName->setText(QApplication::translate("FilterContainer", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterContainer: public Ui_FilterContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCONTAINER_H
