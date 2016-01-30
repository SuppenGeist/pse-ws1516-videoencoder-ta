#include "AnalysisTabMemento.h"

#include "AnalysisBoxContainerMemento.h"

Memento::AnalysisTabMemento::AnalysisTabMemento() {
}

int Memento::AnalysisTabMemento::getCurrentVideoPosition() {
	return this->currentVideoPosition;
}

void Memento::AnalysisTabMemento::setCurrentVideoPosition(int currentVideoPosition) {
	this->currentVideoPosition = currentVideoPosition;
}

int Memento::AnalysisTabMemento::getCurrentlyShownAnalysisVideo() {
	throw "Not yet implemented";
}

void Memento::AnalysisTabMemento::setCurrentlyShownAnalysisVideo(int currentlyShownAnalysisVideo) {
	throw "Not yet implemented";
}

float Memento::AnalysisTabMemento::getCurrentSpeed() {
	return this->currentSpeed;
}

void Memento::AnalysisTabMemento::setCurrentSpeed(float currentSpeed) {
	this->currentSpeed = currentSpeed;
}

Memento::AnalysisBoxContainerMemento Memento::AnalysisTabMemento::getAnalysisBoxContainerMemento() {
	throw "Not yet implemented";
}

void Memento::AnalysisTabMemento::setAnalysisBoxContainerMemento(AnalysisBoxContainerMemento analysisBoxContainerMemento) {
	throw "Not yet implemented";
}
