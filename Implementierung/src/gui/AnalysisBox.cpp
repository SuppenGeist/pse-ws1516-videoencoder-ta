#include "AnalysisBox.h"

#include <QFrame>
#include <QWidget>
#include <memory>
#include <QLabel>
#include <QVBoxLayout>
#include <QRegExp>

#include "AnalysisBoxContainer.h"
#include "VideoPlayer.h"
#include "GraphWidget.h"
#include "Timer.h"
#include "FrameView.h"
#include "../memento/AnalysisBoxMemento.h"
#include "../model/EncodedVideo.h"
#include "../undo_framework/RemoveVideo.h"
#include "ui_analysisbox.h"
#include "GlobalControlPanel.h"
#include "Timer.h"


GUI::AnalysisBox::AnalysisBox(QWidget* parent) : QFrame(parent) {
    currentlyPlayedVideo_=0;
    ui_ = new Ui::AnalysisBox;
    ui_->setupUi(this);

    plainVideoPlayer_=std::make_unique<VideoPlayer>();
    FrameView* frameView_ = new FrameView;
    ui_->rawVidCon->addWidget(frameView_);
    frameView_->setMaximumWidth(600);
    frameView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    plainVideoPlayer_->addView(*frameView_);
    //plainVideoPlayer_->setMasterControlPanel(*playerPanel_);

    analysisVideoPlayer_=std::make_unique<VideoPlayer>();
    frameView_ = new FrameView;
    ui_->anaVidCon->addWidget(frameView_);
    frameView_->setMaximumWidth(600);
    frameView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    analysisVideoPlayer_->addView(*frameView_);
    //analysisVideoPlayer_->setMasterControlPanel(*playerPanel_);

    //playerPanel_->addVideoPlayer(*plainVideoPlayer_);
    //playerPanel_->addVideoPlayer(*analysisVideoPlayer_);


    //connect(ui_->close,SIGNAL(clicked()), this, SLOT(close()));
}

Memento::AnalysisBoxMemento GUI::AnalysisBox::getMemento() {
    /*
    Memento::AnalysisBoxMemento memo;
    memo.setVideoPath(video_->getPsnr());
    memo.setBitrate(video_->getBitrate());
    memo.setComment(ui_->userComment->toPlainText());
    memo.setMacroVideo(video_->getMacroBlockVideo());
    memo.setRgbDiffVideo(video_->getRgbDiffVideo());
    memo.setVideoPath(video_->getPath());

    return memo;
    */
}

void GUI::AnalysisBox::restore(Memento::AnalysisBoxMemento memento) {

    /*video_ = new std::make_unique<Model::EncodedVideo>();
    video_->setPsnr(memento.getPsnr());
    video_->setBitrate(memento.getBitrate());
    video_->setPath(memento.getVideoPath());
    ui_->userComment->setDocument(new QTextDocument(memento.getComment(), ui_->userComment));
    */
}

/*void AnalysisBox::setTimer(shared_ptrshared_ptr<GUI::Timer> timer:std:) {
    throw "Not yet implemented";
}
*/
void GUI::AnalysisBox::setRawVideo(Model::Video* video) {
    this->rawVideo_ = video;
}

void GUI::AnalysisBox::setControlPanel(GUI::GlobalControlPanel* panel) {
    playerPanel_ = panel;
}

void GUI::AnalysisBox::showMacroBlockVideo() {
     if(currentlyPlayedVideo_ == 1) {
        //analysisVideoPlayer_->setVideo(&(video_->getMacroBlockVideo()));
     }
}

void GUI::AnalysisBox::showRGBDifferenceVideo() {
    if(currentlyPlayedVideo_ == 1) {
       //analysisVideoPlayer_->setVideo(&(video_->getRgbDiffVideo(rawVideo_)));
    }
}

void GUI::AnalysisBox::close() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::textChanged() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::setAnalyseVideo(std::unique_ptr<Model::EncodedVideo> video) {
    QRegExp reg = QRegExp("(.(dot))*/");
    //ui_->groupBox->setTitle(video_->getPath()->replace(reg,QString(""));
    video_ = std::move(video);
    /*u
     * plainVideoPlayer_->setVideo(&(video_->getVideo()));

    GUI::GraphWidget *g = new GUI::GraphWidget;
    g->drawGraph(video_->getPsnr());
    ui_->tabWidget->addTab(g,QString("Psnr"));
    g = new GUI::GraphWidget;
    g->drawGraph(video_->getBitrate());
    ui_->tabWidget->addTab(g,"Bitrate");
    QWidget* w = new QWidget;
    QVBoxLayout *ly = new QVBoxLayout(w);
    ly->addWidget(new QLabel(QString("Path: " + video_->getPath())));
    ui_->tabWidget->addTab(w,QString("Attributs"));
    */
  }

