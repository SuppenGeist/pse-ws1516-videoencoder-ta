#include "AnalysisTab.h"

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QFont>
#include <QSpacerItem>
#include <QScrollArea>

#include "PlayerControlPanel.h"
#include "GraphWidget.h"
#include "AnalysisBoxContainer.h"

GUI::AnalysisTab::AnalysisTab(QWidget* parent) : QFrame(parent) {
    createUi();
    connectActions();

    analysisBoxContainer_->addVideo("Test");
    analysisBoxContainer_->addVideo("Test");
}

void GUI::AnalysisTab::resizeEvent(QResizeEvent *event)
{
    if(event->size().width()>1300) {
        //button_addencodedvideo->resize(1300,button_addencodedvideo->height());
        analysisBoxContainer_->setFixedWidth(1280);
    }
    else {
        //button_addencodedvideo->resize(event->size().width(),button_addencodedvideo->height());
        analysisBoxContainer_->setFixedWidth(event->size().width()-56);
    }
}

void GUI::AnalysisTab::createUi()
{
    button_saveResults_=new QPushButton("Save results");
    button_addRawVideo_=new QPushButton("Load video");
    button_attributes_=new QPushButton("Attributes");
    button_bitrate_=new QPushButton("Bitrate");
    button_blueHistogramm_=new QPushButton("Blue histogramm");
    button_greenHistogramm_=new QPushButton("Green histogramm");
    button_redHistogramm_=new QPushButton("Red histogramm");
    button_psnr_=new QPushButton("PSNR");
    button_addencodedvideo=new QPushButton("Add video");

    button_saveResults_->setFlat(true);
    button_attributes_->setFlat(true);
    button_bitrate_->setFlat(true);
    button_blueHistogramm_->setFlat(true);
    button_greenHistogramm_->setFlat(true);
    button_redHistogramm_->setFlat(true);
    button_psnr_->setFlat(true);

    QString stylesheet("QPushButton {"
                       "color: rgb(0, 0, 0);"
                       "background: rgb(220, 220, 220);"
                       "border-width: 1px;"
                       "border-color:rgb(0, 0, 0);"
                       "border-style: outset;"
                       "border-radius: 7px;"
                       "font-size: 12px;"
                       "}"
                       "QPushButton:pressed {"
                       "background-color: rgb(200, 200, 200);"
                       "border-style: inset;"
                       "}"
                      );

    button_attributes_->setStyleSheet(stylesheet);
    button_bitrate_->setStyleSheet(stylesheet);
    button_blueHistogramm_->setStyleSheet(stylesheet);
    button_greenHistogramm_->setStyleSheet(stylesheet);
    button_redHistogramm_->setStyleSheet(stylesheet);
    button_psnr_->setStyleSheet(stylesheet);

    button_attributes_->setFixedSize(120,25);
    button_bitrate_->setFixedSize(120,25);
    button_blueHistogramm_->setFixedSize(120,25);
    button_greenHistogramm_->setFixedSize(120,25);
    button_redHistogramm_->setFixedSize(120,25);
    button_psnr_->setFixedSize(120,25);

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
    button_saveResults_->setStyleSheet(stylesheet1);
    button_saveResults_->setFixedWidth(170);

    button_addRawVideo_->setFixedSize(200,200);
    QFont f("Arial",13);
    button_addRawVideo_->setFont(f);
    button_addRawVideo_->setStyleSheet("QPushButton {"
                                       "border-color:black;"
                                       "border-width:1px;"
                                       "background-color: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 white, stop: 0.5 #bbbbbb, stop: 0.8 #999999);"
                                       "border-style:outset;"
                                       "}"
                                       "QPushButton:pressed {"
                                       "background-color: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 white, stop: 0.5 #aaaaaa, stop: 0.8 #777777);"
                                       "border-style: inset;"
                                       "}");

    button_addencodedvideo->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    button_addencodedvideo->setFlat(true);
    button_addencodedvideo->setStyleSheet(stylesheet1);

    playerControlPanel_=new PlayerControlPanel;

    tabs_graphattrs=new QTabWidget;
    tabs_graphattrs->setTabPosition(QTabWidget::West);

    graphWidget_=new GraphWidget;
    tabs_graphattrs->addTab(graphWidget_,"Graphs");

    QWidget* attributes=new QWidget;
    tabs_graphattrs->addTab(attributes,"Attributes");


    playerControlPanel_->setStyleSheet("QFrame#playerPanel {"
                  "background: rgb(200, 200, 200);"
                  "}"
                  "");

    combobbox_anaVideo_=new QComboBox;
    combobbox_anaVideo_->addItem("Macroblocks");
    combobbox_anaVideo_->addItem("RGB difference");
    combobbox_anaVideo_->setFixedWidth(150);
    combobbox_anaVideo_->setStyleSheet("QComboBox {"
                                       "background-color:rgb(210,210,210);"
                                       "}");

    QVBoxLayout* v_content=new QVBoxLayout;

    QHBoxLayout* h_rawc=new QHBoxLayout;
    QSpacerItem* spacer5=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);
    h_rawc->addSpacerItem(spacer5);

    QWidget* rawVideoArea=new QWidget;
    rawVideoArea->setFixedHeight(210);
    rawVideoArea->setMaximumWidth(1100);
    QHBoxLayout* h_rawVideoArea=new QHBoxLayout;

    v_rawVideo_=new QVBoxLayout;
    v_rawVideo_->addWidget(button_addRawVideo_);

    h_rawVideoArea->addLayout(v_rawVideo_);

    h_rawVideoArea->addSpacing(20);
    h_rawVideoArea->addWidget(tabs_graphattrs);

    QVBoxLayout* v_buttongrp=new QVBoxLayout;
    v_buttongrp->addWidget(button_attributes_);
    v_buttongrp->addWidget(button_redHistogramm_);
    v_buttongrp->addWidget(button_greenHistogramm_);
    v_buttongrp->addWidget(button_blueHistogramm_);
    v_buttongrp->addWidget(button_psnr_);
    v_buttongrp->addWidget(button_bitrate_);

    h_rawVideoArea->addSpacing(20);
    h_rawVideoArea->addLayout(v_buttongrp);

    rawVideoArea->setLayout(h_rawVideoArea);

    h_rawc->addWidget(rawVideoArea,1);

    QSpacerItem* spacer6=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);
    h_rawc->addSpacerItem(spacer6);

    v_content->addLayout(h_rawc);
    v_content->addSpacing(10);

    QWidget* controlArea=new QWidget;
    controlArea->setFixedHeight(90);
    controlArea->setObjectName("controlArea");
    controlArea->setStyleSheet("QWidget#controlArea {"
                               "background-color:rgb(200,200,200);"
                               "border-width:1px;"
                               "border-color:black;"
                               "border-style:outset;"
                               "border-radius:5px;"
                               "}");
    QHBoxLayout* h_controlArea=new QHBoxLayout;

    QWidget*    saveresults=new QWidget;
    QHBoxLayout* h_saveresults=new QHBoxLayout;

    QSpacerItem* spacer=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    h_saveresults->addSpacerItem(spacer);
    h_saveresults->addWidget(button_saveResults_);
    QSpacerItem* spacer1=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    h_saveresults->addSpacerItem(spacer1);

    saveresults->setLayout(h_saveresults);
    h_controlArea->addWidget(saveresults);

    h_controlArea->addWidget(playerControlPanel_);

    QWidget* videoChooser=new QWidget;
    QHBoxLayout* h_videoChooser=new QHBoxLayout;

    QSpacerItem* spacer2=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    QSpacerItem* spacer8=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);

    h_videoChooser->addSpacerItem(spacer8);

    h_videoChooser->addWidget(combobbox_anaVideo_);

    h_videoChooser->addSpacerItem(spacer2);

    videoChooser->setLayout(h_videoChooser);

    h_controlArea->addWidget(videoChooser);

    controlArea->setLayout(h_controlArea);

    v_content->addWidget(controlArea);


    QWidget* analysisBoxes=new QWidget;
    analysisBoxes->setContentsMargins(0,0,0,-5);

    QHBoxLayout* h_anaboxes=new QHBoxLayout;
    QSpacerItem* spacer4=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    h_anaboxes->addSpacerItem(spacer4);

    analysisBoxContainer_=new AnalysisBoxContainer;

    QWidget* scrollbutton=new QWidget;
    QVBoxLayout* v_scrollbutton=new QVBoxLayout;

    scroll_anaBoxes_=new QScrollArea;
    scroll_anaBoxes_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scroll_anaBoxes_->setWidget(analysisBoxContainer_);
    scroll_anaBoxes_->setStyleSheet("QScrollArea {"
                                    "border-width:1px;"
                                    "border-color:black;"
                                    "border-style:outset;"
                                    "background-color:white;"
                                    "}");
    v_scrollbutton->addWidget(scroll_anaBoxes_);
    scrollbutton->setMaximumWidth(1300);
    v_scrollbutton->addWidget(button_addencodedvideo);

    scrollbutton->setLayout(v_scrollbutton);
    h_anaboxes->addWidget(scrollbutton,1);

    QSpacerItem* spacer7=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    h_anaboxes->addSpacerItem(spacer7);

    analysisBoxes->setLayout(h_anaboxes);
    v_content->addWidget(analysisBoxes);

    setContentsMargins(0,-10,0,-20);
    setLayout(v_content);
}

void GUI::AnalysisTab::connectActions()
{

}

