#include <exception>
#include <vector>
#include <memory>

#include "AVVideo.h"
#include "EncodedVideo.h"


using namespace Model;

AVVideo::AVVideo(int fps, int width, int height) {
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
	throw "Not yet implemented";
}

void AVVideo::insertFrame(unique_ptr<AVFrame> frame, int index) {
	throw "Not yet implemented";
}

void AVVideo::removeFrame(int index) {
	throw "Not yet implemented";
}

void AVVideo::insertFrames(vector<unique_ptr<AVFrame>>& frames, int index) {
	throw "Not yet implemented";
}

int AVVideo::getNumberOfFrames() {
	throw "Not yet implemented";
}


