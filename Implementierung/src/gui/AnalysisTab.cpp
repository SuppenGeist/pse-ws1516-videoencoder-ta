#include "AnalysisTab.h"

#include <QWidget>
#include <QFrame>
#include <memory>
#include <QFileDialog>


#include "VideoPlayer.h"
#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "Timer.h"
#include "AnalysisBoxContainer.h"
#include "GlobalControlPanel.h"
#include "../memento/AnalysisTabMemento.h"
#include "../model/YuvVideo.h"
#include "ui_analysistab.h"
#include "YuvInfoDialog.h"
#include "YuvFileOpenDialog.h"
#include "../undo_framework/UndoStack.h"
#include "../undo_framework//LoadAnalysisVideo.h"
#include "../undo_framework/AddVideo.h"

GUI::AnalysisTab::AnalysisTab(QWidget* parent) : QFrame(parent) {

    ui_ = new Ui::AnalysisTab;
    ui_->setupUi(this);

    analysisBoxContainer_ = new GUI::AnalysisBoxContainer(this);

    ui_->scrollArea->setWidget(analysisBoxContainer_);

    connect(ui_->save,SIGNAL(clicked()),this,SLOT(saveResults()));
    connect(ui_->addVideo,SIGNAL(clicked()),this,SLOT(addVideo()));
    connect(ui_->analysisTyp,SIGNAL(currentIndexChanged(int)), this, SLOT(analyseTypChanged(int)));

    playerPanel_ =new PlayerControlPanel(ui_->panel);
	player_=std::make_unique<VideoPlayer>();
	FrameView* frameView_ = new FrameView;
    ui_->rawVidCon->addWidget(frameView_);
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
    memo.setAnalysisBoxContainerMemento(analysisBoxContainer_->getMemento());
    memo.setCurrentSpeed(player_->getSpeed());
    memo.setCurrentVideoPosition(player_->getPosition());
    memo.setCurrentlyShownAnalysisVideo(ui_->analysisTyp->currentIndex());
    return memo;
}

void GUI::AnalysisTab::restore(Memento::AnalysisTabMemento memento) {
    analysisBoxContainer_->restore(memento.getAnalysisBoxContainerMemento());
    player_->setSpeed(memento.getCurrentSpeed());
    player_->setPosition(memento.getCurrentVideoPosition());
    ui_->analysisTyp->setCurrentIndex(memento.getCurrentlyShownAnalysisVideo());
}

void GUI::AnalysisTab::analyseTypChanged(int index) {
    // 0 = RGB_Diff, 1 = Macroblock
    if(index == 1) {
        analysisBoxContainer_->showRGBDifferenceVideos();
    } else if (index == 1) {
        analysisBoxContainer_->showMacroBlockVideos();
    }
}
std::unique_ptr<Model::YuvVideo> GUI::AnalysisTab::removeYuvVideo() {
    auto video=std::move(rawVideo_);
    player_->stop();
    ui_->addVideo->setText("Add Video");
    return std::move(video);
}

void GUI::AnalysisTab::loadYuvVideo(std::unique_ptr<Model::YuvVideo> video) {
    player_->setVideo(&video->getVideo());
    rawVideo_=std::move(video);
    ui_->addVideo->setText("Add Video");
}

void GUI::AnalysisTab::addVideo() {
    if(ui_->addVideo->text() == QString("Add Raw Video")) {
        YuvFileOpenDialog fileOpenDiag(this);

        int result=fileOpenDiag.exec();

        if(!(result==QDialog::Accepted))
            return;

        auto path=fileOpenDiag.getFilename();

        if(path.isEmpty())
            return;

        std::unique_ptr<YuvInfoDialog> infoDialog;
        bool inputValid=true;
        do {
            infoDialog=std::make_unique<YuvInfoDialog>(this);
            inputValid=true;

            result=infoDialog->exec();
            if(!(result==QDialog::Accepted))
                return;

            if(infoDialog->getFps()<=0) {
                inputValid=false;
                continue;
            }
            if(infoDialog->getHeight()<=0) {
                inputValid=false;
                continue;
            }
            if(infoDialog->getWidth()<=0) {
                inputValid=false;
                continue;
            }

        } while(!inputValid);

        std::unique_ptr<Model::YuvVideo> yuvVideo =std::make_unique<Model::YuvVideo>(path,infoDialog->getPixelSheme(),
                      infoDialog->getCompression(),infoDialog->getWidth(),infoDialog->getHeight(),infoDialog->getFps());

        UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::LoadAnalysisVideo(this,std::move(yuvVideo)));

    } else {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Video files (*.txt)"));
        if(fileName.size() > 0) {
        }

    }
}

void GUI::AnalysisTab::saveResults() {

}

void GUI::AnalysisTab::setRawVideo(std::unique_ptr<Model::YuvVideo> video) {
	rawVideo_=std::move(video);
	player_->setVideo(&rawVideo_->getVideo());
}

