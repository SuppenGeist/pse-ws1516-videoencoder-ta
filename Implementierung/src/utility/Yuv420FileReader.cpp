#include "Yuv420FileReader.h"

#include <memory>

#include <QString>
#include <QImage>

#include "Yuv444Vector.h"
#include "YuvFileReader.h"
#include "../model/Video.h"

Utility::Yuv420FileReader::Yuv420FileReader(QString filename, int width, int height, int fps):YuvFileReader(filename,width,height,fps) {

}

std::unique_ptr<Model::Video> Utility::Yuv420FileReader::read() {

}

std::unique_ptr<QImage> Utility::Yuv420FileReader::parseNextFrame() {

}

Utility::Yuv444Vector Utility::Yuv420FileReader::readNextVector() {

}
