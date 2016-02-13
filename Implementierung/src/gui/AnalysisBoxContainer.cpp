#include "AnalysisBoxContainer.h"

#include <vector>

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QString>
#include <QSpacerItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

#include "AnalysisBox.h"

GUI::AnalysisBoxContainer::AnalysisBoxContainer(QWidget* parent) : QFrame(parent) {
    createUi();
    setContentsMargins(-10,-10,-10,-10);

    setObjectName("anacontainer");
    setStyleSheet("QFrame#anacontainer {background-color:white;}");
}

void GUI::AnalysisBoxContainer::addVideo(QString path)
{
    AnalysisBox* newBox=new AnalysisBox;
    v_boxes_->removeItem(spacer_);
    v_boxes_->addWidget(newBox);
    boxes_.push_back(newBox);

    QString objname=QString("x%1").arg((quintptr)newBox,QT_POINTER_SIZE * 2, 16, QChar('0'));
    newBox->setObjectName(objname);

    if(boxes_.size()%2==0) {
        newBox->setStyleSheet("QFrame#"+objname+" {background-color:rgb(230,230,230);border-bottom-style:outset;border-bottom-color: black;border-bottom-width:1px;}");
    }else {
        newBox->setStyleSheet("QFrame#"+objname+" {background-color:rgb(250,250,250);border-bottom-style:outset;border-bottom-color: black;border-bottom-width:1px;}");
    }
    v_boxes_->addSpacerItem(spacer_);
    resize(width(),boxes_.size()*newBox->height()+65);
}

void GUI::AnalysisBoxContainer::clear()
{

}

void GUI::AnalysisBoxContainer::createUi()
{
    QVBoxLayout* v_content=new QVBoxLayout;
    v_boxes_=new QVBoxLayout;
    spacer_=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    v_boxes_->addSpacerItem(spacer_);
    v_boxes_->setSpacing(0);

    v_content->addLayout(v_boxes_);

    button_addVideo_=new QPushButton("Add video");

    QString stylesheet1("QPushButton {"
                                   "color: rgb(255, 255, 255);"
                                   "border-color: rgb(0, 0, 0);"
                                   "background: rgb(140, 140, 140);"
                                   "border-width: 1px;"
                                   "border-color:rgb(0, 0, 0);"
                                   "border-style: outset;"
                                   "border-radius: 7;"
                                   "padding: 3px;"
                                   "font-size: 18px;"
                                   "padding-left: 5px;"
                                   "padding-right: 5px;"
                                   "}"
                                   "QPushButton:pressed {"
                                   "background-color: rgb(69, 62, 62);"
                                   "border-style: inset;"
                                   "}"
                                  );
    button_addVideo_->setFlat(true);
    button_addVideo_->setStyleSheet(stylesheet1);
    v_content->addSpacing(10);

    QHBoxLayout* h_button=new QHBoxLayout;
    h_button->addSpacing(10);

    h_button->addWidget(button_addVideo_);
    h_button->addSpacing(20);

    v_content->addLayout(h_button);
    v_content->addSpacing(15);

    setLayout(v_content);
}


