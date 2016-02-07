#ifndef __Yuv444FileReader_h__
#define __Yuv444FileReader_h__

#include <memory>

#include <QImage>
#include <QString>
#include <QColor>

#include "YuvFileReader.h"
#include "../model/Video.h"

namespace Model {
class Video;
}
namespace Utility {
enum class Compression;
class Yuv444Vector;
}

namespace Utility {

/// This class can read Yuv 444 files.

class Yuv444FileReader: public YuvFileReader {


  public:
	/**
	 * @brief Yuv444FileReader Constructor.
	 * @param filename Absolute path to the file to load.
	 * @param width Width of the video.
	 * @param height Height of the video.
	 * @param compression Compression of the file.
	 */
	Yuv444FileReader(QString filename, int width, int height, Compression compression);


	/**
	 * @brief yuv444ToRgb888 Converts a Yuv444Vector to a Rgb888 pixel.
	 * @param vector The vector to convert.
	 * @return The computed pixel.
	 */
	static QRgb Yuv444ToRgb888(Yuv444Vector &vector);

  protected:
	/**
	 * @brief parseNextFrame Parses the next frame.
	 * @return The parsed frame.
	 */
	std::unique_ptr<QImage> parseNextFrame();

  private:
	int         position_;
	Compression compression_;



	/**
	 * @brief readNextVectorPacked Reads the next vector from a packed file.
	 * @return The new vector.
	 */
	Yuv444Vector readNextVectorPacked();

	/**
	 * @brief readNextVectorPlanar Reads the next vector from a planar file.
	 * @return The new vector.
	 */
	Yuv444Vector readNextVectorPlanar();
};
}

#endif

