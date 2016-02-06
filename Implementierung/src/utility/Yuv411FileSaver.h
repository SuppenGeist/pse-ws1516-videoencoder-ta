#ifndef __Yuv411FileSaver_h__
#define __Yuv411FileSaver_h__

#include <exception>
using namespace std;

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv411Vector.h"
#include "YuvFileSaver.h"

namespace GUI
{
	class Video;
}
namespace Utility
{
    enum Compression;
	class Yuv411Vector;
    class YuvFileSaver;
	class Yuv411FileSaver;
}

namespace Utility
{

    //This class can save videos in the yuv 411 format.

	class Yuv411FileSaver: public Utility::YuvFileSaver
	{
        public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filename">Absolute path to the file to save to.</param>
		/// <param name="video">The video to save.</param>
		/// <param name="compression">The compression mode.</param>
        Yuv411FileSaver(QString filename, Model::Video& video, Utility::Compression compression);

        void save();


		/// <summary>
		/// Converts Rgb888 pixels to a Yuv411Vector.
		/// </summary>
		/// <param name="pixel1">Pixel 1 to convert.</param>
		/// <param name="pixel2">Pixel 2 to convert.</param>
		/// <param name="pixel3">Pixel 3 to convert.</param>
		/// <param name="pixe4">Pixel 4 to convert.</param>
		/// <returns>The Yuv411Vector</returns>
        Utility::Yuv411Vector Rgb888ToYuv411(QRgb pixel1, QRgb pixel2, QRgb pixel3, QRgb pixel4);

        private:
        Compression compression_;


        /// <summary>
        /// Saves the video in packed format.
        /// </summary>
        void savePacked();

        /// <summary>
        /// Saves the video in planar format.
        /// </summary>
        void savePlanar();
	};
}

#endif

