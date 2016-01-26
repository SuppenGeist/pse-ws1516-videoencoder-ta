#include <exception>
#include <vector>

#include "Yuv411FileReader.h"
#include "Video.h"
#include "Compression.h"
#include "Yuv411Vector.h"
#include "YuvFileReader.h"

Yuv411FileReader::Yuv411FileReader(QString filename, int width, int height, Compression compression) {
}

unique_ptr<GUI::Video> Yuv411FileReader::read() {
	throw "Not yet implemented";
}


unique_ptr<QImage> Yuv411FileReader::parseNextFrame() {
	throw "Not yet implemented";
}

Utility::Yuv411Vector Yuv411FileReader::readNextVectorPacked() {
	throw "Not yet implemented";
}

Utility::Yuv411Vector Yuv411FileReader::readNextVectorPlanar() {
	throw "Not yet implemented";
}

