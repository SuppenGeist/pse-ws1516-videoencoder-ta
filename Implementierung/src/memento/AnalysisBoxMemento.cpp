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

void Memento::AnalysisBoxMemento::setPsnrGraph(QImage graph)
{
    psnrGraph_=graph;
}

QImage Memento::AnalysisBoxMemento::getPsnrGraph()
{
    return psnrGraph_;
}

void Memento::AnalysisBoxMemento::setBitrateGraph(QImage graph)
{
    bitrateGraph_=graph;
}

QImage Memento::AnalysisBoxMemento::getBitrateGraph()
{
    return bitrateGraph_;
}

void Memento::AnalysisBoxMemento::setEncoder(QString encoder)
{
    encoder_=encoder;
}

QString Memento::AnalysisBoxMemento::getEncoder()
{
    return encoder_;
}

void Memento::AnalysisBoxMemento::setAverageBitrate(QString bitrate)
{
    avergaeBitrate_=bitrate;
}

QString Memento::AnalysisBoxMemento::getAverageBitrate()
{
    return avergaeBitrate_;
}

void Memento::AnalysisBoxMemento::setFilename(QString filename)
{
    filename_=filename;
}

QString Memento::AnalysisBoxMemento::getFilename()
{
    return filename_;
}

void Memento::AnalysisBoxMemento::setFilesize(QString size)
{
    filesize_=size;
}

QString Memento::AnalysisBoxMemento::getFilesize()
{
    return filesize_;
}
