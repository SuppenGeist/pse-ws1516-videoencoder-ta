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
#include <QMessageBox>

#include "FrameView.h"
#include "GraphWidget.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "AnalysisTab.h"
#include "GlobalControlPanel.h"

#include "../model/EncodedVideo.h"

#include "../undo_framework/UndoStack.h"
#include "../undo_framework/RemoveVideo.h"
#include "../undo_framework/WriteComment.h"

GUI::AnalysisBox::AnalysisBox(QWidget* parent) : QFrame(parent) {
	createUi();
	connectActions();
	setContentsMargins(0,0,0,0);
	setFixedHeight(250);

	timer_updateLabels_.start(200);

	origVidPlayer_=std::make_unique<VideoPlayer>();
	anaVidPlayer_=std::make_unique<VideoPlayer>();
	graphPlayer_=std::make_unique<GraphPlayer>();

	origVidPlayer_->addView(*origView_);
	anaVidPlayer_->addView(*anaView_);

	calculator_=std::make_unique<GraphCalculator>();
	graphWidget_->setGraphCalculator(calculator_.get());
}

GUI::AnalysisBox::~AnalysisBox() {
	globalControlPanel_->removeVideoPlayer(*origVidPlayer_);
	globalControlPanel_->removeVideoPlayer(*graphPlayer_);
	globalControlPanel_->removeVideoPlayer(*anaVidPlayer_);
	origVidPlayer_->clearTimer();
	anaVidPlayer_->clearTimer();
	graphPlayer_->clearTimer();
}

std::unique_ptr<Memento::AnalysisBoxMemento> GUI::AnalysisBox::getMemento() {
	auto memento=std::make_unique<Memento::AnalysisBoxMemento>();

	if(origVideo_) {
		memento->setPath(origVideo_->getPath());
		memento->setMacroBlockVideo(&origVideo_->getMacroBlockVideo());
		memento->setRgbDiffVideo(origVideo_->getRgbDiffVideo(
		                             &parentContainer_->getParentTab()->getRawVideo()->getVideo()));
		memento->setPsnrGraph(origVideo_->getPsnr());
		memento->setBitrateGraph(&origVideo_->getBitrate());
		memento->setRedHistogram(&origVideo_->getRedHistogram());
		memento->setGreenHistogram(&origVideo_->getGreenHistogram());
		memento->setBlueHistogram(&origVideo_->getBlueHistogram());
	}
	memento->setEncoder(label_codec_->text());
	memento->setAverageBitrate(label_averageBitrate_->text());
	memento->setFilename(label_filename_->text());
	memento->setFilesize(label_filesize_->text());
	memento->setComment(texteEdit_comment_->toPlainText());

	return std::move(memento);
}

void GUI::AnalysisBox::restore(Memento::AnalysisBoxMemento *memento) {

	if(!memento) {
		return;
	}
	setFile(memento->getPath());
	texteEdit_comment_->blockSignals(true);
	texteEdit_comment_->document()->setPlainText(memento->getComment());
	texteEdit_comment_->blockSignals(false);
}

void GUI::AnalysisBox::setParentContainer(GUI::AnalysisBoxContainer *container) {
	parentContainer_=container;
}

