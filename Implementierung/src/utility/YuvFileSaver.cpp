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

int Utility::YuvFileSaver::RgbToY(QRgb pixel){
   return 0.299*qRed(pixel)+ 0.587*qGreen(pixel) + 0.1144*qBlue(pixel);
}

int Utility::YuvFileSaver::RgbToU(QRgb pixel){
   return (-0.147)*qRed(pixel)-0.289*qGreen(pixel)+0.436*qBlue(pixel);
}

int Utility::YuvFileSaver::RgbToV(QRgb pixel){
    return 0.615*qRed(pixel)-0.515*qGreen(pixel)-0.100*qBlue(pixel);
}
