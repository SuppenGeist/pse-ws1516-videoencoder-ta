#include "Video.h"

#include <QImage>

#include <vector>
#include <memory>

Model::Video::Video(int fps, int width, int height) noexcept :
fps_(fps),width_(width),height_(height) {

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

QImage* Model::Video::getFrame(std::size_t index) noexcept {
	if(index>=frames_.size())
		return nullptr;
	return frames_[index].get();
}

void Model::Video::insertFrame(std::unique_ptr<QImage> frame, std::size_t index) {
	if(index>=frames_.size())
		return;
	frames_.insert(frames_.begin()+index,std::move(frame));
}

void Model::Video::removeFrame(std::size_t index) {
	if(index>=frames_.size())
		return;
	frames_.erase(frames_.begin()+index);
}

void Model::Video::appendFrame(std::unique_ptr<QImage> frame) {
	frames_.push_back(std::move(frame));
}

void Model::Video::insertFrames(std::vector<std::unique_ptr<QImage> >& frames, std::size_t index) {
	if(index>=frames_.size())
		return;
	frames_.insert(frames_.begin()+index,std::make_move_iterator(frames.begin()),
	               std::make_move_iterator(frames.end()));
}

std::size_t Model::Video::getNumberOfFrames() const noexcept {
	return frames_.size();
}
