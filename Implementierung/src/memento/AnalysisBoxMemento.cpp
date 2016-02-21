#include "AnalysisBoxMemento.h"

#include <QString>
#include <QFile>
#include <QFileInfo>

Memento::AnalysisBoxMemento::AnalysisBoxMemento():path_(""),comment_(""),macroblockVideo_(nullptr),rgbDiffVideo_(nullptr) {

}

QString Memento::AnalysisBoxMemento::getPath() {
	return path_;
}

void Memento::AnalysisBoxMemento::setPath(QString path) {
    path_=path;
}

QString Memento::AnalysisBoxMemento::getComment() {
	return comment_;
}

void Memento::AnalysisBoxMemento::setComment(QString comment) {
    comment_=comment;
}

void Memento::AnalysisBoxMemento::setMacroBlockVideo(Model::Video *macroblockVideo)
{
    macroblockVideo_=macroblockVideo;
}

Model::Video *Memento::AnalysisBoxMemento::getMacroBlockVideo()
{
    return macroblockVideo_;
}

void Memento::AnalysisBoxMemento::setRgbDiffVideo(Model::Video *rgbDiffVideo)
{
    rgbDiffVideo_=rgbDiffVideo;
}

Model::Video *Memento::AnalysisBoxMemento::getRgbDiffVideo()
{
    return rgbDiffVideo_;
}
