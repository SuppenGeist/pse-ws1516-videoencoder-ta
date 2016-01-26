/********************************************************************************
** Form generated from reading UI file 'analysisbox.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISBOX_H
#define UI_ANALYSISBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalysisBox
{
public:
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;

    void setupUi(QGroupBox *AnalysisBox)
    {
        if (AnalysisBox->objectName().isEmpty())
            AnalysisBox->setObjectName(QStringLiteral("AnalysisBox"));
        AnalysisBox->resize(914, 250);
        textEdit = new QTextEdit(AnalysisBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(250, 150, 361, 71));
        tabWidget = new QTabWidget(AnalysisBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(250, 30, 361, 101));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 361, 81));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 361, 81));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(AnalysisBox);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AnalysisBox);
    } // setupUi

    void retranslateUi(QGroupBox *AnalysisBox)
    {
        AnalysisBox->setWindowTitle(QApplication::translate("AnalysisBox", "GroupBox", 0));
        AnalysisBox->setTitle(QApplication::translate("AnalysisBox", "Video A", 0));
        label->setText(QApplication::translate("AnalysisBox", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AnalysisBox", "Tab 1", 0));
        label_2->setText(QApplication::translate("AnalysisBox", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AnalysisBox", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class AnalysisBox: public Ui_AnalysisBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISBOX_H
