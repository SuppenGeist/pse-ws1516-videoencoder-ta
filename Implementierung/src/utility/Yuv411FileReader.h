#ifndef __Yuv411FileReader_h__
#define __Yuv411FileReader_h__

#include <vector>

#include <QColor>

#include "YuvFileReader.h"
#include "../model/Video.h"

namespace Utility
{
    enum class Compression;
    class Yuv411Vector;
	class Yuv411FileReader;
}

namespace Utility
{
	/**
	 * This class is able to read Yuv 411 files.
     */
    class Yuv411FileReader: public YuvFileReader
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

    public: std::unique_ptr<Model::Video> read();

		/// <summary>
		/// Converts a Yuv411Vector to the corresponding Rgb88 pixels.
		/// </summary>
		/// <param name="vector">The vector to convert.</param>
		/// <returns>The computed rgb888 pixels.</returns>
        public: static std::vector<QRgb> yuv411ToRgb888(Yuv411Vector vector);

		/// <summary>
		/// Parses the next frame.
		/// </summary>
		/// <returns>The parsed frame.</returns>
    private: std::unique_ptr<QImage> parseNextFrame();

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
