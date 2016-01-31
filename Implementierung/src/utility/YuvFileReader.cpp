
#include <exception>

#include "YuvFileReader.h"
#include "../model/Video.h"

Utility::YuvFileReader::YuvFileReader(QString filename, int width, int height): file(filename){
    this ->width= width;
    this ->height= height;
    file.open(QIODevice::ReadOnly);
    dataStream.setDevice(&file);
}




