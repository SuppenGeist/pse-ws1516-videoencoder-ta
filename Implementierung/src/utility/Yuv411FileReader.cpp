#include "Yuv411FileReader.h"

#include <memory>
#include <vector>

#include <QString>
#include <QImage>

#include "Compression.h"
#include "Yuv411Vector.h"
#include "YuvFileReader.h"
#include "../model/Video.h"

Utility::Yuv411FileReader::Yuv411FileReader(QString filename, int width, int height, Compression compression):YuvFileReader(filename,width,height) {
}

std::unique_ptr<Model::Video> Utility::Yuv411FileReader::read() {
	throw "Not yet implemented";
}


std::unique_ptr<QImage> Utility::Yuv411FileReader::parseNextFrame() {
	throw "Not yet implemented";
}

Utility::Yuv411Vector Utility::Yuv411FileReader::readNextVectorPacked() {
	throw "Not yet implemented";
}

Utility::Yuv411Vector Utility::Yuv411FileReader::readNextVectorPlanar() {
	throw "Not yet implemented";
}

std::vector<QRgb> Utility::Yuv411FileReader::yuv411ToRgb888(Yuv411Vector vector) {

}
