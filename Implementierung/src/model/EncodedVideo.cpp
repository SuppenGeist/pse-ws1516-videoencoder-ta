#include "EncodedVideo.h"

#include "AVVideo.h"

#include "../utility/BitrateCalculator.h"

Model::EncodedVideo::EncodedVideo(QString path):path_(path),isConverterRunning_(false) {

}

Model::EncodedVideo::~EncodedVideo()
{
    isConverterRunning_=false;
    if(converter_.joinable()) {
        converter_.join();
    }
}

QString Model::EncodedVideo::getPath() {
    return path_;
}

int Model::EncodedVideo::getNumberOfColors() {
    return numberOfColors_;
}

QString Model::EncodedVideo::getCodec() {
    return codec_;
}

Model::Graph& Model::EncodedVideo::getBitrate() {
    if(!avVideo_.get()) {
        loadVideo();
    }
    if(!bitrate_.get()) {
        bitrateCalculator_=std::make_unique<Utility::BitrateCalculator>(*avVideo_);
        bitrate_=std::make_unique<Model::Graph>();
        bitrateCalculator_->calculate(bitrate_.get());
    }

    return *bitrate_;
}

Model::Graph& Model::EncodedVideo::getPsnr(Video *reference) {
    /*if(this->psnr == NULL && reference != NULL) {
		Utility::PsnrCalculator psnrCalculator = Utility::PsnrCalculator(*(reference), *(this->video));
		this->psnr = new Graph(psnrCalculator.calculate());
	}
    return *(this->psnr);*/
    throw "";
}

Model::Graph& Model::EncodedVideo::getRedHistogramm() {
    /*if(this->redHisto == NULL) {
		calculateHistogramms();
	}
	return *(this->redHisto);
    */
    throw "";
}

Model::Graph& Model::EncodedVideo::getBlueHistogramm() {
    /*if(this->blueHisto == NULL) {
		calculateHistogramms();
	}
    return *(this->blueHisto);*/
    throw "";
}

Model::Graph& Model::EncodedVideo::getGreenHistogramm() {
    /*if(this->greenHisto == NULL) {
		calculateHistogramms();
	}
    return *(this->greenHisto);*/
    throw "";
}

Model::AVVideo& Model::EncodedVideo::getAvVideo() {
    if(!avVideo_.get())
        loadVideo();

    return *avVideo_.get();
}

Model::Video& Model::EncodedVideo::getMacroBlockVideo() {
    //return *(this->macroblockVideo);
    throw "";
}

Model::Video& Model::EncodedVideo::getRgbDiffVideo(Video *reference) {
    /*if(this->rgbDiffVideo == NULL && reference != NULL) {
		Utility::RGBDifferenceCalculator rgbDifferenceCalculator = Utility::RGBDifferenceCalculator(
		            *reference, *(this->video));
		this->rgbDiffVideo = new Video(this->video->getFps());
		rgbDifferenceCalculator.calculateVideo(*(this->rgbDiffVideo));
	}
    return *(this->rgbDiffVideo);*/
    throw "";
}

Model::Video& Model::EncodedVideo::getVideo() {
    if(!avVideo_.get()) {
        loadVideo();
    }
    if(!video_.get()) {
        video_=std::make_unique<Video>();
        converter_=std::thread(&EncodedVideo::convertVideo,this);
    }

    return *video_.get();
}

void Model::EncodedVideo::loadVideo() {
    if(avVideo_.get())
        return;

    avVideo_=std::make_unique<AVVideo>();

    loader_ = std::make_unique<Utility::VideoLoader>(path_);
    loader_->loadVideo(avVideo_.get());
}

void Model::EncodedVideo::convertVideo()
{
    isConverterRunning_=true;

    std::size_t i=0;
    do {
        for(;i<avVideo_->getNumberOfFrames();i++) {
            video_->appendFrame(Utility::VideoConverter::convertAVFrameToQImage(*avVideo_->getFrame(i)));
        }
    }while(!avVideo_->isComplete()&&isConverterRunning_);

    isConverterRunning_=false;
    video_->setFps(avVideo_->getFps());
}

void Model::EncodedVideo::calculateHistogramms() {
    /*Utility::RGBHistogrammCalculator histogrammCalculator = Utility::RGBHistogrammCalculator(*
	        (this->video));
	histogrammCalculator.calculate();
	this->greenHisto = histogrammCalculator.getGreenHistogramm();
	this->redHisto = histogrammCalculator.getRedHistogramm();
    this->blueHisto = histogrammCalculator.getBlueHistogramm();*/
    throw "";
}
