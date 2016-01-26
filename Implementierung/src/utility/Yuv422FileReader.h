
#include <exception>
#include <vector>
using namespace std;

#ifndef __Yuv422FileReader_h__
#define __Yuv422FileReader_h__

#include "Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileReader.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
	// enum Compression;
	class Yuv422Vector;
	// class YuvFileReader;
	class Yuv422FileReader;
}

namespace Utility
{
	/**
	 * This class can read yuv 422 files.
	 */
	class Yuv422FileReader: public Utility::YuvFileReader
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
		public: Yuv422FileReader(QString filename, int width, int height, Utility::Compression compression);

		public: unique_ptr<GUI::Video> read();

		/// <summary>
		/// Converts a Yuv422Vector the Rgb888 pixels
		/// </summary>
		/// <param name="vector">The vector to convert.</param>
		/// <returns>The computed rgb888 pixels.</returns>
		public: static vector<QRgb> yuv422ToRgb888(Utility::Yuv422Vector vector) {
			throw "Not yet implemented";
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
		private: Utility::Yuv422Vector readNextVectorPacked();

		/// <summary>
		/// Reads the next vector from a planar file.
		/// </summary>
		/// <returns>The new vector.</returns>
		private: Utility::Yuv422Vector readNextVectorPlanar();
	};
}

#endif
