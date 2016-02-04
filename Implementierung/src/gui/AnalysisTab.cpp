#include <exception>

#include <QWidget>
#include <QFrame>

#include "AnalysisTab.h"
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

}

Memento::AnalysisTabMemento GUI::AnalysisTab::getMemento() {
	throw "Not yet implemented";
}

void GUI::AnalysisTab::restore(Memento::AnalysisTabMemento memento) {
	throw "Not yet implemented";
}

void GUI::AnalysisTab::analyseTypChanged(int index) {
	throw "Not yet implemented";
}

void GUI::AnalysisTab::addVideo() {
	throw "Not yet implemented";
}

void GUI::AnalysisTab::loadRawVideo() {
	throw "Not yet implemented";
}

void GUI::AnalysisTab::saveResults() {
	throw "Not yet implemented";
}

/*void GUI::AnalysisTab::setRawVideo(Model::YuvVideo video) {
	throw "Not yet implemented";
}*/

