#ifndef __Yuv422FileReader_h__
#define __Yuv422FileReader_h__

#include <QImage>

#include <memory>
#include <vector>

#include "../model/Video.h"
#include "YuvFileReader.h"

namespace Utility {
enum class Compression;
class Yuv422Vector;
}

namespace Utility {
/**
 * This class can read yuv 422 files.
 */
class Yuv422FileReader: public YuvFileReader {
  public:
	/**
	 * @brief Yuv422FileReader Constructor.
	 * @param filename Absolute path to the file to load.
	 * @param width Width of the video.
	 * @param height Height of the video.
	 * @param fps
	 * @param compression Compression of the file.
	 */
    Yuv422FileReader(QString filename, int width, int height, Compression compression);

	/**
	 * @brief read Reads the file in.
	 * @return
	 */
    void read(Model::Video* target) override;

	/**
	 * @brief yuv422ToRgb888 Converts a Yuv422Vector the Rgb888 pixels
	 * @param vector The vector to convert.
	 * @return The computed rgb888 pixels.
	 */
	static std::vector<QRgb> Yuv422ToRgb888(Yuv422Vector vector);


  private:
	int             position_;
	Compression     compression_;

	/**
	 * @brief parseNextFrame Parses the next frame.
	 * @return The parsed frame.
	 */
	std::unique_ptr<QImage> parseNextFrame();

	/**
	 * @brief readNextVectorPacked Reads the next vector from a packed file.
	 * @return The new vector.
	 */
	Yuv422Vector readNextVectorPacked(bool& success);

	/**
	 * @brief readNextVectorPlanar Reads the next vector from a planar file.
	 * @return The new vector.
	 */
	Yuv422Vector readNextVectorPlanar(bool& success);
};
}

#endif
