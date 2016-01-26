#include <exception>

#include "EncodedVideo.h"
#include "AnalysisBox.h"
#include "Video.h"
#include "AVVideo.h"
#include "Graph.h"

EncodedVideo::EncodedVideo(QString path) {
}

QString EncodedVideo::getPath() {
	return this->path;
}

int EncodedVideo::getFileSize() {
	return this->fileSize;
}

int EncodedVideo::getNumberOfColors() {
	return this->numberOfColors;
}

QString EncodedVideo::getCodec() {
	return this->codec;
}

Model::Graph& EncodedVideo::getBitrate() {
	throw "Not yet implemented";
}

Model::Graph& EncodedVideo::getPsnr() {
	throw "Not yet implemented";
}

Model::Graph& EncodedVideo::getRedHistogramm() {
	throw "Not yet implemented";
}

Model::Graph& EncodedVideo::getBlueHistogramm() {
	throw "Not yet implemented";
}

Model::Graph& EncodedVideo::getGreenHistogramm() {
	throw "Not yet implemented";
}

Model::AVVideo& EncodedVideo::getAvVideo() {
	throw "Not yet implemented";
}

GUI::Video& EncodedVideo::getMacroBlockVideo() {
	throw "Not yet implemented";
}

GUI::Video& EncodedVideo::getRgbDiffVideo(Video* reference) {
	throw "Not yet implemented";
}

GUI::Video& EncodedVideo::getVideo() {
	throw "Not yet implemented";
}

void EncodedVideo::loadVideo() {
	throw "Not yet implemented";
}

void EncodedVideo::setBitrate(Graph graph) {
	throw "Not yet implemented";
}

void EncodedVideo::setPsnr(Graph graph) {
	throw "Not yet implemented";
}

void EncodedVideo::setRedHistogramm(Graph graph) {
	throw "Not yet implemented";
}

void EncodedVideo::setGreenHistogramm(Graph graph) {
	throw "Not yet implemented";
}

void EncodedVideo::setBlueHistogramm(Graph graph) {
	throw "Not yet implemented";
}

void EncodedVideo::setMacroblockVideo(Video video) {
	throw "Not yet implemented";
}

void EncodedVideo::setRgbDiffVideo(Video video) {
	throw "Not yet implemented";
}

