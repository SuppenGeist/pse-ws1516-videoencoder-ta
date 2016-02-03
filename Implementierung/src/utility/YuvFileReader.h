#ifndef __YuvFileReader_h__
#define __YuvFileReader_h__

#include <QFile>
#include <QByteArray>

#include <memory>

#include "../model/Video.h"

namespace Utility
{

     // This is the base class for all different yuv file readers.
    class YuvFileReader
    {

        public:
        /**
         * @brief YuvFileReader Constructor.
         * @param filename The absolute path to the file to load.
         * @param width The width of the video.
         * @param height The height of the video.
         */
        YuvFileReader(QString filename, int width, int height,int fps);

        /**
         * @brief read Reads the file in.
         * @return The complete video.
         */
        virtual std::unique_ptr<Model::Video> read() = 0;

        /**
         * @brief clamp Clamps the given value to the range [0,255].
         * @param value <param name="value">The value to clamp.</param>
         * @return The clamped value.
         */
        static int clamp(int value);

    protected:
        QByteArray                      binaryData_;
        int                             width_;
        int                             height_;
        int                             fps_;
        std::unique_ptr<Model::Video>   video;
        QFile                           file_;
	};
}

#endif

