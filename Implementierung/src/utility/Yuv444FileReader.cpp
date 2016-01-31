
#include <exception>

#include "Yuv444FileReader.h"
#include "../model/Video.h"
#include "Compression.h"
#include "Yuv444Vector.h"
#include "YuvFileReader.h"

Utility::Yuv444FileReader::Yuv444FileReader(QString filename, int width, int height, Compression compression): YuvFileReader(filename, width, height) {
    this->compression = compression;
    //compression not needed since all 444 files are packed?!
}

unique_ptr<Model::Video> Utility::Yuv444FileReader::read() {
    throw "Not yet implemented";
}


unique_ptr<QImage> Utility::Yuv444FileReader::parseNextFrame() {
	throw "Not yet implemented";
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPacked() {
	throw "Not yet implemented";
}

//Utility::Yuv444Vector Yuv444FileReader::readNextVectorPlanar() {
//	throw "Not yet implemented";
//}


