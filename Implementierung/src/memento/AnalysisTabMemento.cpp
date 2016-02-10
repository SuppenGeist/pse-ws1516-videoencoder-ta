#include "AnalysisTabMemento.h"

#include "AnalysisBoxContainerMemento.h"

Memento::AnalysisTabMemento::AnalysisTabMemento() {
}

int Memento::AnalysisTabMemento::getCurrentVideoPosition() {
	return this->currentVideoPosition_;
}

void Memento::AnalysisTabMemento::setCurrentVideoPosition(int currentVideoPosition) {
	this->currentVideoPosition_ = currentVideoPosition;
}

int Memento::AnalysisTabMemento::getCurrentlyShownAnalysisVideo() {
	return currentlyShownAnalyseVideo_;
}

void Memento::AnalysisTabMemento::setCurrentlyShownAnalysisVideo(int currentlyShownAnalysisVideo) {
	this->currentlyShownAnalyseVideo_ = currentlyShownAnalysisVideo;
}

float Memento::AnalysisTabMemento::getCurrentSpeed() {
	return this->currentSpeed_;
}

void Memento::AnalysisTabMemento::setCurrentSpeed(float currentSpeed) {
	this->currentSpeed_ = currentSpeed;
}

Memento::AnalysisBoxContainerMemento Memento::AnalysisTabMemento::getAnalysisBoxContainerMemento() {
	return containerMemo_;
}

void Memento::AnalysisTabMemento::setAnalysisBoxContainerMemento(AnalysisBoxContainerMemento
        analysisBoxContainerMemento) {
	containerMemo_ = analysisBoxContainerMemento;
}
std::string Memento::AnalysisTabMemento::getLoadedFile() {
	return yuvPath_;
}

void Memento::AnalysisTabMemento::setLoadedFile(std::string loadedFile) {
	yuvPath_ = loadedFile;
}

int Memento::AnalysisTabMemento::getFps() {
	return yuvFps_;
}


int Memento::AnalysisTabMemento::getWidth() {
	return yuvWidth_;
}


int Memento::AnalysisTabMemento::getHeight() {
	return yuvHeight_;
}

Utility::Compression Memento::AnalysisTabMemento::getCompression() {
	return yuvCompession_;
}

Utility::YuvType Memento::AnalysisTabMemento::getPixelSheme() {
	return yuvPixelScheme_;
}

void Memento::AnalysisTabMemento::setFps(int fps) {
	yuvFps_ = fps;
}

void Memento::AnalysisTabMemento::setWidth(int width) {
	yuvWidth_ = width;
}

void Memento::AnalysisTabMemento::setHeight(int height) {
	yuvHeight_ = height;
}

void Memento::AnalysisTabMemento::setCompression(Utility::Compression comp) {
	yuvCompession_ = comp;
}

void Memento::AnalysisTabMemento::setPixelSheme(Utility::YuvType sheme) {
	yuvPixelScheme_ = sheme;
}
