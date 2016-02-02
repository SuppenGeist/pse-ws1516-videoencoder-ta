#ifndef __AVVideo_h__
#define __AVVideo_h__

#include <vector>
#include <memory>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

namespace Model {
/**
 * This class contains AVFrames from the ffmpeg library and manages them.
 */
class AVVideo {

  public:
    /**
     * @brief AVVideo Constructor.
     * @param fps The fps the video should be played at.
     * @param width The width of the video.
     * @param height The height of the video.
     */
	AVVideo(int fps, int width, int height);

    /**
     * @brief getWidth Returns the width of the video.
     * @return The width of the video.
     */
    int getWidth();

    /**
     * @brief getHeight Returns the height of the video.
     * @return The height of the video.
     */
    int getHeight();

    /**
     * @brief getFps Returns the fps of the video.
     * @return Fps of the video.
     */
    int getFps();

    /**
     * @brief getFrame Returns the frame at the given index.
     * If the index is invalid nullptr is returned.
     * @param index the index of the frame to return
     * @return The frame at the given index.
     */
    AVFrame* getFrame(std::size_t index);

    /**
     * @brief insertFrame Inserts a frame at the given index.
     * If the width and height of the frame dont match the size of the video false is returned.
     * @param frame The frame to insert.
     * @param index The index to insert the frame at.
     */
    bool insertFrame(std::unique_ptr<AVFrame> frame, std::size_t index);

    /**
     * @brief removeFrame Removes the frame at the given index.
     * @param index The index of the frame to remove.
     */
    void removeFrame(std::size_t index);

    /**
     * @brief insertFrames Inserts a vector of frames at the given index.
     * If the width and height of one frame dont match the size of the video false is returned.
     * All frames that match the size of the video are inserted either way.
     * @param frames The frames to insert.
     * @param index The index to insert the frames at.
     */
    bool insertFrames(std::vector<std::unique_ptr<AVFrame> >& frames, std::size_t index);

    /**
     * @brief getNumberOfFrames Returns the number of frames in the video.
     * @return The number of frames in the video.
     */
    int getNumberOfFrames();

private:
  std::vector<std::unique_ptr<AVFrame>> video_;
  int fps_;
  int width_;
  int height_;
};
}

#endif

