#ifndef __Yuv422FileReader_h__
#define __Yuv422FileReader_h__

#include <QImage>

#include <memory>

#include "../model/Video.h"
#include "YuvFileReader.h"

namespace Utility
{
    enum class Compression;
    class Yuv422Vector;
}

namespace Utility
{
	/**
	 * This class can read yuv 422 files.
     */
    class Yuv422FileReader: public YuvFileReader
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
        public: Yuv422FileReader(QString filename, int width, int height, Compression compression);

    public: std::unique_ptr<Model::Video> read();

		/// <summary>
		/// Converts a Yuv422Vector the Rgb888 pixels
		/// </summary>
		/// <param name="vector">The vector to convert.</param>
		/// <returns>The computed rgb888 pixels.</returns>
    public: static std::vector<QRgb> yuv422ToRgb888(Yuv422Vector vector);

		/// <summary>
		/// Parses the next frame.
		/// </summary>
		/// <returns>The parsed frame.</returns>
    private: std::unique_ptr<QImage> parseNextFrame();

		/// <summary>
		/// Reads the next vector from a packed file.
		/// </summary>
		/// <returns>The new vector.</returns>
        private: Yuv422Vector readNextVectorPacked();

		/// <summary>
		/// Reads the next vector from a planar file.
		/// </summary>
		/// <returns>The new vector.</returns>
        private: Yuv422Vector readNextVectorPlanar();
	};
}

#endif
