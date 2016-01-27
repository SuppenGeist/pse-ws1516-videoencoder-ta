#ifndef __Video_h__
#define __Video_h__

#include <QImage>

#include <vector>

namespace Model
{
	/**
     * This class is a video.
	 * It provides a basic interface to comfortly handle a vector of frames.
     */
	class Video
    {
    public:
        /**
         * @brief Video Constructor.
         * @param fps The fps the video should be played at.
         * @param width The width of the video.
         * @param height The height of the video.
         */
        Video(int fps, int width, int height) noexcept;

        /**
         * @brief getWidth Returns the width of the video.
         * @return The width of the video.
         */
        int getWidth() const noexcept;

        /**
         * @brief getHeight Returns the height of the video.
         * @return The height of the video.
         */
        int getHeight() const noexcept;

        /**
         * @brief getFps Returns the fps of the video.
         * @return Fps of the video.
         */
        int getFps() const noexcept;

        /**
         * If the index is invalid nullptr is returned.
         *
         * @brief getFrame Returns the frame at the given index.
         * @param index The index of the frame to return.
         * @return The frame at the given index.
         */
        QImage* getFrame(std::size_t index) noexcept;

        /**
         * If the index is invalid nothing happens.
         * The image is copied into the video.
         *
         * @brief insertFrame Inserts a frame at the given index.
         * @param index The index to insert the frame at.
         * @param frame The frame to insert.
         */
        void insertFrame(const QImage& frame, std::size_t index);

        /**
         * If the index is invalid nothing happens.
         *
         * @brief removeFrame Removes the frame at the given index.
         * @param index The index of the frame to remove.
         */
        void removeFrame(std::size_t index);

        /**
         * If the index is invalid nothing happens.
         * The images are copied into the video.
         *
         * @brief insertFrames Inserts a vector of frames at the given index.
         * @param index The index to insert the frames at.
         * @param frames The frames to insert.
         */
        void insertFrames(const std::vector<QImage>& frames, std::size_t index);

        /**
         * The image is copied into the video.
         *
         * @brief appendFrame Adds the frame to the end of the video.
         * @param frame The frame to append.
         */
        void appendFrame(const QImage& frame);

        /**
         * @brief getNumberOfFrames Returns the number of frames in the video.
         * @return  The number of frames in the video.
         */
        std::size_t getNumberOfFrames() const noexcept;

    private:
        std::vector<QImage>     frames_;

        int                     fps_;
        int                     width_;
        int                     height_;
	};
}

#endif

