#include "AVVideo.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

Model::AVVideo::AVVideo(int fps):fps_(fps),width_(0),height_(0),isComplete_(false) {

}

Model::AVVideo::~AVVideo() {
	for(auto frame:video_) {
		av_frame_free(&frame);
	}
}

int Model::AVVideo::getWidth() {
	return width_;
}

int Model::AVVideo::getHeight() {
	return height_;
}

int Model::AVVideo::getFps() {
	return fps_;
}

void Model::AVVideo::setFps(int fps) {
	if(fps<0)
		return;
	fps_=fps;
}

AVFrame* Model::AVVideo::getFrame(std::size_t index) {
	if(index>=video_.size())
		return nullptr;

	return video_[index];
}

bool Model::AVVideo::insertFrame(AVFrame *frame, std::size_t index) {
	if(video_.empty()) {
		width_=frame->width;
		height_=frame->height;
	}
	if(frame->width!=width_||frame->height!=height_)
		return false;

	if(index>video_.size())
		return false;

	video_.insert(video_.begin() + index, frame);

	return true;
}

void Model::AVVideo::removeFrame(std::size_t index) {
	if(index < video_.size()) {
		av_frame_free(&video_[index]);
		video_.erase(video_.begin() + index);
	}
	if(video_.empty()) {
		width_=0;
		height_=0;
	}
}

bool Model::AVVideo::insertFrames(std::vector<AVFrame*>& frames,
                                  std::size_t index) {
	bool returnVal=true;

	if(index>video_.size())
		return false;

	for(std::size_t i=index; i<index+frames.size(); i++) {
		returnVal&=insertFrame(frames[i-index],i);
	}
	return returnVal;
}

bool Model::AVVideo::appendFrame(AVFrame* frame) {
	if(video_.empty()) {
		width_=frame->width;
		height_=frame->height;
	}
	if(frame->width!=width_||frame->height!=height_)
		return false;

	video_.push_back(frame);

    return true;
}

std::size_t Model::AVVideo::getNumberOfFrames() {
	return video_.size();
}

bool Model::AVVideo::isComplete() {
	return isComplete_;
}

void Model::AVVideo::setIsComplete(bool isComplete) {
	isComplete_=isComplete;
}

