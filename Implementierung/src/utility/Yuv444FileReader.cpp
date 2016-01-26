#include <exception>

#include "Yuv444FileReader.h"
#include "Video.h"
#include "Compression.h"
#include "Yuv444Vector.h"
#include "YuvFileReader.h"

Yuv444FileReader::Yuv444FileReader(QString filename, int width, int height, Compression compression) {
}

unique_ptr<GUI::Video> Yuv444FileReader::read() {
	throw "Not yet implemented";
}


unique_ptr<QImage> Yuv444FileReader::parseNextFrame() {
	throw "Not yet implemented";
}

Utility::Yuv444Vector Yuv444FileReader::readNextVectorPacked() {
	throw "Not yet implemented";
}

Utility::Yuv444Vector Yuv444FileReader::readNextVectorPlanar() {
	throw "Not yet implemented";
}

