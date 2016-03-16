#ifndef __Yuv411FileSaver_h__
#define __Yuv411FileSaver_h__

#include <thread>

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv411Vector.h"
#include "YuvFileSaver.h"
#include "../gui/FilterTab.h"

namespace Utility {
enum Compression;
class Yuv411Vector;
class YuvFileSaver;
class Yuv411FileSaver;
}

namespace Utility {

//This class can save videos in the yuv 411 format.

class Yuv411FileSaver: public YuvFileSaver {
  public:
	/**
	 * @brief Yuv411FileSaver Constructor.
	 * @param filename Absolute path to the file to save to.
	 * @param video The video to save.
	 * @param compression The compression mode.
	 */
	Yuv411FileSaver(QString filename, Model::Video& video, Utility::Compression compression);

	~Yuv411FileSaver();

	/**
	 * @brief save
	 */
	void save();

	/**
	 * @brief Rgb888ToYuv411 Converts Rgb888 pixels to a Yuv411Vector.
	 * @param pixel1 Pixel 1 to convert.
	 * @param pixel2 Pixel 2 to convert.
	 * @param pixel3 Pixel 3 to convert.
	 * @param pixel4 Pixel 4 to convert.
	 * @return The Yuv411Vector
	 */
	static Utility::Yuv411Vector Rgb888ToYuv411(QRgb pixel1, QRgb pixel2, QRgb pixel3, QRgb pixel4);

  private:
	Compression compression_;
	std::thread     safer_;
	bool        isRunning_;

	/**
	 * @brief savePacked Saves the video in packed format.
	 */
	void savePacked();

	/**
	 * @brief savePlanar Saves the video in planar format.
	 */
	void savePlanar();

	/**
	 * @brief saveP
	 */
	void saveP();
};
}

#endif

