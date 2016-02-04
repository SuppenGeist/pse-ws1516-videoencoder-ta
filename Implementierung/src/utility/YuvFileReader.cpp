#include "YuvFileReader.h"

#include <QFile>

#include "../model/Video.h"

Utility::YuvFileReader::YuvFileReader(QString filename, int width, int height): file_(filename),width_(width),height_(height) {
	file_.open(QIODevice::ReadOnly);
	binaryData_=file_.readAll();
}

int Utility::YuvFileReader::clamp(int value) {
	if(value<0)
		return 0;
	if(value>255)
		return 255;
	return value;
}