void GUI::AnalysisBox::setFile(QString filename) {
	origVideo_=std::make_unique<Model::EncodedVideo>(filename);

	QFile f(filename);
	QFileInfo info(f);

	label_title_->setText(info.fileName());
	label_filename_->setText(info.fileName());
	label_filesize_->setText(QString::number(info.size()/(double)1000000,'f',2)+" MB");


	origVidPlayer_->setVideo(&origVideo_->getVideo(),false);
	if(globalControlPanel_.get()) {
		origVidPlayer_->setPosition(globalControlPanel_->getPosition());
	}

	origVideo_->getRedHistogram();
	origVideo_->getBitrate();
	origVideo_->getMacroBlockVideo();
	origVideo_->getRgbDiffVideo(&parentContainer_->getParentTab()->getRawVideo()->getVideo());
	origVideo_->getPsnr(&parentContainer_->getParentTab()->getRawVideo()->getVideo());

	label_codec_->setText(origVideo_->getCodec());
	label_averageBitrate_->setText(QString::number(origVideo_->getAverageBitrate()));

	if(parentContainer_) {
		showGraph(parentContainer_->getShownGraph());
		showAnalysisVideo(parentContainer_->getShownVideo());
	}
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
	if(!origVideo_.get())
        return;

	switch(graph) {
	case AnalysisGraph::BITRATE: {
		graphPlayer_->setGraphVideo(nullptr);
		graphPlayer_->setView(nullptr);
		calculator_->setAxisLabels("frame","kb");
		graphWidget_->setControlPanel(globalControlPanel_.get());
		calculator_->setShowLabels(true);
		calculator_->setIsFilled(false);
		QPen linepen;
		calculator_->setLinePen(linepen);
		graphWidget_->drawGraph(&origVideo_->getBitrate());
		tabs_graphs_->setCurrentIndex(0);
		break;
	}
	case AnalysisGraph::RED_HISTOGRAM: {
		graphWidget_->drawGraph(nullptr);
		graphWidget_->setControlPanel(nullptr);
		graphPlayer_->setView(graphWidget_);
		calculator_->setAxisLabels("","");
		calculator_->setIsFilled(true);
		calculator_->setShowLabels(false);
		QBrush filler(QColor(255,0,0));
		calculator_->setFillBrush(filler);
		QPen filpen(QColor(255,0,0));
		calculator_->setFillPen(filpen);
		calculator_->setLinePen(filpen);
		graphPlayer_->setGraphVideo(&origVideo_->getRedHistogram());
		if(globalControlPanel_.get()) {
			graphPlayer_->setPosition(globalControlPanel_->getPosition());
		}
		tabs_graphs_->setCurrentIndex(0);
		break;
	}
	case AnalysisGraph::BLUE_HISTOGRAM: {
		graphWidget_->setControlPanel(nullptr);
		graphWidget_->drawGraph(nullptr);
		graphPlayer_->setView(graphWidget_);
		calculator_->setAxisLabels("","");
		calculator_->setIsFilled(true);
		calculator_->setShowLabels(false);
		QBrush filler(QColor(0,0,255));
		calculator_->setFillBrush(filler);
		QPen filpen(QColor(0,0,255));
		calculator_->setFillPen(filpen);
		calculator_->setLinePen(filpen);
		graphPlayer_->setGraphVideo(&origVideo_->getBlueHistogram());
		if(globalControlPanel_.get()) {
			graphPlayer_->setPosition(globalControlPanel_->getPosition());
		}
		tabs_graphs_->setCurrentIndex(0);
		break;
	}
	case AnalysisGraph::GREEN_HISTOGRAM: {
		graphWidget_->setControlPanel(nullptr);
		graphWidget_->drawGraph(nullptr);
		graphPlayer_->setView(graphWidget_);
		calculator_->setAxisLabels("","");
		calculator_->setIsFilled(true);
		QBrush filler(QColor(0,255,0));
		calculator_->setShowLabels(false);
		calculator_->setFillBrush(filler);
		QPen filpen(QColor(0,255,0));
		calculator_->setFillPen(filpen);
		calculator_->setLinePen(filpen);
		graphPlayer_->setGraphVideo(&origVideo_->getGreenHistogram());
		if(globalControlPanel_.get()) {
			graphPlayer_->setPosition(globalControlPanel_->getPosition());
		}
		tabs_graphs_->setCurrentIndex(0);
		break;
	}
	case AnalysisGraph::PSNR: {
		graphPlayer_->setGraphVideo(nullptr);
		graphPlayer_->setView(nullptr);
		calculator_->setAxisLabels("frame","dB");
		graphWidget_->setControlPanel(globalControlPanel_.get());
		calculator_->setShowLabels(true);
		calculator_->setIsFilled(false);
		QPen linepen;
		calculator_->setLinePen(linepen);
		graphWidget_->drawGraph(origVideo_->getPsnr(
		                            &parentContainer_->getParentTab()->getRawVideo()->getVideo()));
		tabs_graphs_->setCurrentIndex(0);
		break;
	}
	}
}

void GUI::AnalysisBox::showAnalysisVideo(GUI::AnalysisVideo video) {
	if(!origVideo_.get())
		return;

	switch(video) {
	case AnalysisVideo::MACROBLOCK:
		anaVidPlayer_->setVideo(&origVideo_->getMacroBlockVideo(),false);
		break;
	case AnalysisVideo::RGB_DIFFERENCE:
		anaVidPlayer_->setVideo(origVideo_->getRgbDiffVideo(
		                            &parentContainer_->getParentTab()->getRawVideo()->getVideo()),false);
		break;
	}

	if(globalControlPanel_.get()) {
		anaVidPlayer_->setPosition(globalControlPanel_->getPosition());
	}
}

void GUI::AnalysisBox::showAttributes() {
	tabs_graphs_->setCurrentIndex(1);
}

QString GUI::AnalysisBox::getPath() {
	return origVideo_->getPath();
}

QPlainTextEdit *GUI::AnalysisBox::getCommentBox() {
	return texteEdit_comment_;
}

void GUI::AnalysisBox::lockUi() {
	button_close_->setEnabled(false);
	texteEdit_comment_->setEnabled(false);
}

void GUI::AnalysisBox::unlockUi() {
	button_close_->setEnabled(true);
	texteEdit_comment_->setEnabled(true);
}

void GUI::AnalysisBox::close() {
	auto command=new UndoRedo::RemoveVideo(parentContainer_,this);

	UndoRedo::UndoStack::getUndoStack().push(command);
}

