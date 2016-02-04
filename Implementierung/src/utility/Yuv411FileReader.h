#ifndef __Yuv411FileReader_h__
#define __Yuv411FileReader_h__

#include <vector>

#include <QColor>

#include "YuvFileReader.h"
#include "../model/Video.h"

namespace Utility {
enum class Compression;
class Yuv411Vector;
class Yuv411FileReader;
}

namespace Utility {
/**
 * This class is able to read Yuv 411 files.
 */
class Yuv411FileReader: public YuvFileReader {

  public:
	/**
	 * @brief Yuv411FileReader Constructor.
	 * @param filename Absolute path to the file to load.
	 * @param width Width of the video.
	 * @param height Height of the video.
	 * @param fps
	 * @param compression The compression of the file.
	 */
    Yuv411FileReader(QString filename, int width, int height, Utility::Compression compression);

	/**
	 * @brief yuv411ToRgb888 Converts a Yuv411Vector to the corresponding Rgb88 pixels.
	 * @param vector The vector to convert.
	 * @return The computed rgb888 pixels.
	 */
	static std::vector<QRgb> Yuv411ToRgb888(Yuv411Vector vector);

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
    Yuv411Vector readNextVectorPacked();

	/**
	 * @brief readNextVectorPlanar Reads the next vector from a planar file.
	 * @return The new vector.
	 */
    Yuv411Vector readNextVectorPlanar();
};
}

#endif
