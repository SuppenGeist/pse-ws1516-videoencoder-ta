#ifndef VIDEOSAVER_H
#define VIDEOSAVER_H
#include <memory>
#include <QString>
extern "C" {
#include <libavformat/avformat.h>
}

namespace Model {
class Video;
}

namespace Utility {
class VideoSaver
{
      public:
        /**
         * @brief saveVideo Saves a video in the given file.
         * @param video The video to save.
         * @param filename The path to save the video.
         */
        static void saveVideo(Model::Video* video, QString filename);


      private:
        VideoSaver();
    };

}

#endif // VIDEOSAVER_H
