#ifndef __Yuv444FileSaver_h__
#define __Yuv444FileSaver_h__

#include <thread>

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv444Vector.h"
#include "YuvFileSaver.h"
#include "../gui/FilterTab.h"

namespace Model {
class Video;
}
namespace Utility {
enum Compression;
class Yuv444Vector;
class YuvFileSaver;
class Yuv444FileSaver;
}

namespace Utility {

//This class can save videos in the yuv 422 format.

class Yuv444FileSaver: public Utility::YuvFileSaver {
  public:
	/**
	 * @brief Yuv444FileSaver Constructor.
	 * @param filename Absolute path to the file to save to.
	 * @param video The video to save.
	 * @param compression The compression mode.
	 */
    Yuv444FileSaver(QString filename, Model::Video& video, Utility::Compression compression);

	~Yuv444FileSaver();

	/**
	 * @brief Rgb888ToYuv444 Converts a Rgb888 pixel to a Yuv444Vector.
	 * @param pixel1 The pixel to convert.
	 * @return The Yuv444Vector.
	 */
	static Utility::Yuv444Vector Rgb888ToYuv444(QRgb pixel1);

	void save();


  private:
	Compression compression_;
    std::thread safer_;
	bool    isRunning_;

	/**
	 * @brief savePacked Saves the video in packed format.
	 */
	void savePacked();

	/**
	 * @brief savePlanar Saves the video in planar format.
	 */
	void savePlanar();

	void saveP();
};
}

#endif

