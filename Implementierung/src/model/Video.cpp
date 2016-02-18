#include "Video.h"

#include <QImage>

#include <vector>
#include <memory>

Model::Video::Video(int fps) noexcept :
fps_(fps),width_(0),height_(0),isComplete_(false) {

}

int Model::Video::getWidth() const noexcept {
	return width_;
}

int Model::Video::getHeight() const noexcept {
	return height_;
}

int Model::Video::getFps() const noexcept {
	return fps_;
}

void Model::Video::setFps(int fps) {
    fps_=fps;
}

QImage* Model::Video::getFrame(std::size_t index) noexcept {
	if(index>=frames_.size())
		return nullptr;
	return frames_[index].get();
}

bool Model::Video::insertFrame(std::unique_ptr<QImage> frame, std::size_t index) {
	if(frames_.empty()) {
		width_=frame->width();
		height_=frame->height();
	}
	if(frame->width()!=width_||frame->height()!=height_)
		return false;

	if(index>frames_.size())
		return false;

	frames_.insert(frames_.begin() + index, std::move(frame));

	return true;
}

void Model::Video::removeFrame(std::size_t index) {
	if(index>=frames_.size())
		return;
	frames_.erase(frames_.begin()+index);

	if(frames_.empty()) {
		width_=0;
		height_=0;
	}
}

bool Model::Video::appendFrame(std::unique_ptr<QImage> frame) {
	if(frames_.empty()) {
		width_=frame->width();
		height_=frame->height();
	}
	if(frame->width()!=width_||frame->height()!=height_)
		return false;

	frames_.push_back(std::move(frame));
}

bool Model::Video::insertFrames(std::vector<std::unique_ptr<QImage> >& frames, std::size_t index) {
	bool returnVal=true;

	if(index>frames_.size())
		return false;

	for(std::size_t i=index; i<index+frames.size(); i++) {
		returnVal&=insertFrame(std::move(frames[i-index]),i);
	}
	return returnVal;
}

std::size_t Model::Video::getNumberOfFrames() const noexcept {
	return frames_.size();
}

bool Model::Video::isComplete() {
	return isComplete_;
}

void Model::Video::setIsComplete(bool isComplete) {
	isComplete_=isComplete;
}
