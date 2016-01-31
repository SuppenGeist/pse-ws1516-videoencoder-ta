/*
#include <exception>
using namespace std;

#ifndef __Yuv444FileReader_h__
#define __Yuv444FileReader_h__

#include "Video.h"
#include "Compression.h"
#include "Yuv444Vector.h"
#include "YuvFileReader.h"
#include <QColor>

namespace Model
{
	class Video;
}
namespace Utility
{
	// enum Compression;
	class Yuv444Vector;
	// class YuvFileReader;
	class Yuv444FileReader;
}

namespace Utility
{

     /// This class can read Yuv 444 files.

	class Yuv444FileReader: public Utility::YuvFileReader
	{
		private: int position;
		private: Utility::Compression compression;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to load.</param>
		/// <param name="width">Width of the video.</param>
		/// <param name="height">Height of the video.</param>
		/// <param name="compression">Compression of the file.</param>
		public: Yuv444FileReader(QString filename, int width, int height, Utility::Compression compression);

		public: unique_ptr<GUI::Video> read();

		/// <summary>
		/// Converts a Yuv444Vector to a Rgb888 pixel.
		/// </summary>
		/// <param name="vector">The vector to convert.</param>
		/// <returns>The computed pixel.</returns>
		public: static QRgb yuv444ToRgb888(Utility::Yuv444Vector vector) {
            uint8_t c = vector.y - 16;
            uint8_t d = vector.u - 128;
            uint8_t e = vector.v - 128;
            uint8_t r = clamp((298 * c + 409 * e + 128) >> 8);
            uint8_t g = clamp((298 * c - 100 * d - 208 * e + 128) >> 8);
            uint8_t b = clamp ((298 * c + 516 * d + 128) >> 8);
            QRgb qRgb(r,g,b);
            return qRgb;
		}

		/// <summary>
		/// Parses the next frame.
		/// </summary>
		/// <returns>The parsed frame.</returns>
		private: unique_ptr<QImage> parseNextFrame();

		/// <summary>
		/// Reads the next vector from a packed file.
		/// </summary>
		/// <returns>The new vector.</returns>
		private: Utility::Yuv444Vector readNextVectorPacked();

		/// <summary>
		/// Reads the next vector from a planar file.
		/// </summary>
		/// <returns>The new vector.</returns>
		private: Utility::Yuv444Vector readNextVectorPlanar();
	};
}

#endif
*/
