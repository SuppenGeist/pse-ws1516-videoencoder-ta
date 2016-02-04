#include "AnalysisBox.h"

#include <QFrame>
#include <QWidget>

#include "AnalysisBoxContainer.h"
#include "VideoPlayer.h"
#include "GraphWidget.h"
#include "Timer.h"
#include "../memento/AnalysisBoxMemento.h"
#include "../model/EncodedVideo.h"
#include "../undo_framework/RemoveVideo.h"

GUI::AnalysisBox::AnalysisBox(QWidget* parent) {
}

Memento::AnalysisBoxMemento GUI::AnalysisBox::getMemento() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::restore(Memento::AnalysisBoxMemento memento) {
	throw "Not yet implemented";
}

/*void AnalysisBox::setTimer(shared_ptrshared_ptr<GUI::Timer> timer:std:) {
    throw "Not yet implemented";
}
*/
void GUI::AnalysisBox::setRawVideo(Model::Video* video) {
	this->rawVideo = video;
}

void GUI::AnalysisBox::setControlPanel(GUI::GlobalControlPanel* panel) {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::showMacroBlockVideo() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::showRGBDifferenceVideo() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::close() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::textChanged() {
	throw "Not yet implemented";
}

void GUI::AnalysisBox::setAnalyseVideo(Model::EncodedVideo video) {
	throw "Not yet implemented";
}
