

#include "AnalysisBoxMemento.h"
#include "../model/Video.h"
#include "../model/Graph.h"

Memento::AnalysisBoxMemento::AnalysisBoxMemento() {
}

QString Memento::AnalysisBoxMemento::getVideoPath() {
    return videoPath_;
}

void Memento::AnalysisBoxMemento::setVideoPath(QString videoPath) {
    videoPath_ = videoPath;
}

QString Memento::AnalysisBoxMemento::getComment() {
    return comment_;
}

void Memento::AnalysisBoxMemento::setComment(QString comment) {
    comment_ = comment;
}

Model::Video* Memento::AnalysisBoxMemento::getMacroVideo() {
    return macroVideo_;
}

void Memento::AnalysisBoxMemento::setMacroVideo(Model::Video* macroVideo) {
    macroVideo_ = macroVideo;
}

Model::Video* Memento::AnalysisBoxMemento::getRgbDiffVideo() {
    return rgbDiffVideo_;
}

void Memento::AnalysisBoxMemento::setRgbDiffVideo(Model::Video* rgbDiffVideo) {
    rgbDiffVideo_ = rgbDiffVideo;
}

Model::Graph Memento::AnalysisBoxMemento::getPsnr() {
    return psnr_;
}

void Memento::AnalysisBoxMemento::setPsnr(Model::Graph psnr) {
    psnr_ = psnr;
}

Model::Graph Memento::AnalysisBoxMemento::getBitrate() {
    return bitrate_;
}

void Memento::AnalysisBoxMemento::setBitrate(Model::Graph bitrate) {
    bitrate_ = bitrate;
}


