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

	analysisBoxContainer = new GUI::AnalysisBoxContainer(this);

	ui->scrollArea->setWidget(analysisBoxContainer);

	connect(ui->save,SIGNAL(clicked()),this,SLOT(saveResults()));
	connect(ui->addVideo,SIGNAL(clicked()),this,SLOT(addVideo()));
    connect(ui->analysisTyp,SIGNAL(currentIndexChanged(int)), this, SLOT(analyseTypChanged(int)));

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
    //analysisBoxContainer->setControlPanel(new GlobalControlPanel());

}

Memento::AnalysisTabMemento GUI::AnalysisTab::getMemento() {
    Memento::AnalysisTabMemento memo;
    memo.setAnalysisBoxContainerMemento(analysisBoxContainer->getMemento());
    memo.setCurrentSpeed(player_->getSpeed());
    memo.setCurrentVideoPosition(player_->getPosition());
    memo.setCurrentlyShownAnalysisVideo(ui->analysisTyp->currentIndex());
    return memo;
}

void GUI::AnalysisTab::restore(Memento::AnalysisTabMemento memento) {
    analysisBoxContainer->restore(memento.getAnalysisBoxContainerMemento());
    player_->setSpeed(memento.getCurrentSpeed());
    player_->setPosition(memento.getCurrentVideoPosition());
    ui->analysisTyp->setCurrentIndex(memento.getCurrentlyShownAnalysisVideo());
}

void GUI::AnalysisTab::analyseTypChanged(int index) {
    // 0 = RGB_Diff, 1 = Macroblock
    if(index == 1) {
        analysisBoxContainer->showRGBDifferenceVideos();
    } else if (index == 1) {
        analysisBoxContainer->showMacroBlockVideos();
    }
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

