/********************************************************************************
** Form generated from reading UI file 'filtercontainertab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERCONTAINERTAB_H
#define UI_FILTERCONTAINERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FilterContainerTab
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *container;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *FilterContainerTab)
    {
        if (FilterContainerTab->objectName().isEmpty())
            FilterContainerTab->setObjectName(QStringLiteral("FilterContainerTab"));
        FilterContainerTab->resize(22, 200);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilterContainerTab->sizePolicy().hasHeightForWidth());
        FilterContainerTab->setSizePolicy(sizePolicy);
        FilterContainerTab->setMinimumSize(QSize(0, 200));
        FilterContainerTab->setMaximumSize(QSize(16777215, 200));
        FilterContainerTab->setBaseSize(QSize(0, 0));
        FilterContainerTab->setFrameShape(QFrame::StyledPanel);
        FilterContainerTab->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(FilterContainerTab);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        container = new QHBoxLayout();
        container->setObjectName(QStringLiteral("container"));

        horizontalLayout_2->addLayout(container);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        retranslateUi(FilterContainerTab);

        QMetaObject::connectSlotsByName(FilterContainerTab);
    } // setupUi

    void retranslateUi(QFrame *FilterContainerTab)
    {
        FilterContainerTab->setWindowTitle(QApplication::translate("FilterContainerTab", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterContainerTab: public Ui_FilterContainerTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERCONTAINERTAB_H
