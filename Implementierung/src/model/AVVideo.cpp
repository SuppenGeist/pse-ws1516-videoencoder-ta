#include <exception>

#include "AVVideo.h"
#include "EncodedVideo.h"


using namespace Model;

AVVideo::AVVideo(int fps, int width, int height) {
	this->width = width;
	this->fps = fps;
	this->height = height;
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
	video.insert(video.begin() + index, move(frame));
}

void AVVideo::removeFrame(int index) {
	if(index < video.size())
		video.erase(video.begin() + index);
}

void AVVideo::insertFrames(vector<unique_ptr<AVFrame>>& frames, int index) {
	if(index <= video.size()) {
		int i = index;
		for(vector<unique_ptr<AVFrame>>::iterator it = frames.begin(); it != frames.end(); ++it) {
			video.insert(video.begin() + i++, move(*it));
		}

	}
}

int AVVideo::getNumberOfFrames() {
	return video.size();
}

