/********************************************************************************
** Form generated from reading UI file 'exsistingfilters.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXSISTINGFILTERS_H
#define UI_EXSISTINGFILTERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExsistingFilters
{
public:
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QScrollArea *ExsistingFilters)
    {
        if (ExsistingFilters->objectName().isEmpty())
            ExsistingFilters->setObjectName(QStringLiteral("ExsistingFilters"));
        ExsistingFilters->resize(799, 206);
        ExsistingFilters->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ExsistingFilters->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 797, 187));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        ExsistingFilters->setWidget(scrollAreaWidgetContents);

        retranslateUi(ExsistingFilters);

        QMetaObject::connectSlotsByName(ExsistingFilters);
    } // setupUi

    void retranslateUi(QScrollArea *ExsistingFilters)
    {
        ExsistingFilters->setWindowTitle(QApplication::translate("ExsistingFilters", "ScrollArea", 0));
        textEdit->setHtml(QApplication::translate("ExsistingFilters", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">fgasgsdg</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class ExsistingFilters: public Ui_ExsistingFilters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXSISTINGFILTERS_H
