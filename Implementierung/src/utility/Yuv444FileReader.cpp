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

}


std::unique_ptr<QImage> Utility::Yuv444FileReader::parseNextFrame() {
    /*throw "Not yet implemented";
    QImage image(width_, height_, QImage::Format_RGB888);
    QRgb rgb;
    for (int i = 0; i < width_; i++){
        rgb = yuv444ToRgb888(readNextVectorPacked());
        for (int j = 0; j < height_; j++){
        image.setPixel(i,j,rgb);

        }
    }*/
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPacked() {
    /*char *temp = new char[3];
    dataStream.readRawData(temp, 3);
    buffer.append(temp, 3);
    delete [] temp;
    Yuv444Vector vect(buffer[position],buffer[position+1],buffer[position+2]);
    position += 3;
    return vect;*/
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


