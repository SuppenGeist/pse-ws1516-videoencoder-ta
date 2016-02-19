#include "AnalysisTab.h"

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QVBoxLayout>
#include <QFont>
#include <QSpacerItem>
#include <QScrollArea>

#include "PlayerControlPanel.h"
#include "GraphWidget.h"
#include "AnalysisBoxContainer.h"
#include "YuvFileOpenDialog.h"
#include "YuvInfoDialog.h"
#include "ForwardPlayer.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "GlobalControlPanel.h"

#include "../memento/AnalysisTabMemento.h"

#include "../model/YuvVideo.h"

#include "../undo_framework/UndoStack.h"
#include "../undo_framework/LoadAnalysisVideo.h"

GUI::AnalysisTab::AnalysisTab(QWidget* parent) : QFrame(parent),rawVideo_(nullptr) {
	createUi();
	connectActions();

	forwardPlayer_=std::make_unique<ForwardPlayer>();
	globalControlPanel_=std::make_shared<GlobalControlPanel>();
	videoPlayer_=std::make_unique<VideoPlayer>();
	timer_=std::make_shared<Timer>();

	forwardPlayer_->setMasterVideoPlayer(videoPlayer_.get());
	videoPlayer_->setTimer(timer_);
	videoPlayer_->addView(*rawVideoView_);
	videoPlayer_->setMasterControlPanel(*playerControlPanel_);
	playerControlPanel_->setMasterVideoPlayer(*forwardPlayer_.get());
	forwardPlayer_->setForwardControlPanel(globalControlPanel_.get());
	globalControlPanel_->setMasterVideoPlayer(*videoPlayer_);
	graphPlayer_=std::make_unique<GraphPlayer>();
	graphPlayer_->setView(graphWidget_);
	globalControlPanel_->addVideoPlayer(graphPlayer_.get());
	graphPlayer_->setTimer(timer_);

	timer_labelUpdater_.start(200);

	analysisBoxContainer_->setControlPanel(globalControlPanel_);
	analysisBoxContainer_->setTimer(timer_);
}

std::unique_ptr<Memento::AnalysisTabMemento> GUI::AnalysisTab::getMemento() {
	auto memento=std::make_unique<Memento::AnalysisTabMemento>();

	memento->setRawVideo(rawVideo_);
	memento->setAnalysisBoxContainerMemento(std::move(analysisBoxContainer_->getMemento()));
	memento->setAnalysisGraph(analysisBoxContainer_->getShownGraph());
	memento->setAnalysisVideo(analysisBoxContainer_->getShownVideo());
	memento->setPlayerPosition(globalControlPanel_->getPosition());

	return std::move(memento);
}

void GUI::AnalysisTab::restore(Memento::AnalysisTabMemento *memento) {
	setRawVideo(memento->getRawVideo());

	if(memento->getAnalysisBoxContainerMemento()) {
		analysisBoxContainer_->restore(memento->getAnalysisBoxContainerMemento());
	}

	switch(memento->getAnalysisGraph()) {
	case AnalysisGraph::BITRATE:
		showBitrate();
		break;
	case AnalysisGraph::BLUE_HISTOGRAMM:
		showBlueHistogramm();
		break;
	case AnalysisGraph::RED_HISTOGRAMM:
		showRedHistogramm();
		break;
	case AnalysisGraph::GREEN_HISTOGRAMM:
		showGreenHistogramm();
		break;
	case AnalysisGraph::PSNR:
		showPsnr();
		break;
	}

	switch(memento->getAnalysisVideo()) {
	case AnalysisVideo::MACROBLOCK:
		combobbox_anaVideo_->setCurrentIndex(0);
		analysisBoxContainer_->showAnalysisVideo(AnalysisVideo::MACROBLOCK);
		break;
	case AnalysisVideo::RGB_DIFFERENCE:
		combobbox_anaVideo_->setCurrentIndex(1);
		analysisBoxContainer_->showAnalysisVideo(AnalysisVideo::RGB_DIFFERENCE);
		break;
	}
	globalControlPanel_->setPosition(memento->getPlayerPosition());

}

