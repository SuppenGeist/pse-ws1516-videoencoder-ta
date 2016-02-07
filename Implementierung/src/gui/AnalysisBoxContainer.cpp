#include "AnalysisBoxContainer.h"

#include <vector>
#include <QWidget>
#include <QFrame>


#include "../model/Video.h"
#include "Timer.h"
#include "AnalysisTab.h"
#include "AnalysisBox.h"
#include "../memento/AnalysisBoxContainerMemento.h"
#include "../model/EncodedVideo.h"
#include "../undo_framework/RemoveVideo.h"
#include "ui_analysisboxcontainer.h"

GUI::AnalysisBoxContainer::AnalysisBoxContainer(QWidget* parent) : QFrame(parent) {

	ui = new Ui::AnalysisBoxContainer;
	ui->setupUi(this);
	AnalysisBox *a = new AnalysisBox(this);
	ui->verticalLayout->addWidget(a);
	a = new AnalysisBox(this);
	ui->verticalLayout->addWidget(a);
	a = new AnalysisBox(this);
	ui->verticalLayout->addWidget(a);
	a = new AnalysisBox(this);
	ui->verticalLayout->addWidget(a);
}

Memento::AnalysisBoxContainerMemento GUI::AnalysisBoxContainer::getMemento() {
	throw "Not yet implemented";
}

void GUI::AnalysisBoxContainer::restore(Memento::AnalysisBoxContainerMemento memento) {
	throw "Not yet implemented";
}

void GUI::AnalysisBoxContainer::addVideo(QString path) {
	AnalysisBox* anaBox = new AnalysisBox(this);
	anaBox->setRawVideo(rawVideo);
	anaBox->setAnalyseVideo(std::make_unique<Model::EncodedVideo>(path));
	ui->verticalLayout->addWidget(anaBox);
	boxes.push_back(anaBox);
	if(255* boxes.size() > height()) {
		resize(height()+255,width());
	}
}

void GUI::AnalysisBoxContainer::setRawVideo(Model::Video* video) {
	this->rawVideo = video;
}

/*void GUI::AnalysisBoxContainer::setTimer(shared_ptrshared_ptr<GUI::Timer> timer:std:) {
	throw "Not yet implemented";
} */

void GUI::AnalysisBoxContainer::setControlPanel(GUI::GlobalControlPanel* panel) {
	this->controlPanel = panel;
}

void GUI::AnalysisBoxContainer::showMacroBlockVideos() {
	throw "Not yet implemented";
}

void GUI::AnalysisBoxContainer::showRGBDifferenceVideos() {
	throw "Not yet implemented";
}

void GUI::AnalysisBoxContainer::removeBox(AnalysisBox& box) {
	throw "Not yet implemented";
}

GUI::AnalysisBox* GUI::AnalysisBoxContainer::addVideo(Model::EncodedVideo video) {
	/*AnalysisBox* anaBox = new AnalysisBox(this);
	anaBox->setRawVideo(rawVideo);
	anaBox->setAnalyseVideo(video);
	ui->verticalLayout->addWidget(anaBox);
	boxes.push_back(anaBox);
	if(255* boxes.length > height()) {
	    resize(height()+255,width());
	}
	return &anaBox;
	*/
}


