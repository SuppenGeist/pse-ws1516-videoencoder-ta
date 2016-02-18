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
#include "../undo_framework/WriteComment.h"

GUI::AnalysisBox::AnalysisBox(QWidget* parent) : QFrame(parent) {
	createUi();
	setContentsMargins(0,0,0,0);
	setFixedHeight(250);

    connect(button_close_,SIGNAL(clicked(bool)),this,SLOT(closeBox()));
    connect(&timer_updateLabels_,SIGNAL(timeout()),this,SLOT(updateLabels()));
    connect(texteEdit_comment_,SIGNAL(textChanged()),this,SLOT(commentChanged()));
    timer_updateLabels_.start(200);

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

std::unique_ptr<Memento::AnalysisBoxMemento> GUI::AnalysisBox::getMemento()
{
    auto memento=std::make_unique<Memento::AnalysisBoxMemento>();

    if(origVideo_) {
    memento->setPath(origVideo_->getPath());
    }
    memento->setComment(texteEdit_comment_->toPlainText());
    return std::move(memento);
}

void GUI::AnalysisBox::restore(Memento::AnalysisBoxMemento *memento)
{
    if(!memento)
        return;

    setFile(memento->getPath());
    texteEdit_comment_->document()->setPlainText(memento->getComment());
}

void GUI::AnalysisBox::setParentContainer(GUI::AnalysisBoxContainer *container) {
	parentContainer_=container;
}

void GUI::AnalysisBox::setFile(QString filename) {
	filename_=filename;

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

    origVideo_->getRedHistogramm();
    origVideo_->getBitrate();
    origVideo_->getMacroBlockVideo();
    origVideo_->getRgbDiffVideo(&parentContainer_->getParentTab()->getRawVideo()->getVideo());
    origVideo_->getPsnr(&parentContainer_->getParentTab()->getRawVideo()->getVideo());

    label_codec_->setText(origVideo_->getCodec());
    label_averageBitrate_->setText(QString::number(origVideo_->getAverageBitrate()));
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
    case AnalysisVideo::RGB_DIFFERENCE:
        anaVidPlayer_->setVideo(origVideo_->getRgbDiffVideo(&parentContainer_->getParentTab()->getRawVideo()->getVideo()),false);
        break;
    }

    if(globalControlPanel_.get()) {
        anaVidPlayer_->setPosition(globalControlPanel_->getPosition());
    }
}

void GUI::AnalysisBox::showAttributes()
{
    tabs_graphs_->setCurrentIndex(1);
}

QString GUI::AnalysisBox::getFilename() {
    return filename_;
}

QPlainTextEdit *GUI::AnalysisBox::getCommentBox()
{
    return texteEdit_comment_;
}

void GUI::AnalysisBox::closeBox() {
	auto command=new UndoRedo::RemoveVideo(parentContainer_,this);

    UndoRedo::UndoStack::getUndoStack().push(command);
}

void GUI::AnalysisBox::updateLabels()
{
    label_codec_->setText(origVideo_->getCodec());
    label_averageBitrate_->setText(QString::number(origVideo_->getAverageBitrate()/(double)1000,'f',2)+" KB/s");

    if(origVideo_->getCodec()!="")
        timer_updateLabels_.stop();
}

void GUI::AnalysisBox::commentChanged()
{
    auto newComment=texteEdit_comment_->toPlainText();

    if(newComment.split(" ").size()!=currentComment_.split(" ").size()&&newComment!=currentComment_) {
        UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::WriteComment(parentContainer_,parentContainer_->getIndex(this),currentComment_,newComment));
        currentComment_=newComment;
    }
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