void GUI::AnalysisTab::setRawVideo(Model::YuvVideo *rawVideo) {
	analysisBoxContainer_->clear();

	globalControlPanel_->stop();


	if(rawVideo) {
		videoPlayer_->setVideo(&rawVideo->getVideo());
	} else {
		videoPlayer_->setVideo(nullptr);
	}
	rawVideo_=rawVideo;

	if(rawVideo) {
		v_rawVideo_->removeWidget(button_addRawVideo_);
		button_addRawVideo_->hide();
		v_rawVideo_->addWidget(rawVideoView_);
		rawVideoView_->show();

		QFile f(rawVideo->getPath());
		QFileInfo info(f);

		label_filename_->setText(info.fileName());
		label_filesize_->setText(QString::number(info.size()/(double)1000000,'f',2)+" MB");
		label_resolution_->setText(QString::number(rawVideo->getWidth())+"x"+QString::number(
		                               rawVideo->getHeight()));
		label_framesize_->setText(QString::number((rawVideo->getWidth()*rawVideo->getHeight()*3)/
		                          (double)1000,'f',2)+" KB");

		rawVideo_->getRedHistogramm();

	} else {
		v_rawVideo_->removeWidget(rawVideoView_);
		rawVideoView_->hide();
		v_rawVideo_->addWidget(button_addRawVideo_);
		button_addRawVideo_->show();

		label_filename_->setText("");
		label_filesize_->setText("");
		label_resolution_->setText("");
		label_framesize_->setText("");
	}
}

Model::YuvVideo *GUI::AnalysisTab::getRawVideo() {
	return rawVideo_;
}

bool GUI::AnalysisTab::isRawVideoLoaded() {
	return rawVideo_;
}

void GUI::AnalysisTab::resizeEvent(QResizeEvent *event) {
	if(event->size().width()>1300) {
		analysisBoxContainer_->setFixedWidth(1280);
	} else {
		analysisBoxContainer_->setFixedWidth(event->size().width()-56);
	}
}

void GUI::AnalysisTab::loadRawVideo() {
	YuvFileOpenDialog fileOpenDiag(this);

	int result=fileOpenDiag.exec();

	if(result!=QDialog::Accepted)
		return;

	auto path=fileOpenDiag.getFilename();

	if(path.isEmpty())
		return;

	auto yuvVideo =std::make_unique<Model::YuvVideo>(path,
	               fileOpenDiag.getPixelSheme(),
	               fileOpenDiag.getCompression(),fileOpenDiag.getWidth(),fileOpenDiag.getHeight(),
	               fileOpenDiag.getFps());

	UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::LoadAnalysisVideo(this,std::move(yuvVideo)));
}

void GUI::AnalysisTab::showBitrate() {
	if(!rawVideo_)
		return;
	analysisBoxContainer_->showGraph(AnalysisGraph::BITRATE);
	tabs_graphattrs->setCurrentIndex(1);
	graphPlayer_->setGraphVideo(nullptr);

	button_bitrate_->setStyleSheet(stylesheet_buttonsSelected_);
	button_blueHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_greenHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_psnr_->setStyleSheet(stylesheet_buttons_);
	button_redHistogramm_->setStyleSheet(stylesheet_buttons_);
}

void GUI::AnalysisTab::showRedHistogramm() {
	if(!rawVideo_)
		return;
	analysisBoxContainer_->showGraph(AnalysisGraph::RED_HISTOGRAMM);
	graphPlayer_->setGraphVideo(&rawVideo_->getRedHistogramm());
	tabs_graphattrs->setCurrentIndex(0);
	graphWidget_->setAxisLabels("","");
	graphWidget_->setIsFilled(true);
	QBrush filler(QColor(255,0,0));
	graphWidget_->setShowLabels(false);
	graphWidget_->setFillBrush(filler);
	QPen filpen(QColor(255,0,0));
	graphWidget_->setFillPen(filpen);
	graphWidget_->setLinePen(filpen);
	graphPlayer_->setPosition(globalControlPanel_->getPosition());

	button_bitrate_->setStyleSheet(stylesheet_buttons_);
	button_blueHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_greenHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_psnr_->setStyleSheet(stylesheet_buttons_);
	button_redHistogramm_->setStyleSheet(stylesheet_buttonsSelected_);

}

