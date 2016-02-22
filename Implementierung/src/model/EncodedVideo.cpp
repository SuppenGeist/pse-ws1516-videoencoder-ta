#include "EncodedVideo.h"

#include <QDebug>

#include "AVVideo.h"

#include "../utility/BitrateCalculator.h"

Model::EncodedVideo::EncodedVideo(QString path):path_(path) {

}

Model::EncodedVideo::~EncodedVideo() {
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

Model::GraphVideo &Model::EncodedVideo::getRedHistogram() {
	if(!redHisto_.get()) {
                calculateHistograms();
	}

	return *redHisto_;
}

Model::GraphVideo &Model::EncodedVideo::getBlueHistogram() {
	if(!blueHisto_.get()) {
                calculateHistograms();
	}

	return *blueHisto_;
}

Model::GraphVideo &Model::EncodedVideo::getGreenHistogram() {
	if(!greenHisto_.get()) {
                calculateHistograms();
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
        av_dict_set(&dict, "vismv", "pf+bf+bb", 0);
		macroblockLoader_ = std::make_unique<Utility::VideoLoader>(path_, dict);
		macroblockLoader_->loadVideo(macroblockAVVideo_.get());
		macroblockVideo_=std::make_unique<Video>();
        macroblockConverter_=std::make_unique<Utility::VideoConverter>(macroblockAVVideo_.get());
        macroblockConverter_->convertAVVideoToVideo(macroblockVideo_.get());
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
            rgbDiffVideo_->setIsComplete(true);
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
        videoConverter_=std::make_unique<Utility::VideoConverter>(avVideo_.get());
        videoConverter_->convertAVVideoToVideo(video_.get());
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

void Model::EncodedVideo::calculateHistograms() {
	redHisto_=std::make_unique<GraphVideo>();
	greenHisto_=std::make_unique<GraphVideo>();
	blueHisto_=std::make_unique<GraphVideo>();

        rgbHistoCalculator_=std::make_unique<Utility::RGBHistogramCalculator>(getVideo());
	rgbHistoCalculator_->calculate(redHisto_.get(),greenHisto_.get(),blueHisto_.get());
}
