/*
#include <exception>
using namespace std;

#ifndef __Yuv444FileSaver_h__
#define __Yuv444FileSaver_h__

#include "Video.h"
#include "Compression.h"
#include "Yuv444Vector.h"
#include "YuvFileSaver.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
	// enum Compression;
	class Yuv444Vector;
	// class YuvFileSaver;
	class Yuv444FileSaver;
}

namespace Utility
{
	/**
	 * This class can save videos in the yuv 422 format.

	class Yuv444FileSaver: public Utility::YuvFileSaver
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to save to.</param>
		/// <param name="video">The video to save.</param>
		/// <param name="compression">The compression mode.</param>
		public: Yuv444FileSaver(QString filename, GUI::Video& video, Utility::Compression compression);

		public: void save();

		/// <summary>
		/// Saves the video in packed format.
		/// </summary>
		private: void savePacked();

		/// <summary>
		/// Saves the video in planar format.
		/// </summary>
		private: void savePlanar();

		/// <summary>
		/// Converts a Rgb888 pixel to a Yuv444Vector.
		/// </summary>
		/// <param name="pixel1">The pixel to convert.</param>
		/// <returns>The Yuv444Vector.</returns>
		public: static Utility::Yuv444Vector rgb888ToYuv444(QRgb pixel1) {
			throw "Not yet implemented";
		}
	};
}

#endif
*/
