/*
#include <exception>
using namespace std;

#ifndef __Yuv422FileSaver_h__
#define __Yuv422FileSaver_h__

#include "Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileSaver.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
	// enum Compression;
	class Yuv422Vector;
	// class YuvFileSaver;
	class Yuv422FileSaver;
}

namespace Utility
{
	/**
	 * This class can save a video in the yuv 422 format.

	class Yuv422FileSaver: public Utility::YuvFileSaver
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to save to.</param>
		/// <param name="video">The video to save.</param>
		/// <param name="compression">The compression mode.</param>
		public: Yuv422FileSaver(QString filename, GUI::Video& video, Utility::Compression compression);

		public: void save();

		/// <summary>
		/// Saves the video packed.
		/// </summary>
		private: void savePacked();

		/// <summary>
		/// Saves the video planar.
		/// </summary>
		private: void savePlanar();

		/// <summary>
		/// Converts Rgb888 pixel to a Yuv422Vector.
		/// </summary>
		/// <param name="pixel1">Pixel 1 to convert.</param>
		/// <param name="pixel2">Pixel 2 to convert.</param>
		/// <returns>The Yuv422Vector.</returns>
		public: static Utility::Yuv422Vector rgb888ToYuv422(QRgb pixel1, QRgb pixel2) {
			throw "Not yet implemented";
		}
	};
}

#endif
*/