void GUI::AnalysisBox::updateLabels() {
	label_codec_->setText(origVideo_->getCodec());
	label_averageBitrate_->setText(QString::number(origVideo_->getAverageBitrate()/(double)1000,'f',
	                               2)+" KB/s");

	if(!anaVidPlayer_->getVideo()&&parentContainer_) {
		showAnalysisVideo(parentContainer_->getShownVideo());
	}
	if(!graphWidget_->getGraph()&&parentContainer_) {
		showGraph(parentContainer_->getShownGraph());
	}
	if(parentContainer_) {
		origVideo_->getRgbDiffVideo(&parentContainer_->getParentTab()->getRawVideo()->getVideo());
		origVideo_->getPsnr(&parentContainer_->getParentTab()->getRawVideo()->getVideo());
	}
    if(origVideo_->getAvVideo().isComplete()) {
		timer_updateLabels_.stop();
        if(origVideo_->getAvVideo().getNumberOfFrames()==0) {
            QMessageBox::warning(this,"Error while loading video","Video could not be loaded!");
            auto& stack=UndoRedo::UndoStack::getUndoStack();
            stack.setIndex(stack.index()-1);
        }
    }
}

void GUI::AnalysisBox::commentChanged() {
	auto newComment=texteEdit_comment_->toPlainText();

	UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::WriteComment(parentContainer_,
	        parentContainer_->getIndex(this),currentComment_,newComment));
	currentComment_=newComment;
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

	QHBoxLayout* h_videoTab=new QHBoxLayout;
	QSpacerItem* spacer4=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	h_videoTab->addSpacerItem(spacer4);
	h_videoTab->addSpacing(10);

	QVBoxLayout* v_videoTab=new QVBoxLayout;

	QString styleSheet("QLabel {"
	                   "font-weight:bold;"
	                   "}");

	QLabel* filename=new QLabel("Filename:");
	QLabel* filesize=new QLabel("Filesize:");
	QLabel* codec=new QLabel("Codec:");
	QLabel* bitrate=new QLabel("Average bitrate:");

	codec->setStyleSheet(styleSheet);
	filesize->setStyleSheet(styleSheet);
	filename->setStyleSheet(styleSheet);
	bitrate->setStyleSheet(styleSheet);

	label_filename_=new QLabel("testfilename.txt");
	label_filesize_=new QLabel("2,5MB");
	label_codec_=new QLabel("H.264");
	label_averageBitrate_=new QLabel("4444 kb/s");

	QWidget* attributes=new QWidget;
	QVBoxLayout* v_attributes=new QVBoxLayout;

	QHBoxLayout* h_filename=new QHBoxLayout;
	h_filename->addWidget(filename);
	h_filename->addWidget(label_filename_);

	QHBoxLayout* h_filesize=new QHBoxLayout;
	h_filesize->addWidget(filesize);
	h_filesize->addWidget(label_filesize_);

	QHBoxLayout* h_codec=new QHBoxLayout;
	h_codec->addWidget(codec);
	h_codec->addWidget(label_codec_);

	QHBoxLayout* h_bitrate=new QHBoxLayout;
	h_bitrate->addWidget(bitrate);
	h_bitrate->addWidget(label_averageBitrate_);

	texteEdit_comment_=new QPlainTextEdit;
	texteEdit_comment_->setFixedHeight(50);
	texteEdit_comment_->document()->setPlainText("Your note...");

	v_attributes->addLayout(h_filename);
	v_attributes->addLayout(h_filesize);
	v_attributes->addLayout(h_codec);
	v_attributes->addLayout(h_bitrate);

	v_videoTab->addLayout(v_attributes);

	attributes->setObjectName("attributes");
	attributes->setStyleSheet("QWidget#attributes {"
	                          "border-width:1px;"
	                          "border-color:black;"
	                          "border-radius:5px;"
	                          "border-style:outset;"
	                          "background-color:rgb(240,240,240);"
	                          "}");
	attributes->setMaximumWidth(500);

	QSpacerItem* spacer1=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);

	v_videoTab->addSpacerItem(spacer1);
	v_videoTab->addWidget(texteEdit_comment_);


	attributes->setLayout(v_videoTab);
	h_videoTab->addWidget(attributes,1);
	h_videoTab->addSpacing(10);
	QSpacerItem* spacer3=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	h_videoTab->addSpacerItem(spacer3);
	attr->setLayout(h_videoTab);
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
	currentComment_=texteEdit_comment_->toPlainText();
}

void GUI::AnalysisBox::connectActions() {
	connect(button_close_,SIGNAL(clicked(bool)),this,SLOT(close()));
	connect(&timer_updateLabels_,SIGNAL(timeout()),this,SLOT(updateLabels()));
	connect(texteEdit_comment_,SIGNAL(textChanged()),this,SLOT(commentChanged()));

}
