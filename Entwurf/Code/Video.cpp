#include <exception>
#include <vector>

#include "Video.h"
#include "EncodedVideo.h"

Video::Video(int fps, int width, int height) {
}

int Video::getWidth() {
	return this->width;
}

int Video::getHeight() {
	return this->height;
}

int Video::getFps() {
	return this->fps;
}

QImage* Video::getFrame(int index) {
	throw "Not yet implemented";
}

void Video::insertFrame(int index, unique_ptrunique_ptr<QImage> frame) {
	throw "Not yet implemented";
}

void Video::removeFrame(int index) {
	throw "Not yet implemented";
}

void Video::insertFrames(int index, vectorvector<unique_ptr<QImage> >& frames) {
	throw "Not yet implemented";
}

int Video::getNumberOfFrames() {
	throw "Not yet implemented";
}

