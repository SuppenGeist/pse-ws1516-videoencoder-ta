#ifndef __Yuv420FIleReader_h__
#define __Yuv420FIleReader_h__

#include <memory>

#include <QImage>

#include "../model/Video.h"
#include "YuvFileReader.h"

namespace Utility {
class Yuv444Vector;
}

namespace Utility {
/**
 * This class can read Yuv 420 files.
 */
class Yuv420FileReader: public YuvFileReader {
  public:
	/**
	 * @brief Yuv420FileReader Constructor.
	 * @param filename Absolute path to the file to load.
	 * @param width Width of the video.
	 * @param height Height of the video.
	 * @param fps
	 */
	Yuv420FileReader(QString filename, int width, int height,int fps);

	/**
	* @brief read Reads the file in.
	* @return
	*/
	std::unique_ptr<Model::Video> read();

  private:

	int position_;
	/**
	 * @brief parseNextFrame Parses the next frame.
	 * @return The parsed frame.
	 */
	std::unique_ptr<QImage> parseNextFrame();

	/**
	 * @brief readNextVector Reads the next Yuv 444 vector.
	 * @param success
	 * @return The new vector.
	 */
	Yuv444Vector readNextVector(bool& success);
};
}

#endif
