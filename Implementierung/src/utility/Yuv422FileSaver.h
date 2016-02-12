#ifndef __Yuv422FileSaver_h__
#define __Yuv422FileSaver_h__

#include <QString>
#include <QColor>

#include <thread>

#include "YuvFileSaver.h"

namespace Utility {
enum class Compression;
class Yuv422Vector;
}
namespace Model {
class Video;
}

namespace Utility {
/**
 * This class can save a video in the yuv 422 format.
 */
class Yuv422FileSaver: public YuvFileSaver {
  public:
	/**
	 * @brief rgb888ToYuv422 Converts Rgb888 pixel to a Yuv422Vector.
	 * @param pixel1 Pixel 1 to convert.
	 * @param pixel2 Pixel 2 to convert.
	 * @return The Yuv422Vector.
	 */
	static Yuv422Vector Rgb888ToYuv422(QRgb pixel1, QRgb pixel2);

	/**
	 * @brief Yuv422FileSaver Constructor.
	 * @param filename Absolute path to the file to save to.
	 * @param video The video to save.
	 * @param compression The compression mode.
	 */
	Yuv422FileSaver(QString filename, Model::Video& video, Utility::Compression compression);

	/**
	 * @brief save Saves the video.
	 */
	void save();


  private:
	Compression     compression_;
    std::thread     safer_;


	/**
	 * @brief savePacked Saves the video packed.
	 */
	void savePacked();

	/**
	 * @brief savePlanar Saves the video planar.
	 */
	void savePlanar();

    void saveP();

};
}

#endif
