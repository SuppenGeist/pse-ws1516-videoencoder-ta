#include "Yuv444FileReader.h"

#include <memory>

#include <QString>
#include <QImage>
#include <QColor>

#include "Compression.h"
#include "YuvFileReader.h"
#include "../model/Video.h"
#include "Yuv444Vector.h"

Utility::Yuv444FileReader::Yuv444FileReader(QString filename, int width, int height, int fps, Compression compression): YuvFileReader(filename, width, height,fps),compression_(compression) {

}

std::unique_ptr<Model::Video> Utility::Yuv444FileReader::read() {

    video = std::make_unique<Model::Video>(fps_,width_,height_);
    position_ = 0;
    while (position_ <= binaryData_.size()){
        video->appendFrame(parseNextFrame());
    }
    //return video;
}


std::unique_ptr<QImage> Utility::Yuv444FileReader::parseNextFrame() {
    std::unique_ptr<QImage> image(new QImage(width_, height_, QImage::Format_RGB888));
    QRgb rgb;
    for (int i = 0; i < width_; i++){
        rgb = Yuv444ToRgb888(readNextVectorPacked());
        for (int j = 0; j < height_; j++){
        image->setPixel(i,j,rgb);
        }
    }
    return image;
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPacked() {
    Yuv444Vector vector(binaryData_[position_],binaryData_[position_+1],binaryData_[position_+2]);
    position_ += 3;
    return vector;
}

QRgb Utility::Yuv444FileReader::Yuv444ToRgb888(Yuv444Vector vector) {
    uint8_t c = vector.getY() - 16;
    uint8_t d = vector.getU() - 128;
    uint8_t e = vector.getV() - 128;
    uint8_t r = clamp((298 * c + 409 * e + 128) >> 8);
    uint8_t g = clamp((298 * c - 100 * d - 208 * e + 128) >> 8);
    uint8_t b = clamp ((298 * c + 516 * d + 128) >> 8);
    return qRgb(r,g,b);
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPlanar() {

}


