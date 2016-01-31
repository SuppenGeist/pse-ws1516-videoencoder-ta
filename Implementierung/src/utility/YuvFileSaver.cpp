#include "YuvFileSaver.h"

#include "../model/Video.h"

Utility::YuvFileSaver::YuvFileSaver(QString filename, Model::Video& video):width_(video.getWidth()),
	height_(video.getHeight()),video_(&video),file_(filename) {
	file_.open(QIODevice::WriteOnly);
	dataStream_.setDevice(&file_);
}


Utility::YuvFileSaver::~YuvFileSaver() {
	file_.flush();
	file_.close();
}
