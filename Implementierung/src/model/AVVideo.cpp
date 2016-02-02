#include "AVVideo.h"


Model::AVVideo::AVVideo(int fps, int width, int height):fps_(fps),width_(width),height_(height) {

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

    return video_[index].get();
}

bool Model::AVVideo::insertFrame(std::unique_ptr<AVFrame> frame, std::size_t index) {
    if(frame->width!=width_||frame->height!=height_)
        return false;

    if(index>video_.size())
        return false;

    video_.insert(video_.begin() + index, std::move(frame));

    return true;
}

void Model::AVVideo::removeFrame(std::size_t index) {
    if(index < video_.size())
        video_.erase(video_.begin() + index);
}

bool Model::AVVideo::insertFrames(std::vector<std::unique_ptr<AVFrame>>& frames, std::size_t index) {
    bool returnVal=true;

    if(index>video_.size())
        return false;

    for(std::size_t i=index;i<index+frames.size();i++) {
        returnVal&=insertFrame(std::move(frames[i-index]),i);
    }
    return returnVal;
}

int Model::AVVideo::getNumberOfFrames() {
    return video_.size();
}

