#include "AVVideo.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

Model::AVVideo::AVVideo(int fps, int width, int height):fps_(fps),width_(width),height_(height) {

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

AVFrame* Model::AVVideo::getFrame(std::size_t index) {
	if(index>=video_.size())
		return nullptr;

	return video_[index];
}

bool Model::AVVideo::insertFrame(AVFrame *frame, std::size_t index) {
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
	if(frame->width!=width_||frame->height!=height_)
		return false;

	video_.push_back(frame);
}

std::size_t Model::AVVideo::getNumberOfFrames() {
	return video_.size();
}

