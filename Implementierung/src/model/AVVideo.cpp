#include <exception>
#include <vector>
#include <memory>

#include "AVVideo.h"
#include "EncodedVideo.h"


using namespace Model;

AVVideo::AVVideo(int fps, int width, int height) {
    this->width = width;
    this->fps = fps;
    this->height = height;
    video = * new vector<unique_ptr<AVFrame>>;
}

int AVVideo::getWidth() {
	return this->width;
}

int AVVideo::getHeight() {
	return this->height;
}

int AVVideo::getFps() {
	return this->fps;
}

AVFrame* AVVideo::getFrame(int index) {
    return video.at(index).get();
}

void AVVideo::insertFrame(unique_ptr<AVFrame> frame, int index) {
    video.insert(video.begin() + index, frame);
}

void AVVideo::removeFrame(int index) {
    if(index < video.size())
        video.erase(video.begin() + index);
}

void AVVideo::insertFrames(vector<unique_ptr<AVFrame>>& frames, int index) {
    if(index <= video.size())
        video.insert(video.begin() + index, frames.begin(), frames.end());
}

int AVVideo::getNumberOfFrames() {
    return video.size();
}


