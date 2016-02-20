#include "EncodedVideo.h"

#include <QDebug>

#include "AVVideo.h"

#include "../utility/BitrateCalculator.h"

Model::EncodedVideo::EncodedVideo(QString path):path_(path),isConverterRunning_(false) {

}

Model::EncodedVideo::~EncodedVideo() {
	isConverterRunning_=false;
	if(converter_.joinable()) {
		converter_.join();
	}

	isMacroblockConverterRunnning_=false;
	if(macroblockConverter_.joinable()) {
		macroblockConverter_.join();
	}
}

QString Model::EncodedVideo::getPath() {
	return path_;
}

QString Model::EncodedVideo::getCodec() {
	if(!loader_.get()) {
		loadVideo();
	}
	return loader_->getCodec();
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

Model::Graph* Model::EncodedVideo::getPsnr(Video *reference) {
	if(!psnr_.get()) {
		if(getVideo().getNumberOfFrames()==0)
			return nullptr;
		if(!reference)
			return nullptr;
		if(reference->getNumberOfFrames()==0)
			return nullptr;

		psnr_=std::make_unique<Graph>();
		try {
			psnrCalculator_=std::make_unique<Utility::PsnrCalculator>(getVideo(),*reference);
		} catch(std::invalid_argument& e) {
			return psnr_.get();
		}
		psnrCalculator_->calculate(psnr_.get());
	}
	return psnr_.get();
}

Model::GraphVideo &Model::EncodedVideo::getRedHistogramm() {
	if(!redHisto_.get()) {
		calculateHistogramms();
	}

	return *redHisto_;
}

Model::GraphVideo &Model::EncodedVideo::getBlueHistogramm() {
	if(!blueHisto_.get()) {
		calculateHistogramms();
	}

	return *blueHisto_;
}

Model::GraphVideo &Model::EncodedVideo::getGreenHistogramm() {
	if(!greenHisto_.get()) {
		calculateHistogramms();
	}

	return *greenHisto_;
}

Model::AVVideo& Model::EncodedVideo::getAvVideo() {
	if(!avVideo_.get())
		loadVideo();

	return *avVideo_.get();
}

Model::Video& Model::EncodedVideo::getMacroBlockVideo() {
	if(!macroblockVideo_.get()) {
		macroblockAVVideo_ = std::make_unique<AVVideo>();
		AVDictionary *dict = NULL;
		// deprecated option vismv
		av_dict_set(&dict, "debug", "vis_mb_type", 0);
		av_dict_set(&dict, "vismv", "pf", 0);
		macroblockLoader_ = std::make_unique<Utility::VideoLoader>(path_, dict);
		macroblockLoader_->loadVideo(macroblockAVVideo_.get());
		macroblockVideo_=std::make_unique<Video>();
		macroblockConverter_=std::thread(&EncodedVideo::convertMacroblock,this);
	}
	return *macroblockVideo_;
}

Model::Video* Model::EncodedVideo::getRgbDiffVideo(Video *reference) {
	if(!rgbDiffVideo_.get()) {
		if(!reference)
			return nullptr;
		if(getVideo().getNumberOfFrames()==0)
			return nullptr;
		if(reference->getNumberOfFrames()==0)
			return nullptr;

		rgbDiffVideo_=std::make_unique<Video>();
		try {
			rgbDiffCalculator_=std::make_unique<Utility::RGBDifferenceCalculator>(*reference,getVideo());
		} catch(std::invalid_argument& e) {
			return rgbDiffVideo_.get();
		}
		rgbDiffCalculator_->calculateVideo(rgbDiffVideo_.get());
	}
	return rgbDiffVideo_.get();
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

int Model::EncodedVideo::getAverageBitrate() {
	if(!loader_.get()) {
		loadVideo();
	}
	return loader_->getAverageBitrate();
}

void Model::EncodedVideo::loadVideo() {
	if(avVideo_.get())
		return;

	avVideo_=std::make_unique<AVVideo>();

	loader_ = std::make_unique<Utility::VideoLoader>(path_);
	loader_->loadVideo(avVideo_.get());
}

void Model::EncodedVideo::convertVideo() {
	isConverterRunning_=true;

	std::size_t i=0;
	do {
		for(; i<avVideo_->getNumberOfFrames(); i++) {
			video_->appendFrame(Utility::VideoConverter::convertAVFrameToQImage(*avVideo_->getFrame(i)));
        }
    } while(isConverterRunning_&&(!avVideo_->isComplete()||avVideo_->getNumberOfFrames()!=video_->getNumberOfFrames()));
	video_->setIsComplete(true);
	isConverterRunning_=false;
    video_->setFps(avVideo_->getFps());
}

void Model::EncodedVideo::convertMacroblock() {
	isMacroblockConverterRunnning_=true;

	std::size_t i=0;
	do {
		for(; i<macroblockAVVideo_->getNumberOfFrames(); i++) {
			macroblockVideo_->appendFrame(Utility::VideoConverter::convertAVFrameToQImage(
			                                  *macroblockAVVideo_->getFrame(i)));
		}
	} while(!macroblockAVVideo_->isComplete()&&isMacroblockConverterRunnning_);

	isMacroblockConverterRunnning_=false;
	macroblockVideo_->setIsComplete(true);
	macroblockAVVideo_.reset();
}

void Model::EncodedVideo::calculateHistogramms() {
	redHisto_=std::make_unique<GraphVideo>();
	greenHisto_=std::make_unique<GraphVideo>();
	blueHisto_=std::make_unique<GraphVideo>();

	rgbHistoCalculator_=std::make_unique<Utility::RGBHistogrammCalculator>(getVideo());
	rgbHistoCalculator_->calculate(redHisto_.get(),greenHisto_.get(),blueHisto_.get());
}
