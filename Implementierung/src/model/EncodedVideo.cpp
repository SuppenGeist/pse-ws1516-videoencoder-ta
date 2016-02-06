#include "EncodedVideo.h"

#include "Video.h"
#include "AVVideo.h"
#include "Graph.h"

Model::EncodedVideo::EncodedVideo(QString path) {
}

QString Model::EncodedVideo::getPath() {
	return this->path;
}

int Model::EncodedVideo::getFileSize() {
	return this->fileSize;
}

int Model::EncodedVideo::getNumberOfColors() {
	return this->numberOfColors;
}

QString Model::EncodedVideo::getCodec() {
	return this->codec;
}

Model::Graph& Model::EncodedVideo::getBitrate() {
	throw "Not yet implemented";
}

Model::Graph& Model::EncodedVideo::getPsnr() {
	throw "Not yet implemented";
}

Model::Graph& Model::EncodedVideo::getRedHistogramm() {
	throw "Not yet implemented";
}

Model::Graph& Model::EncodedVideo::getBlueHistogramm() {
	throw "Not yet implemented";
}

Model::Graph& Model::EncodedVideo::getGreenHistogramm() {
	throw "Not yet implemented";
}

Model::AVVideo& Model::EncodedVideo::getAvVideo() {
	throw "Not yet implemented";
}

Model::Video& Model::EncodedVideo::getMacroBlockVideo() {
	throw "Not yet implemented";
}

Model::Video& Model::EncodedVideo::getRgbDiffVideo(Video* reference) {
	throw "Not yet implemented";
}

Model::Video& Model::EncodedVideo::getVideo() {
	throw "Not yet implemented";
}

void Model::EncodedVideo::loadVideo() {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setBitrate(Graph graph) {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setPsnr(Graph graph) {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setRedHistogramm(Graph graph) {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setGreenHistogramm(Graph graph) {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setBlueHistogramm(Graph graph) {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setMacroblockVideo(Video video) {
	throw "Not yet implemented";
}

void Model::EncodedVideo::setRgbDiffVideo(Video video) {
	throw "Not yet implemented";
}
