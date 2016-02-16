#include "AnalysisBox.h"

#include <memory>

#include <QFrame>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileInfo>
#include <QBrush>
#include <QPen>
#include <QFile>
#include <QDebug>
#include <QTabWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QTimer>

#include "FrameView.h"
#include "GraphWidget.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "AnalysisTab.h"
#include "GlobalControlPanel.h"

#include "../model/EncodedVideo.h"

#include "../undo_framework/UndoStack.h"
#include "../undo_framework/RemoveVideo.h"

GUI::AnalysisBox::AnalysisBox(QWidget* parent) : QFrame(parent) {
	createUi();
	setContentsMargins(0,0,0,0);
	setFixedHeight(250);

    connect(button_close_,SIGNAL(clicked(bool)),this,SLOT(closeBox()));

	origVidPlayer_=std::make_unique<VideoPlayer>();
	anaVidPlayer_=std::make_unique<VideoPlayer>();
    graphPlayer_=std::make_unique<GraphPlayer>();

	origVidPlayer_->addView(*origView_);
    anaVidPlayer_->addView(*anaView_);
}

GUI::AnalysisBox::~AnalysisBox() {
	globalControlPanel_->removeVideoPlayer(*origVidPlayer_);
    globalControlPanel_->removeVideoPlayer(*graphPlayer_);
	globalControlPanel_->removeVideoPlayer(*anaVidPlayer_);
	origVidPlayer_->clearTimer();
	anaVidPlayer_->clearTimer();
    graphPlayer_->clearTimer();
}

void GUI::AnalysisBox::setParentContainer(GUI::AnalysisBoxContainer *container) {
	parentContainer_=container;
}

void GUI::AnalysisBox::setFile(QString filename) {
	filename_=filename;

	QFile f(filename);
	QFileInfo info(f);

	label_title_->setText(info.fileName());
	origVideo_=std::make_unique<Model::EncodedVideo>(filename);


    origVidPlayer_->setVideo(&origVideo_->getVideo(),false);
    if(globalControlPanel_.get()) {
        origVidPlayer_->setPosition(globalControlPanel_->getPosition());
    }

    origVideo_->getRedHistogramm();
    origVideo_->getBitrate();
    origVideo_->getPsnr(&parentContainer_->getParentTab()->getRawVideo()->getVideo());
}

void GUI::AnalysisBox::setTimer(std::shared_ptr<GUI::Timer> timer) {
	origVidPlayer_->setTimer(timer);
	anaVidPlayer_->setTimer(timer);
    graphPlayer_->setTimer(timer);
}

void GUI::AnalysisBox::setControlPanel(std::shared_ptr<GlobalControlPanel> controlPanel) {
	controlPanel->addVideoPlayer(origVidPlayer_.get());
	controlPanel->addVideoPlayer(anaVidPlayer_.get());
    controlPanel->addVideoPlayer(graphPlayer_.get());

	globalControlPanel_=controlPanel;
}

