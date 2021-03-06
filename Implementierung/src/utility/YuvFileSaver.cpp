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

int Utility::YuvFileSaver::RgbToY(QRgb pixel) {
	return (0.257*qRed(pixel)) + (0.504*qGreen(pixel)) + (0.098*qBlue(pixel))+16;
}

int Utility::YuvFileSaver::RgbToU(QRgb pixel) {
	return ((-0.148)*qRed(pixel)) - (0.291*qGreen(pixel)) + (0.439*qBlue(pixel)) + 128;
}

int Utility::YuvFileSaver::RgbToV(QRgb pixel) {
	return (0.439*qRed(pixel)) - (0.368*qGreen(pixel)) - (0.071*qBlue(pixel)) + 128;
}
