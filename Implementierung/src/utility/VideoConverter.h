#ifndef __VideoConverter_h__
#define __VideoConverter_h__

#include <QImage>

#include <memory>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include "../model/Video.h"
#include "../model/AVVideo.h"


namespace Utility {
/**
 * Converts AVFrames to QImages and vice versa.
 */

class VideoConverter {
  public:
    /**
     * @brief convertAVFrameToQImage Converts the given AVFrame to a QImage.
     * @param frame The avframe to convert.
     * @param width The width of the frame.
     * @param height The height of the frame.
     * @return The converted AVFrame.
     */
    static std::unique_ptr<QImage> convertAVFrameToQImage(AVFrame& frame);

    /**
     * @brief convertAVVideoToVideo Converts a AVVideo to a Video
     * @param video The video to convert.
     * @return The converted AVVideo.
     */
    static std::unique_ptr<Model::Video> convertAVVideoToVideo(Model::AVVideo& video);

    /**
     * @brief convertQImageToAVFrame Converts a qimage to a avframe.
     * CAUTION: An owning pointer is returned.
     * @param image The qimage to convert.
     * @return The converted qimage.
     */
    static AVFrame* convertQImageToAVFrame(QImage& image);

    /**
     * @brief convertVideoToAVVideo Converts a Video to a AVVideo.
     * @param video The video to convert.
     * @return The converted video.
     */
    static std::unique_ptr<Model::AVVideo> convertVideoToAVVideo(Model::Video& video);

private:
    VideoConverter();
};
}

#endif