void GUI::AnalysisTab::showBlueHistogramm() {
	if(!rawVideo_)
		return;
	analysisBoxContainer_->showGraph(AnalysisGraph::BLUE_HISTOGRAMM);
	graphPlayer_->setGraphVideo(&rawVideo_->getBlueHistogramm());
	tabs_graphattrs->setCurrentIndex(0);
	graphWidget_->setAxisLabels("","");
	graphWidget_->setIsFilled(true);
	QBrush filler(QColor(0,0,255));
	graphWidget_->setShowLabels(false);
	graphWidget_->setFillBrush(filler);
	QPen filpen(QColor(0,0,255));
	graphWidget_->setFillPen(filpen);
	graphWidget_->setLinePen(filpen);
	graphPlayer_->setPosition(globalControlPanel_->getPosition());

	button_bitrate_->setStyleSheet(stylesheet_buttons_);
	button_blueHistogramm_->setStyleSheet(stylesheet_buttonsSelected_);
	button_greenHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_psnr_->setStyleSheet(stylesheet_buttons_);
	button_redHistogramm_->setStyleSheet(stylesheet_buttons_);
}

void GUI::AnalysisTab::showGreenHistogramm() {
	if(!rawVideo_)
		return;
	analysisBoxContainer_->showGraph(AnalysisGraph::GREEN_HISTOGRAMM);
	graphPlayer_->setGraphVideo(&rawVideo_->getGreenHistogramm());
	tabs_graphattrs->setCurrentIndex(0);
	graphWidget_->setAxisLabels("","");
	graphWidget_->setIsFilled(true);
	QBrush filler(QColor(0,255,0));
	graphWidget_->setShowLabels(false);
	graphWidget_->setFillBrush(filler);
	QPen filpen(QColor(0,255,0));
	graphWidget_->setFillPen(filpen);
	graphWidget_->setLinePen(filpen);
	graphPlayer_->setPosition(globalControlPanel_->getPosition());

	button_bitrate_->setStyleSheet(stylesheet_buttons_);
	button_blueHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_greenHistogramm_->setStyleSheet(stylesheet_buttonsSelected_);
	button_psnr_->setStyleSheet(stylesheet_buttons_);
	button_redHistogramm_->setStyleSheet(stylesheet_buttons_);
}

void GUI::AnalysisTab::showPsnr() {
	if(!rawVideo_)
		return;
	analysisBoxContainer_->showGraph(AnalysisGraph::PSNR);
	tabs_graphattrs->setCurrentIndex(1);
	graphPlayer_->setGraphVideo(nullptr);

	button_bitrate_->setStyleSheet(stylesheet_buttons_);
	button_blueHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_greenHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_psnr_->setStyleSheet(stylesheet_buttonsSelected_);
	button_redHistogramm_->setStyleSheet(stylesheet_buttons_);
}

void GUI::AnalysisTab::showAttributes() {
	tabs_graphattrs->setCurrentIndex(1);
	analysisBoxContainer_->showAttributes();
}

void GUI::AnalysisTab::analysisVideoChanged(int index) {
	if(index==0) {
		analysisBoxContainer_->showAnalysisVideo(AnalysisVideo::MACROBLOCK);
	} else if(index==1) {
		analysisBoxContainer_->showAnalysisVideo(AnalysisVideo::RGB_DIFFERENCE);
	}
}

void GUI::AnalysisTab::updateLabels() {
	if(!rawVideo_)
		return;

	label_resolution_->setText(QString::number(rawVideo_->getWidth())+"x"+QString::number(
	                               rawVideo_->getHeight()));
	label_framesize_->setText(QString::number((rawVideo_->getWidth()*rawVideo_->getHeight()*3)/
	                          (double)1000,'f',2)+" KB");

	if(rawVideo_->getWidth()!=0&&rawVideo_->getHeight()!=0) {
		timer_labelUpdater_.stop();
	}
}

