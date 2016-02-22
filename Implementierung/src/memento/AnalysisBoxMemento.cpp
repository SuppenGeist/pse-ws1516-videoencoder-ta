#include "AnalysisBoxMemento.h"

#include <QString>
#include <QFile>
#include <QFileInfo>

Memento::AnalysisBoxMemento::AnalysisBoxMemento():path_(""),comment_(""),macroblockVideo_(nullptr),rgbDiffVideo_(nullptr),redHistogram_(nullptr) {

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

void Memento::AnalysisBoxMemento::setPsnrGraph(Model::Graph *graph)
{
    psnrGraph_=graph;
}

Model::Graph *Memento::AnalysisBoxMemento::getPsnrGraph()
{
    return psnrGraph_;
}

void Memento::AnalysisBoxMemento::setBitrateGraph(Model::Graph *graph)
{
    bitrateGraph_=graph;
}

Model::Graph *Memento::AnalysisBoxMemento::getBitrateGraph()
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

void Memento::AnalysisBoxMemento::setRedHistogram(Model::GraphVideo *video)
{
    redHistogram_=video;
}

Model::GraphVideo *Memento::AnalysisBoxMemento::getRedHistogram()
{
    return redHistogram_;
}

void Memento::AnalysisBoxMemento::setGreenHistogram(Model::GraphVideo *video)
{
    greenHistogram_=video;
}

Model::GraphVideo *Memento::AnalysisBoxMemento::getGreenHistogram()
{
    return greenHistogram_;
}

void Memento::AnalysisBoxMemento::setBlueHistogram(Model::GraphVideo *video)
{
    blueHistogram_=video;
}

Model::GraphVideo *Memento::AnalysisBoxMemento::getBlueHistogram()
{
    return blueHistogram_;
}
