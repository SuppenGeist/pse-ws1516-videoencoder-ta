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

bool Model::Video::insertFrame(std::unique_ptr<QImage> frame, std::size_t index) {
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
}

void Model::Video::appendFrame(std::unique_ptr<QImage> frame) {
	frames_.push_back(std::move(frame));
}

bool Model::Video::insertFrames(std::vector<std::unique_ptr<QImage> >& frames, std::size_t index) {
    bool returnVal=true;

    if(index>frames_.size())
        return false;

    for(std::size_t i=index;i<index+frames.size();i++) {
        returnVal&=insertFrame(std::move(frames[i-index]),i);
    }
    return returnVal;
}

std::size_t Model::Video::getNumberOfFrames() const noexcept {
	return frames_.size();
}
