/********************************************************************************
** Form generated from reading UI file 'pickablefilters.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKABLEFILTERS_H
#define UI_PICKABLEFILTERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PickableFilters
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *PickableFilters)
    {
        if (PickableFilters->objectName().isEmpty())
            PickableFilters->setObjectName(QStringLiteral("PickableFilters"));
        PickableFilters->resize(174, 41);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PickableFilters->sizePolicy().hasHeightForWidth());
        PickableFilters->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(PickableFilters);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        retranslateUi(PickableFilters);

        QMetaObject::connectSlotsByName(PickableFilters);
    } // setupUi

    void retranslateUi(QWidget *PickableFilters)
    {
        PickableFilters->setWindowTitle(QApplication::translate("PickableFilters", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class PickableFilters: public Ui_PickableFilters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKABLEFILTERS_H
