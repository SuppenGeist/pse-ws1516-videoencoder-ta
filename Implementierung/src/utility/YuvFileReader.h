/*
#include <exception>
#include <QFile>
#include <QDataStream>
#include <memory>
using namespace std;

#ifndef __YuvFileReader_h__
#define __YuvFileReader_h__

#include "Video.h"

namespace Model
{
	class Video;
}
namespace Utility
{
	class YuvFileReader;
}

namespace Utility
{

     // This is the base class for all different yuv file readers.

    class YuvFileReader
	{
    protected: unique_ptr<QByteArray> binaryData;
    protected: int width;
    protected: int height;
    protected: unique_ptr<GUI::Video> video;
    protected: QFile file;
    protected: QDataStream dataStream;
    protected: QByteArray buffer;


		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">The absolute path to the file to load.</param>
		/// <param name="width">The width of the video.</param>
		/// <param name="height">The height of the video.</param>
		public: YuvFileReader(QString filename, int width, int height);

		/// <summary>
		/// Reads the file in.
		/// </summary>
		/// <returns>The complete video.</returns>
		public: virtual unique_ptr<GUI::Video> read() = 0;

		/// <summary>
		/// Clamps the given value to the range [0,255].
		/// </summary>
		/// <param name="value">The value to clamp.</param>
		/// <returns>The clamped value.</returns>
		public: static int clamp(int value) {
            return value < 0 ? 0 : value > 255 ? 255 : value;
		}
	};
}

#endif
*/
