#include <exception>
#include <vector>

#include "Yuv422FileReader.h"
#include "Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileReader.h"

Yuv422FileReader::Yuv422FileReader(QString filename, int width, int height, Compression compression) {
}

unique_ptr<GUI::Video> Yuv422FileReader::read() {
	throw "Not yet implemented";
}


unique_ptr<QImage> Yuv422FileReader::parseNextFrame() {
	throw "Not yet implemented";
}

Utility::Yuv422Vector Yuv422FileReader::readNextVectorPacked() {
	throw "Not yet implemented";
}

Utility::Yuv422Vector Yuv422FileReader::readNextVectorPlanar() {
	throw "Not yet implemented";
}

