#include "EncodedVideo.h"

Model::EncodedVideo::EncodedVideo(QString path) {
    this->path = path;
    this->loadVideo();
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
    return *(this->bitrate);
}

Model::Graph& Model::EncodedVideo::getPsnr(Video *reference) {
    if(this->psnr == NULL && reference != NULL) {
        Utility::PsnrCalculator psnrCalculator = Utility::PsnrCalculator(*(reference), *(this->video));
        this->psnr = new Graph(psnrCalculator.calculate());
    }
    return *(this->psnr);
}

Model::Graph& Model::EncodedVideo::getRedHistogramm() {
    if(this->redHisto == NULL) {
        calculateHistogramms();
    }
    return *(this->redHisto);
}

Model::Graph& Model::EncodedVideo::getBlueHistogramm() {
    if(this->blueHisto == NULL) {
        calculateHistogramms();
    }
    return *(this->blueHisto);
}

Model::Graph& Model::EncodedVideo::getGreenHistogramm() {
    if(this->greenHisto == NULL) {
        calculateHistogramms();
    }
    return *(this->greenHisto);
}

Model::AVVideo& Model::EncodedVideo::getAvVideo() {
    return *(this->avVideo);
}

Model::Video& Model::EncodedVideo::getMacroBlockVideo() {
    return *(this->macroblockVideo);
}

Model::Video& Model::EncodedVideo::getRgbDiffVideo(Video *reference) {
    if(this->rgbDiffVideo == NULL && reference != NULL) {
        Utility::RGBDifferenceCalculator rgbDifferenceCalculator = Utility::RGBDifferenceCalculator(*reference, *(this->video));
        this->rgbDiffVideo = new Video(this->video->getFps(), this->video->getWidth(), this->video->getHeight());
        rgbDifferenceCalculator.calculateVideo(*(this->rgbDiffVideo));
    }
    return *(this->rgbDiffVideo);
}

Model::Video& Model::EncodedVideo::getVideo() {
    return *(this->video);
}

void Model::EncodedVideo::loadVideo() {
    Utility::VideoLoader loader = Utility::VideoLoader(this->path);
    this->avVideo = loader.loadVideo().get();
    this->video = Utility::VideoConverter::convertAVVideoToVideo(*(this->avVideo)).get();
}

void Model::EncodedVideo::setBitrate(Graph graph) {
    this->bitrate = &graph;
}

void Model::EncodedVideo::setPsnr(Graph graph) {
    this->psnr = &graph;
}

void Model::EncodedVideo::setRedHistogramm(Graph graph) {
    this->redHisto = &graph;
}

void Model::EncodedVideo::setGreenHistogramm(Graph graph) {
    this->greenHisto = &graph;
}

void Model::EncodedVideo::setBlueHistogramm(Graph graph) {
    this->blueHisto = &graph;
}

void Model::EncodedVideo::setMacroblockVideo(Video video) {
    this->macroblockVideo = &video;
}

void Model::EncodedVideo::setRgbDiffVideo(Video video) {
    this->rgbDiffVideo = &video;
}

void Model::EncodedVideo::calculateHistogramms(){
    Utility::RGBHistogrammCalculator histogrammCalculator = Utility::RGBHistogrammCalculator(*(this->video));
    histogrammCalculator.calculate();
    this->greenHisto = histogrammCalculator.getGreenHistogramm();
    this->redHisto = histogrammCalculator.getRedHistogramm();
    this->blueHisto = histogrammCalculator.getBlueHistogramm();
}
