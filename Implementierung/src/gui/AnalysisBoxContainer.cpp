#include "AnalysisBoxContainer.h"

#include <vector>

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QString>
#include <QSpacerItem>
#include <QDebug>

#include "AnalysisBox.h"

GUI::AnalysisBoxContainer::AnalysisBoxContainer(QWidget* parent) : QFrame(parent) {
    createUi();
    setContentsMargins(-10,-10,-10,-10);
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
    resize(width(),boxes_.size()*newBox->height());
}

void GUI::AnalysisBoxContainer::createUi()
{
    v_boxes_=new QVBoxLayout;
    spacer_=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    v_boxes_->addSpacerItem(spacer_);
    v_boxes_->setSpacing(0);

    setLayout(v_boxes_);
}


