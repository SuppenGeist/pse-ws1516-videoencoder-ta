#include "AnalysisTab.h"

#include <QWidget>
#include <QFrame>
#include <memory>
#include <QDebug>

#include "VideoPlayer.h"
#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "Timer.h"
#include "AnalysisBoxContainer.h"
#include "GlobalControlPanel.h"
#include "../memento/AnalysisTabMemento.h"
#include "../model/YuvVideo.h"
#include "../undo_framework//LoadAnalysisVideo.h"
#include "ui_analysistab.h"

GUI::AnalysisTab::AnalysisTab(QWidget* parent) : QFrame(parent) {

	ui = new Ui::AnalysisTab;
	ui->setupUi(this);

    analysisBoxContainer = new GUI::AnalysisBoxContainer(ui->scrollArea);

    connect(ui->save,SIGNAL(clicked()),this,SLOT(saveResults()));
    connect(ui->addVideo,SIGNAL(clicked()),this,SLOT(addVideo()));

    playerPanel_ =new PlayerControlPanel(ui->panel);
    player_=std::make_unique<VideoPlayer>();
    FrameView* frameView_ = new FrameView;
    ui->rawVidCon->addWidget(frameView_);
    frameView_->setMaximumWidth(600);
    frameView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    player_->addView(*frameView_);
    player_->setTimer(std::make_shared<Timer>());
    playerPanel_->setMasterVideoPlayer(*player_);
    player_->setMasterControlPanel(*playerPanel_);

}

Memento::AnalysisTabMemento GUI::AnalysisTab::getMemento() {
}

void GUI::AnalysisTab::restore(Memento::AnalysisTabMemento memento) {
}

void GUI::AnalysisTab::analyseTypChanged(int index) {
}

void GUI::AnalysisTab::addVideo() {
}

void GUI::AnalysisTab::loadRawVideo() {
}

void GUI::AnalysisTab::saveResults() {
}

void GUI::AnalysisTab::setRawVideo(std::unique_ptr<Model::YuvVideo> video) {
    rawVideo_=std::move(video);
    player_->setVideo(&rawVideo_->getVideo());
}

