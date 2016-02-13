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
#include "ForwardPlayer.h"
#include "../utility/ProjectWriter.h"
#include "AnalysisTab.h"
#include "MainWindow.h"
#include "../model/Project.h"
#include "../utility/Compression.h"
#include "../utility/YuvType.h"

GUI::AnalysisTab::AnalysisTab(QWidget* parent) : QFrame(parent) {

	ui_ = new Ui::AnalysisTab;
	ui_->setupUi(this);

    button_addVideo_ = ui_->addVideo;
    button_save_ = ui_->save;
    comboBox_analyseTyp_ = ui_->analysisTyp;
    tab_properties_ = ui_->properties;

    connect(button_save_,SIGNAL(clicked()),this,SLOT(saveResults()));
    connect(button_addVideo_,SIGNAL(clicked()),this,SLOT(addVideo()));
    connect(comboBox_analyseTyp_,SIGNAL(currentIndexChanged(int)), this, SLOT(analyseTypChanged(int)));

    rawVideoView_ = new FrameView;
    ui_->rawVidCon->addWidget(rawVideoView_);
    rawVideoView_->setMaximumWidth(600);
    rawVideoView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

	analysisBoxContainer_ = new GUI::AnalysisBoxContainer(this);
    ui_->scrollArea->setWidget(analysisBoxContainer_);

    playerPanel_ =new PlayerControlPanel(ui_->panel);
	player_=std::make_unique<VideoPlayer>();

    player_->addView(*rawVideoView_);
	player_->setTimer(std::make_shared<Timer>());
	playerPanel_->setMasterVideoPlayer(*player_);
	player_->setMasterControlPanel(*playerPanel_);

	/*
	ForwardPlayer fp = ForwardPlayer();
	playerPanel_->setMasterVideoPlayer(fp);
	GlobalControlPanel* gp = new GlobalControlPanel();
	fp.setForwardControlPanel(gp);
	analysisBoxContainer_->setControlPanel(gp);
    */

}

Memento::AnalysisTabMemento GUI::AnalysisTab::getMemento() {
	Memento::AnalysisTabMemento memo;
	memo.setAnalysisBoxContainerMemento(analysisBoxContainer_->getMemento());
	memo.setCurrentSpeed(player_->getSpeed());
	memo.setCurrentVideoPosition(player_->getPosition());
    memo.setCurrentlyShownAnalysisVideo(comboBox_analyseTyp_->currentIndex());
	memo.setCompression(rawVideo_->getCompression());
	memo.setFps(rawVideo_->getFps());
	memo.setHeight(rawVideo_->getHeight());
	memo.setWidth(rawVideo_->getWidth());
	memo.setPixelSheme(rawVideo_->getYuvType());
	return memo;
}

void GUI::AnalysisTab::restore(Memento::AnalysisTabMemento memento) {
	analysisBoxContainer_->restore(memento.getAnalysisBoxContainerMemento());

    comboBox_analyseTyp_->setCurrentIndex(memento.getCurrentlyShownAnalysisVideo());
	rawVideo_=std::make_unique<Model::YuvVideo>(QString::fromStdString(memento.getLoadedFile()),
	          memento.getPixelSheme(),
	          memento.getCompression(),
	          memento.getWidth(),
	          memento.getHeight(),
	          memento.getFps());
	player_->setVideo(&rawVideo_->getVideo());
	player_->setSpeed(memento.getCurrentSpeed());
	player_->setPosition(memento.getCurrentVideoPosition());
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
	player_->reset();
    button_addVideo_->setText("Add Raw Video");
	return std::move(video);
}

void GUI::AnalysisTab::loadYuvVideo(std::unique_ptr<Model::YuvVideo> video) {
	player_->setVideo(&video->getVideo());
	rawVideo_=std::move(video);
    button_addVideo_->setText("Add Video");
}
void GUI::AnalysisTab::setProject(Model::Project *project) {
	project_ = project;
}

void GUI::AnalysisTab::addVideo() {
    if(button_addVideo_->text() == QString("Add Raw Video")) {
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

		std::unique_ptr<Model::YuvVideo> yuvVideo =std::make_unique<Model::YuvVideo>(path,
		        infoDialog->getPixelSheme(),
		        infoDialog->getCompression(),infoDialog->getWidth(),infoDialog->getHeight(),infoDialog->getFps());

		UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::LoadAnalysisVideo(this,std::move(yuvVideo)));

	} else {
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/",
		                   tr("Video files (*.mp4 *.avi *flv)"));
		if(fileName.size() > 0) {
			analysisBoxContainer_->addVideo(fileName);
		}

	}
}

void GUI::AnalysisTab::saveResults() {
	Utility::ProjectWriter *pWriter = new Utility::ProjectWriter(*project_);
	pWriter->saveResults();
}

void GUI::AnalysisTab::setRawVideo(std::unique_ptr<Model::YuvVideo> video) {
	rawVideo_=std::move(video);
	player_->setVideo(&rawVideo_->getVideo());
}

