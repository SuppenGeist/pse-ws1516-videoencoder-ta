#ifndef VIDEOSAVER_H
#define VIDEOSAVER_H
#include <memory>
#include <QString>
extern "C" {
#include <libavformat/avformat.h>
}
#include "../model/AVVideo.h"

namespace Model {
class Graph;
class Video;
}

namespace Utility {
class VideoSaver
{
      public:
        static void saveVideo(Model::Video* video, QString filename);


      private:
        VideoSaver();
    };

}

#endif // VIDEOSAVER_H
