#ifndef BITRATE_H
#define BITRATE_H

#include <QPixmap>
#include <QImage>

class bitrate
{
public:
    bitrate();
    int getBitrate(QImage *image);
};

#endif // BITRATE_H