void GUI::AnalysisBox::showGraph(GUI::AnalysisGraph graph) {
	switch(graph) {
	case AnalysisGraph::BITRATE:
    {
        graphPlayer_->setGraphVideo(nullptr);
        graphPlayer_->setView(nullptr);
        graphWidget_->drawGraph(&origVideo_->getBitrate());
		graphWidget_->setAxisLabels("frame","kb");
        graphWidget_->setControlPanel(globalControlPanel_.get());
        graphWidget_->setShowLabels(true);
        graphWidget_->setIsFilled(false);
        QPen linepen;
        graphWidget_->setLinePen(linepen);
        tabs_graphs_->setCurrentIndex(0);
		break;
    }
    case AnalysisGraph::RED_HISTOGRAMM:
    {
        graphWidget_->setControlPanel(nullptr);
        graphWidget_->drawGraph(nullptr);
        graphPlayer_->setView(graphWidget_);
        graphPlayer_->setGraphVideo(&origVideo_->getRedHistogramm());
        graphWidget_->setAxisLabels("","");
        graphWidget_->setIsFilled(true);
        graphWidget_->setShowLabels(false);
        QBrush filler(QColor(255,0,0));
        graphWidget_->setFillBrush(filler);
        QPen filpen(QColor(255,0,0));
        graphWidget_->setFillPen(filpen);
        graphWidget_->setLinePen(filpen);
        if(globalControlPanel_.get()) {
            graphPlayer_->setPosition(globalControlPanel_->getPosition());
        }
        tabs_graphs_->setCurrentIndex(0);
        break;
    }
    case AnalysisGraph::BLUE_HISTOGRAMM:
    {
        graphWidget_->setControlPanel(nullptr);
        graphWidget_->drawGraph(nullptr);
        graphPlayer_->setView(graphWidget_);
        graphPlayer_->setGraphVideo(&origVideo_->getBlueHistogramm());
        graphWidget_->setAxisLabels("","");
        graphWidget_->setIsFilled(true);
        graphWidget_->setShowLabels(false);
        QBrush filler(QColor(0,0,255));
        graphWidget_->setFillBrush(filler);
        QPen filpen(QColor(0,0,255));
        graphWidget_->setFillPen(filpen);
        graphWidget_->setLinePen(filpen);
        if(globalControlPanel_.get()) {
            graphPlayer_->setPosition(globalControlPanel_->getPosition());
        }
        tabs_graphs_->setCurrentIndex(0);
        break;
    }
    case AnalysisGraph::GREEN_HISTOGRAMM:
    {
        graphWidget_->setControlPanel(nullptr);
        graphWidget_->drawGraph(nullptr);
        graphPlayer_->setView(graphWidget_);
        graphPlayer_->setGraphVideo(&origVideo_->getGreenHistogramm());
        graphWidget_->setAxisLabels("","");
        graphWidget_->setIsFilled(true);
        QBrush filler(QColor(0,255,0));
        graphWidget_->setShowLabels(false);
        graphWidget_->setFillBrush(filler);
        QPen filpen(QColor(0,255,0));
        graphWidget_->setFillPen(filpen);
        graphWidget_->setLinePen(filpen);
        if(globalControlPanel_.get()) {
            graphPlayer_->setPosition(globalControlPanel_->getPosition());
        }
        tabs_graphs_->setCurrentIndex(0);
        break;
    }
    case AnalysisGraph::PSNR:
    {
        graphPlayer_->setGraphVideo(nullptr);
        graphPlayer_->setView(nullptr);
        graphWidget_->drawGraph(origVideo_->getPsnr(&parentContainer_->getParentTab()->getRawVideo()->getVideo()));
        graphWidget_->setAxisLabels("frame","dB");
        graphWidget_->setControlPanel(globalControlPanel_.get());
        graphWidget_->setShowLabels(true);
        graphWidget_->setIsFilled(false);
        QPen linepen;
        graphWidget_->setLinePen(linepen);
        tabs_graphs_->setCurrentIndex(0);
        break;
    }
    }
}

void GUI::AnalysisBox::showAnalysisVideo(GUI::AnalysisVideo video)
{
    switch(video) {
    case AnalysisVideo::MACROBLOCK:
        anaVidPlayer_->setVideo(&origVideo_->getMacroBlockVideo(),false);
        break;
    }

    if(globalControlPanel_.get()) {
        anaVidPlayer_->setPosition(globalControlPanel_->getPosition());
    }
}

QString GUI::AnalysisBox::getFilename() {
	return filename_;
}

void GUI::AnalysisBox::closeBox() {
	auto command=new UndoRedo::RemoveVideo(parentContainer_,this);

	UndoRedo::UndoStack::getUndoStack().push(command);
}

void GUI::AnalysisBox::createUi() {
	origView_=new FrameView;
	origView_->setFixedSize(200,200);

	button_close_=new QPushButton;
	button_close_->setFlat(true);
	button_close_->setFixedSize(15,15);
	button_close_->setStyleSheet("QPushButton {"
	                             "border-image:url(:/icons/resources/icons/close.png);"
	                             "}"
	                             "QPushButton:pressed {"
	                             "border-image:none;"
	                             "border-width:1px;"
	                             "border-color:black;"
	                             "border-style:outset;"
	                             "background-color:rgb(200,200,200);"
	                             "}");

	label_title_=new QLabel("");
	label_title_->setStyleSheet("QLabel {"
	                            "font-weight:bold;"
	                            "font-size:15px;"
	                            "}");

	anaView_=new FrameView;
	anaView_->setFixedSize(200,200);

	graphWidget_=new GraphWidget;

	tabs_graphs_=new QTabWidget;
	tabs_graphs_->setTabPosition(QTabWidget::West);
	tabs_graphs_->addTab(graphWidget_,"Graphs");
	QWidget* attr=new QWidget;
	tabs_graphs_->addTab(attr,"Video");

	QVBoxLayout* v_control=new QVBoxLayout;

	QHBoxLayout* h_control=new QHBoxLayout;
	h_control->addWidget(label_title_);
	QSpacerItem* spacer=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);
	h_control->addSpacerItem(spacer);
	h_control->addWidget(button_close_);
	h_control->addSpacing(15);

	v_control->addLayout(h_control);

	QHBoxLayout* h_content=new QHBoxLayout;

	h_content->addSpacing(2);
	h_content->addWidget(origView_);
	h_content->addSpacing(5);
	h_content->addWidget(tabs_graphs_);
	h_content->addSpacing(5);
	h_content->addWidget(anaView_);
	h_content->addSpacing(10);

	v_control->addLayout(h_content);

	setLayout(v_control);
}
