#include "Yuv422FileReader.h"

#include <memory>

#include <QImage>
#include <QColor>

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileReader.h"

Utility::Yuv422FileReader::Yuv422FileReader(QString filename, int width, int height, Compression compression):YuvFileReader(filename,width,height) {
}

std::unique_ptr<Model::Video> Utility::Yuv422FileReader::read() {
	throw "Not yet implemented";
}


std::unique_ptr<QImage> Utility::Yuv422FileReader::parseNextFrame() {
	throw "Not yet implemented";
}

Utility::Yuv422Vector Utility::Yuv422FileReader::readNextVectorPacked() {
	throw "Not yet implemented";
}

std::vector<QRgb> Utility::Yuv422FileReader::yuv422ToRgb888(Yuv422Vector vector) {

}

Utility::Yuv422Vector Utility::Yuv422FileReader::readNextVectorPlanar()
{

}
