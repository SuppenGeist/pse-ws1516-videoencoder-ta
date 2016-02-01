
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
    //need fps to create video

}


unique_ptr<QImage> Utility::Yuv444FileReader::parseNextFrame() {
	throw "Not yet implemented";
    QImage image = QImage(width, height, QImage::Format_RGB888);
    QRgb rgb;
    for (int i = 0; i < width; i++){
        rgb = yuv444ToRgb888(readNextVectorPacked());
        for (int j = 0; j < height; j++){
        image.setPixel(i,j,rgb);

        }
    }
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPacked() {
    char *temp = new char[3];
    dataStream.readRawData(temp, 3);
    buffer.append(temp, 3);
    delete [] temp;
    Yuv444Vector vect = Yuv444Vector(buffer[position],buffer[position+1],buffer[position+2]);
    position += 3;
    return vect;
}

//Utility::Yuv444Vector Yuv444FileReader::readNextVectorPlanar() {
//	throw "Not yet implemented";
//}


