
#include <exception>
#include <vector>
using namespace std;

#ifndef __Yuv411FileReader_h__
#define __Yuv411FileReader_h__

#include "Video.h"
#include "Compression.h"
#include "Yuv411Vector.h"
#include "YuvFileReader.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
	// enum Compression;
	class Yuv411Vector;
	// class YuvFileReader;
	class Yuv411FileReader;
}

namespace Utility
{
	/**
	 * This class is able to read Yuv 411 files.
	 */
	class Yuv411FileReader: public Utility::YuvFileReader
	{
		private: int position;
		private: Utility::Compression compression;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to load.</param>
		/// <param name="width">Width of the video.</param>
		/// <param name="height">Height of the video.</param>
		/// <param name="compression">The compression of the file.</param>
		public: Yuv411FileReader(QString filename, int width, int height, Utility::Compression compression);

		public: unique_ptr<GUI::Video> read();

		/// <summary>
		/// Converts a Yuv411Vector to the corresponding Rgb88 pixels.
		/// </summary>
		/// <param name="vector">The vector to convert.</param>
		/// <returns>The computed rgb888 pixels.</returns>
		public: static std::vector<QRgb> yuv411ToRgb888(Yuv11Vector vector) {
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
		private: Utility::Yuv411Vector readNextVectorPacked();

		/// <summary>
		/// Reads the next vector from a planar file.
		/// </summary>
		/// <returns>The new vector.</returns>
		private: Utility::Yuv411Vector readNextVectorPlanar();
	};
}

#endif
