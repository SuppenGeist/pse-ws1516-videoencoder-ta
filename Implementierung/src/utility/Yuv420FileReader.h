#ifndef __Yuv420FIleReader_h__
#define __Yuv420FIleReader_h__

#include <memory>

#include <QImage>

#include "../model/Video.h"
#include "Yuv444Vector.h"
#include "YuvFileReader.h"

namespace Utility
{
    class Yuv444Vector;
}

namespace Utility
{
	/**
	 * This class can read Yuv 420 files.
     */
    class Yuv420FileReader: public YuvFileReader
	{
		private: int position;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to load.</param>
		/// <param name="width">Width of the video.</param>
		/// <param name="height">Height of the video.</param>
        public: Yuv420FileReader(QString filename, int width, int height,int fps);

    public: std::unique_ptr<Model::Video> read();

		/// <summary>
		/// Parses the next frame.
		/// </summary>
		/// <returns>The parsed frame.</returns>
		private: std::unique_ptr<QImage> parseNextFrame();

		/// <summary>
		/// Reads the next Yuv 444 vector.
		/// </summary>
		/// <returns>The new vector.</returns>
		private: Utility::Yuv444Vector readNextVector();
	};
}

#endif