void GUI::AnalysisTab::createUi() {
	button_saveResults_=new QPushButton("Save results");
	button_addRawVideo_=new QPushButton("Load video");
	button_attributes_=new QPushButton("Attributes");
	button_bitrate_=new QPushButton("Bitrate");
	button_blueHistogramm_=new QPushButton("Blue histogramm");
	button_greenHistogramm_=new QPushButton("Green histogramm");
	button_redHistogramm_=new QPushButton("Red histogramm");
	button_psnr_=new QPushButton("PSNR");

	button_saveResults_->setFlat(true);
	button_attributes_->setFlat(true);
	button_bitrate_->setFlat(true);
	button_blueHistogramm_->setFlat(true);
	button_greenHistogramm_->setFlat(true);
	button_redHistogramm_->setFlat(true);
	button_psnr_->setFlat(true);

	stylesheet_buttons_=QString("QPushButton {"
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

	stylesheet_buttonsSelected_=QString("QPushButton {"
	                                    "color: rgb(0, 0, 0);"
	                                    "background: rgb(180,180, 180);"
	                                    "border-width: 1px;"
	                                    "border-color:rgb(0, 0, 0);"
	                                    "border-style: outset;"
	                                    "border-radius: 7px;"
	                                    "font-size: 12px;"
	                                    "}"
	                                    "QPushButton:pressed {"
	                                    "background-color: rgb(160, 160, 160);"
	                                    "border-style: inset;"
	                                    "}"
	                                   );

	button_attributes_->setStyleSheet(stylesheet_buttons_);
	button_bitrate_->setStyleSheet(stylesheet_buttonsSelected_);
	button_blueHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_greenHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_redHistogramm_->setStyleSheet(stylesheet_buttons_);
	button_psnr_->setStyleSheet(stylesheet_buttons_);

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

	playerControlPanel_=new PlayerControlPanel;

	tabs_graphattrs=new QTabWidget;
	tabs_graphattrs->setTabPosition(QTabWidget::West);

	graphWidget_=new GraphWidget;
	tabs_graphattrs->addTab(graphWidget_,"Graphs");

	QWidget* attributes=new QWidget;
	QHBoxLayout* h_attributes=new QHBoxLayout;
	QSpacerItem* spacer9=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	h_attributes->addSpacing(10);
	h_attributes->addSpacerItem(spacer9);
	QWidget* attrcontent=new QWidget;
	attrcontent->setObjectName("attributescon");
	attrcontent->setStyleSheet("QWidget#attributescon {"
	                           "border-width:1px;"
	                           "border-color:black;"
	                           "border-radius:5px;"
	                           "border-style:outset;"
	                           "background-color:rgb(240,240,240);"
	                           "}");
	attrcontent->setMaximumWidth(400);

	QVBoxLayout* v_attrcontent=new QVBoxLayout;

	QString styleSheet("QLabel {"
	                   "font-weight:bold;"
	                   "}");

	QLabel* filename=new QLabel("Filename:");
	QLabel* filesize=new QLabel("Filesize:");
	QLabel* resolution=new QLabel("Resolution:");
	QLabel* framesize=new QLabel("Framesize:");

	filename->setStyleSheet(styleSheet);
	filesize->setStyleSheet(styleSheet);
	resolution->setStyleSheet(styleSheet);
	framesize->setStyleSheet(styleSheet);

	label_filename_=new QLabel("");
	label_filesize_=new QLabel("");
	label_resolution_=new QLabel("");
	label_framesize_=new QLabel("");

	QHBoxLayout* h_filename=new QHBoxLayout;
	h_filename->addWidget(filename);
	h_filename->addWidget(label_filename_);

	QHBoxLayout* h_filesize=new QHBoxLayout;
	h_filesize->addWidget(filesize);
	h_filesize->addWidget(label_filesize_);

	QHBoxLayout* h_resolution=new QHBoxLayout;
	h_resolution->addWidget(resolution);
	h_resolution->addWidget(label_resolution_);

	QHBoxLayout* h_framesize=new QHBoxLayout;
	h_framesize->addWidget(framesize);
	h_framesize->addWidget(label_framesize_);

	v_attrcontent->addLayout(h_filename);
	v_attrcontent->addLayout(h_filesize);
	v_attrcontent->addLayout(h_resolution);
	v_attrcontent->addLayout(h_framesize);


	button_loadnewvideo_=new QPushButton("Load new video");
	button_loadnewvideo_->setMaximumWidth(300);

	QHBoxLayout* h_button=new QHBoxLayout;
	QSpacerItem* spacer11=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	h_button->addSpacerItem(spacer11);
	h_button->addWidget(button_loadnewvideo_,1);
	QSpacerItem* spacer12=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	h_button->addSpacerItem(spacer12);
	v_attrcontent->addSpacing(5);
	QFrame* line=new QFrame;
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	v_attrcontent->addWidget(line);
	v_attrcontent->addSpacing(2);
	v_attrcontent->addLayout(h_button);

	attrcontent->setLayout(v_attrcontent);

	QSpacerItem* spacer10=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);

	h_attributes->addWidget(attrcontent,1);

	h_attributes->addSpacerItem(spacer10);
	h_attributes->addSpacing(10);

	attributes->setLayout(h_attributes);

	tabs_graphattrs->addTab(attributes,"Video");

	rawVideoView_=new FrameView;
	rawVideoView_->setFixedSize(200,200);

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
	analysisBoxContainer_->setParentTab(this);

	QWidget* scrollbutton=new QWidget;
	QVBoxLayout* v_scrollbutton=new QVBoxLayout;

	scroll_anaBoxes_=new QScrollArea;
	scroll_anaBoxes_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	scroll_anaBoxes_->setWidget(analysisBoxContainer_);
	scroll_anaBoxes_->setStyleSheet("QScrollArea {"
	                                "border-width:2px;"
	                                "border-color:black;"
	                                "border-style:outset;"
	                                "background-color:white;"
	                                "}");
	v_scrollbutton->addWidget(scroll_anaBoxes_);
	scrollbutton->setMaximumWidth(1300);

	scrollbutton->setLayout(v_scrollbutton);
	h_anaboxes->addWidget(scrollbutton,1);

	QSpacerItem* spacer7=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	h_anaboxes->addSpacerItem(spacer7);

	analysisBoxes->setLayout(h_anaboxes);
	v_content->addWidget(analysisBoxes);

	setContentsMargins(0,-10,0,-20);
	setLayout(v_content);
}

void GUI::AnalysisTab::connectActions() {
	connect(button_addRawVideo_,SIGNAL(clicked(bool)),this,SLOT(loadRawVideo()));
	connect(button_bitrate_,SIGNAL(clicked(bool)),this,SLOT(showBitrate()));
	connect(combobbox_anaVideo_,SIGNAL(currentIndexChanged(int)),this,SLOT(analysisVideoChanged(int)));
	connect(button_redHistogramm_,SIGNAL(clicked(bool)),this,SLOT(showRedHistogramm()));
	connect(button_blueHistogramm_,SIGNAL(clicked(bool)),this,SLOT(showBlueHistogramm()));
	connect(button_greenHistogramm_,SIGNAL(clicked(bool)),this,SLOT(showGreenHistogramm()));
	connect(button_psnr_,SIGNAL(clicked(bool)),this,SLOT(showPsnr()));
	connect(button_attributes_,SIGNAL(clicked(bool)),this,SLOT(showAttributes()));
	connect(button_loadnewvideo_,SIGNAL(clicked(bool)),this,SLOT(loadRawVideo()));
	connect(&timer_labelUpdater_,SIGNAL(timeout()),this,SLOT(updateLabels()));
}

