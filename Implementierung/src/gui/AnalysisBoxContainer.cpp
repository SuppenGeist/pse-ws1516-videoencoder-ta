#include "AnalysisBoxContainer.h"

#include <vector>
#include <QWidget>
#include <QFrame>
#include <QUndoStack>
#include <memory>

#include "../model/Video.h"
#include "Timer.h"
#include "AnalysisTab.h"
#include "AnalysisBox.h"
#include "../memento/AnalysisBoxContainerMemento.h"
#include "../model/EncodedVideo.h"
#include "../undo_framework/RemoveVideo.h"
#include "ui_analysisboxcontainer.h"
#include "../undo_framework/UndoStack.h"
#include "../memento/AnalysisBoxContainerMemento.h"
#include "../memento/AnalysisBoxMemento.h"

GUI::AnalysisBoxContainer::AnalysisBoxContainer(QWidget* parent) : QFrame(parent) {

    ui_ = new Ui::AnalysisBoxContainer;
    ui_->setupUi(this);
	AnalysisBox *a = new AnalysisBox(this);
    ui_->verticalLayout->addWidget(a);
    boxes_.push_back(a);
    a = new AnalysisBox(this);
        ui_->verticalLayout->addWidget(a);
        boxes_.push_back(a);
}

Memento::AnalysisBoxContainerMemento GUI::AnalysisBoxContainer::getMemento() {
    Memento::AnalysisBoxContainerMemento memo;
    std::vector<Memento::AnalysisBoxMemento> memoList;
    for(int i = 0; i < boxes_.size(); i++) {
        memoList.push_back(boxes_[i]->getMemento());
    }
    memo.setAnalysisBoxList(memoList);
    return memo;
}

void GUI::AnalysisBoxContainer::restore(Memento::AnalysisBoxContainerMemento memento) {
    std::vector<Memento::AnalysisBoxMemento> memoList = memento.getAnalysisBoxList();
    AnalysisBox* anaBox;
    for(int i = 0; i < memoList.size(); i++) {
        anaBox = new AnalysisBox(this);
        anaBox->restore(memoList[1]);
        anaBox->setRawVideo(rawVideo_);
        ui_->verticalLayout->addWidget(anaBox);
        boxes_.push_back(anaBox);
        if(255* boxes_.size() > height()) {
            resize(height()+255,width());
        }
    }
}

void GUI::AnalysisBoxContainer::addVideo(QString path) {
	AnalysisBox* anaBox = new AnalysisBox(this);
    anaBox->setRawVideo(rawVideo_);
	anaBox->setAnalyseVideo(std::make_unique<Model::EncodedVideo>(path));
    ui_->verticalLayout->addWidget(anaBox);
    boxes_.push_back(anaBox);
    if(255* boxes_.size() > height()) {
		resize(height()+255,width());
	}
}

void GUI::AnalysisBoxContainer::setRawVideo(Model::Video* video) {
    rawVideo_ = video;
}

void GUI::AnalysisBoxContainer::setTimer(std::shared_ptr<GUI::Timer> timer) {
    this->timer = timer;
}

void GUI::AnalysisBoxContainer::setControlPanel(GUI::GlobalControlPanel* panel) {
    controlPanel_ = panel;
    for (AnalysisBox* anaBox : boxes_) {
        anaBox->setControlPanel(controlPanel_);
    }
}

void GUI::AnalysisBoxContainer::showMacroBlockVideos() {

}

void GUI::AnalysisBoxContainer::showRGBDifferenceVideos() {
    for (AnalysisBox* & anaBox : boxes_) {
        anaBox->showRGBDifferenceVideo();
    }
}

void GUI::AnalysisBoxContainer::removeBox(AnalysisBox* box) {
    box->setObjectName("toBeDeleted");
    for (int i = 0; i < boxes_.size(); i++) {
        if(boxes_[i]->objectName() == box->objectName()) {
            delete boxes_[i];
            boxes_.erase(boxes_.begin() + i);
        }
    }
    if(255* boxes_.size()-255 > height()) {
        resize(height()-255,width());
    }
}

GUI::AnalysisBox* GUI::AnalysisBoxContainer::addVideo(Model::EncodedVideo video) {
    AnalysisBox* anaBox = new AnalysisBox(this);
    /*anaBox->setRawVideo(rawVideo_);
    anaBox->setAnalyseVideo(make_unique(video));
    ui_->verticalLayout->addWidget(anaBox);
    boxes_.push_back(anaBox);
    if(255* width() > height()) {
	    resize(height()+255,width());
    }
    if(255* boxes_.size() > height()) {
        resize(height()+255,width());
    }
    //something to set rgbDif/Makroblock video
    return anaBox;
    */

}


