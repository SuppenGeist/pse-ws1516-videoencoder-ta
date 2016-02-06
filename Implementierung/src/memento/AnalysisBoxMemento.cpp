

#include "AnalysisBoxMemento.h"
#include "../model/Video.h"
#include "../model/Graph.h"

Memento::AnalysisBoxMemento::AnalysisBoxMemento() {
}

QString Memento::AnalysisBoxMemento::getVideoPath() {
	return this->videoPath;
}

void Memento::AnalysisBoxMemento::setVideoPath(QString videoPath) {
	this->videoPath = videoPath;
}

QString Memento::AnalysisBoxMemento::getComment() {
	return this->comment;
}

void Memento::AnalysisBoxMemento::setComment(QString comment) {
	this->comment = comment;
}

Model::Video* Memento::AnalysisBoxMemento::getMacroVideo() {
	return this->macroVideo;
}

void Memento::AnalysisBoxMemento::setMacroVideo(Model::Video* macroVideo) {
	this->macroVideo = macroVideo;
}

Model::Video* Memento::AnalysisBoxMemento::getRgbDiffVideo() {
	return this->rgbDiffVideo;
}

void Memento::AnalysisBoxMemento::setRgbDiffVideo(Model::Video* rgbDiffVideo) {
	this->rgbDiffVideo = rgbDiffVideo;
}

Model::Graph Memento::AnalysisBoxMemento::getPsnr() {
	return this->psnr;
}

void Memento::AnalysisBoxMemento::setPsnr(Model::Graph psnr) {
	this->psnr = psnr;
}

Model::Graph Memento::AnalysisBoxMemento::getBitrate() {
	return this->bitrate;
}

void Memento::AnalysisBoxMemento::setBitrate(Model::Graph bitrate) {
	this->bitrate = bitrate;
}


