#include "bitrate.h"
#include <QImage>
#include <QtMultimedia/QMediaMetaData>
#include <QtMultimedia/QMediaResource>


bitrate::bitrate()
{


}

int bitrate::getBitrate(QImage *image) {


    int bits = image->width() * image->height()  * image->bitPlaneCount();
    return bits;



}


