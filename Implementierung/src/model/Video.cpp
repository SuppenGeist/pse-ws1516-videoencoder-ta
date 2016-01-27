#include "Video.h"

#include <QImage>

#include <vector>

Model::Video::Video(int fps, int width, int height) noexcept :fps_(fps),width_(width),height_(height) {

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
    return &frames_[index];
}

void Model::Video::insertFrame(const QImage& frame, std::size_t index) {
    if(index>=frames_.size())
        return;
    frames_.insert(frames_.begin()+index,frame);
}

void Model::Video::removeFrame(std::size_t index) {
    if(index>=frames_.size())
        return;
    frames_.erase(frames_.begin()+index);
}

void Model::Video::appendFrame(const QImage& frame) {
    frames_.push_back(frame);
}

void Model::Video::insertFrames(const std::vector<QImage>& frames, std::size_t index) {
    if(index>=frames_.size())
        return;
    frames_.insert(frames_.begin()+index,frames.begin(),frames.end());
}

std::size_t Model::Video::getNumberOfFrames() const noexcept {
    return frames_.size();
}
